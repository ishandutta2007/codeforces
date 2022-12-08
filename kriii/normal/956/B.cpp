#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int N, U,A[100100];

int main()
{
	scanf("%d %d", &N, &U);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	double ans = -1;
	for (int i = 0, k = 2; i < N; i++) {
		while (k < N && A[k] - A[i] <= U) k++; k--;
		if (i + 1 < k) {
			double now = (0. + A[k] - A[i + 1]) / (A[k] - A[i]);
			if (ans < now)
				ans = now;
		}
	}
	if (ans < 0) puts("-1");
	else printf("%.12lf\n", ans);
	return 0;
}