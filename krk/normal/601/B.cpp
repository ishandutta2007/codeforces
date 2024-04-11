#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Inf = 1000000000;

int n, q;
int a[Maxn];
int B[Maxn];
int L[Maxn], R[Maxn];
ll res;

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
		B[i] = abs(a[i] - a[i + 1]);
	B[0] = B[n] = Inf;
	for (int i = 1; i < n; i++) {
		int cand = i - 1;
		while (B[cand] < B[i]) cand = L[cand];
		L[i] = cand;
	}
	for (int i = n - 1; i >= 1; i--) {
		int cand = i + 1;
		while (B[cand] <= B[i]) cand = R[cand];
		R[i] = cand;
	}
	while (q--) {
		res = 0;
		int l, r; scanf("%d %d", &l, &r);
		for (int i = l; i < r; i++)
			res += ll(i - max(l - 1, L[i])) * ll(min(r, R[i]) - i) * ll(B[i]);
		printf("%I64d\n", res);
	}
	return 0;
}