#include <stdio.h>
#include <algorithm>
using namespace std;

int N; long long A[200200];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N * 2; i++) scanf("%lld", &A[i]);
	sort(A, A + N * 2);

	long long ans = (A[N-1] - A[0]) * (A[N*2-1] - A[N]);
	for (int i = 1; i < N; i++) {
		long long hi = (A[i + N - 1] - A[i]) * (A[2 * N - 1] - A[0]);
		if (ans > hi)
			ans = hi;
	}
	printf("%lld\n", ans);

	return 0;
}