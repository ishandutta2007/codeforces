#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 20;
const int mod = 1000000007;

int n;
vector <ii> neigh[Maxn];
int L[Maxn], P[Maxn][Maxm];
ll W[Maxn];
int cur, lef[Maxn], rig[Maxn];
int sqsum[Maxn], sum[Maxn], cnt[Maxn];
int tsqsum[Maxn], tsum[Maxn], tcnt[Maxn];
int q;

void Traverse(int v)
{
	lef[v] = ++cur;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.first == P[v][0]) continue;
		L[u.first] = L[v] + 1;
		P[u.first][0] = v;
		W[u.first] = W[v] + u.second;
		Traverse(u.first);
	}
	rig[v] = cur;
}

void Solve1(int v)
{
	cnt[v] = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.first == P[v][0]) continue;
		Solve1(u.first);
		sqsum[v] = (sqsum[v] + ll(sqsum[u.first]) + 2ll * ll(u.second) % mod * sum[u.first] + ll(u.second) * u.second % mod * cnt[u.first]) % mod;
		sum[v] = (sum[v] + ll(sum[u.first]) + ll(u.second) * cnt[u.first]) % mod;
		cnt[v] = (cnt[v] + cnt[u.first]) % mod;
	}
}

void Solve2(int v)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.first == P[v][0]) continue;
		int rsqsum = (ll(sqsum[u.first]) + 2ll * ll(u.second) % mod * sum[u.first] + ll(u.second) * u.second % mod * cnt[u.first]) % mod;
		int rsum = (ll(sum[u.first]) + ll(u.second) * cnt[u.first]) % mod;
		int rcnt = cnt[u.first];
		int allsqsum = (ll(tsqsum[v]) + ll(sqsum[v]) - ll(rsqsum) + ll(mod)) % mod;
		int allsum = (ll(tsum[v]) + ll(sum[v]) - ll(rsum) + ll(mod)) % mod;
		int allcnt = (ll(tcnt[v]) + ll(cnt[v]) - ll(rcnt) + ll(mod)) % mod;
		tsqsum[u.first] = (ll(allsqsum) + 2ll * ll(u.second) % mod * allsum + ll(u.second) * u.second % mod * allcnt) % mod;
		tsum[u.first] = (ll(allsum) + ll(u.second) * allcnt) % mod;
		tcnt[u.first] = allcnt;
		Solve2(u.first); 
	}
}

int getLCA(int a, int b)
{
	if (L[a] < L[b]) swap(a, b);
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b])
			a = P[a][i];
	if (a == b) return a;
	for (int i = Maxm - 1; i >= 0; i--)
		if (P[a][i] != P[b][i])
			a = P[a][i], b = P[b][i];
	return P[a][0];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		neigh[a].push_back(ii(b, c));
		neigh[b].push_back(ii(a, c));
	}
	Traverse(1);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	Solve1(1);
	Solve2(1);
	scanf("%d", &q);
	while (q--) {
		int u, v; scanf("%d %d", &u, &v);
		int lca = getLCA(u, v);
		ll len = (W[u] + W[v] - 2 * W[lca]) % mod;
		if (lef[v] <= lef[u] && lef[u] <= rig[v]) {
			int res = (sqsum[u] + tsqsum[u]) % mod;
			int rem = 2ll * (ll(tsqsum[v]) + 2ll * ll(len) % mod * tsum[v] + ll(len) * len % mod * tcnt[v]) % mod;
			res = (res - rem + mod) % mod;
			printf("%d\n", res);
		} else {
			int rem = (sqsum[u] + tsqsum[u]) % mod;
			int res = 2ll * (ll(sqsum[v]) + 2ll * ll(len) % mod * sum[v] + ll(len) * len % mod * cnt[v]) % mod;
			res = (res - rem + mod) % mod;
			printf("%d\n", res);
		}
	}
    return 0;
}