module main;

import std.c.stdio;

int main(string[] argv)
{
	int n;
	scanf("%d", &n);
	int [] arr = new int[n];
	for(int i = 0; i<n; i++)
		scanf("%d", &arr[i]);

	int[] r1 = new int[n];
	for (int i = 0; i < n * 7; i++) {
		if (i % 7 != 6) r1[i % n]++;
		if (r1[i % n] == arr[i % n]) {
			printf("%d\n", (i % n) + 1);
			return 0;
		}
	}
	int moves = 1000000000;
	for (int i = 0; i < n; i++) {
		if (r1[i] != 0) {
			if ((arr[i] - 1) / r1[i] < moves) {
				moves = (arr[i] - 1) / r1[i];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		r1[i] *= moves;
	}

	for (int i = 0; i < n * 7; i++) {
		if (i % 7 != 6) r1[i % n]++;
		if (r1[i % n] == arr[i % n]) {
			printf("%d\n", (i % n) + 1);
			return 0;
		}
	}
	return 0;
}