#include <stdio.h>
#include <algorithm>
using namespace std;

int N, A[100100], W[100100];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x; scanf("%d", &x);
		A[i] = x;
	}
	sort(A, A + N);
	int c = 0, w = 1;
	for (int i = N-1; i >=0; i--) {
		if (!W[i + 1]) W[i] = 1;
		else if (!w) W[i] = 1;
		else W[i] = 0;
		if (i == 0 || A[i - 1] != A[i]) {
			if (!W[i+1]) w = 0;
		}
	}

	puts(!W[0] ? "Agasa" : "Conan");
	return 0;
}