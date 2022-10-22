#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int A[Maxn];
int m;
int B[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int mx1 = 0, mx2 = 0;
		int st1 = 0, st2 = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &A[i]);
			st1 += A[i];
			mx1 = max(mx1, st1);
		}
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &B[j]);
			st2 += B[j];
			mx2 = max(mx2, st2);
		}
		printf("%d\n", mx1 + mx2);
	}
    return 0;
}