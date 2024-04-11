#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 15005;
const int Maxk = 1005;
const int Maxq = 100005;
const int ar = 10000019;
const int mod = 1000000007;

int n, k;
int V[Maxn], W[Maxn];
int Q;
int inquer[Maxn];
int oth[Maxq], ind[Maxq];
ll dp[Maxn][Maxk];
int len;

void Add(int V, int W)
{
	for (int i = 1; i <= k; i++) {
		dp[len][i] = dp[len - 1][i];
		if (i >= W) dp[len][i] = max(dp[len][i], dp[len - 1][i - W] + V);
	}
	len++;
}

void Solve(int lef, int rig)
{
	if (lef == rig) {
		if (oth[lef] == lef) {
			int ans = 0;
			for (int i = k; i > 0; i--)
				ans = (ll(ans) * ar + dp[len - 1][i]) % mod;
			printf("%d\n", ans);
		}
	} else {
		int mid = lef + rig >> 1;
		int lim = len;
		for (int i = mid + 1; i <= rig; i++)
			if (oth[i] < lef) Add(V[ind[i]], W[ind[i]]);
		Solve(lef, mid);
		len = lim;
		for (int i = lef; i <= mid; i++)
			if (oth[i] > rig) Add(V[ind[i]], W[ind[i]]);
		Solve(mid + 1, rig);
		len = lim;
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &V[i], &W[i]);
		inquer[i] = Q++;
	}
	int q; scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int typ; scanf("%d", &typ);
		if (typ == 1) {
			scanf("%d %d", &V[n], &W[n]);
			inquer[n] = Q;
			n++;
		} else if (typ == 2) {
			int x; scanf("%d", &x); x--;
			oth[inquer[x]] = Q;
			oth[Q] = inquer[x];
			ind[inquer[x]] = ind[Q] = x;
			inquer[x] = -1;
		} else oth[Q] = Q;
		Q++;
	}
	for (int i = 0; i < n; i++)
		if (inquer[i] != -1) {
			oth[inquer[i]] = Q;
			oth[Q] = inquer[i];
			ind[inquer[i]] = ind[Q] = i;
			Q++;
		}
	len = 1;
	Solve(0, Q - 1);
    return 0;
}