#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 1000000

void quick_sort(int* list[],int left,int right);	// quick_sort function
int swap(int *i, int *j);							// swap function
void print(int* list[]);							// print function
int list[MAX_SIZE];

int swap(int *i, int *j) {
	int *tmp = 0;
	tmp = *i;
	*i = *j;
	*j = tmp;
	return i, j;
}

void quick_sort(int* list[], int left, int right)
{
	if (left >= right) return;
	int mid = (left + right) / 2;
	int i = left, j = right;
	int pivot = list[mid];
	int k = 0;

	while (left <= right) {
		while (list[left] < pivot) left++;
		while (list[right] > pivot) right--;
		if (left <= right) {
			swap(&list[left], &list[right]);
			left++; right--;
		}
	}
	quick_sort(list, i, right);
	quick_sort(list, left, j);
}
void print(int* list[]) {
	int i = 0;
	for (i = 0;i < MAX_SIZE;i++) {
		if (i % 10 == 0) printf("\n");
		printf("%3d ", list[i]);
	}
	printf("\n");
}

void input_data(int* list[]) {
	int i = 0;
	for (int i = 0;i < MAX_SIZE;i++) {
		list[i] = (rand() % MAX_SIZE) + 1;	// input random data
	}
}
int main() {
	clock_t start, end;
	float total_time;
	start = clock();
	input_data(list);
	//print(list);
	quick_sort(list, 0, sizeof(list) / sizeof(int) - 1);
	printf("--------------------------------------------------------------------------------\n");
	//print(list);
	end = clock();
	total_time = (float)(end - start) / CLOCKS_PER_SEC;

	printf("Execute_time : %.6f\n", total_time);
	return 0;
}

