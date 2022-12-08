#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int N,C[100100],X[100100];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &C[i]);
		X[i] = C[i] + 1;
		if (i && X[i] < X[i - 1]) X[i] = X[i - 1];
	}

	for (int i = N - 2; i >= 0; i--) {
		if (X[i] < X[i + 1] - 1)
			X[i] = X[i + 1] - 1;
	}

	long long ans = 0;
	for (int i = 0; i < N; i++) {
		ans += X[i] - 1 - C[i];
	}
	printf("%lld\n", ans);

	return 0;
}