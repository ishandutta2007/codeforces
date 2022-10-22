#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

ll sum;
int n;
int A[Maxn];
int m;
int B[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
		sum += A[i];
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &B[i]);
		sum -= B[i];
	}
	if (sum != 0) { printf("-1\n"); return 0; }
	int i = 0, j = 0;
	while (i < n || j < m) {
		if (sum < 0) sum += A[i++];
		else if (sum > 0) sum -= B[j++];
		else sum += A[i++] - B[j++];
		if (sum == 0) res++;
	}
	printf("%d\n", res);
    return 0;
}