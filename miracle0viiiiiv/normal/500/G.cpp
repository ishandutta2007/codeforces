//this is brute force
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL INF = 0x3f3f3f3f3f3f;
 
int n, q;
vector<int> T[200005];
int dep[200005], pre[200005][20];
 
void dfs(int v)
{
	rep1(i, 17) pre[v][i] = pre[pre[v][i - 1]][i - 1];
	rep(i, T[v].size()) {
		int u = T[v][i];
		if(u == pre[v][0]) continue;
		pre[u][0] = v; dep[u] = dep[v] + 1;
		dfs(u);
	}
}
int lca(int x, int y)
{
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 17; i >= 0; i --) if((dep[x] - dep[y]) >> i) x = pre[x][i];
	if(x == y) return x;
	for(int i = 17; i >= 0; i --) if(pre[x][i] != pre[y][i]) {
		x = pre[x][i]; y = pre[y][i];
	}
	return pre[x][0];
}

int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x % y);
}
int exgcd(int x, int y, int& u, int& v)
{
	if(y == 0) {
		u = 1; v = 0; return x;
	}
	int ret = exgcd(y, x % y, v, u);
	v -= u * (x / y);
	return ret;
}
LL calc(int m0, int m1, int r0, int r1)
{
	int u, v;
	int g = exgcd(m0, m1, u, v);
	if((r0 - r1) % g != 0) return INF;
	LL ret = (1LL * r0 * v * m1 + 1LL * r1 * u * m0) / g, cyc = 1LL * m0 * m1 / g;
	ret %= cyc;
	if(ret < 0) ret += cyc;
	return ret;
}

LL minz(LL beg, LL st, LL m, LL cnt)
{
	if(beg + st * (cnt - 1) < m) return beg;
	if(st * 2 > m) return minz((beg + st * (cnt - 1)) % m, m - st, m, cnt);
	LL t = beg < st ? 0 : (m - beg - 1) / st + 1;
	beg = (beg + st * t) % m; cnt -= t;
	return minz(beg, (st - m % st) % st, st, (beg + (cnt - 1) * st) / m + 1);
}
LL calc(int l0, int l1, int p0, int q0, int p1, int q1)
{
	if((p0 - p1) & 1) return INF;
	if(q0 - p0 == q1 - p1) return min(calc(l0, l1, p0, p1), calc(l0, l1, q0, q1));
	if(p0 > q0) {
		swap(p0, q0); swap(p1, q1);
	}
	int g = gcd(l0, l1);
	int c = ((p1 - p0) % g + g) % g / 2;
	p0 += c; p1 -= c;
	if(p0 > q0) return INF;
	int len = (q0 - p0) / (g / 2) + 1;
	LL beg = calc(l0, l1, p0, p1), st = calc(l0, l1, g / 2, l1 - g / 2), cyc = 1LL * l0 * l1 / g;
	return minz(beg, st, cyc, len);
}

int l0, p0, q0, l1, p1, q1;
int main()
{
	scanf("%d", &n);
	rep(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		T[u].push_back(v); T[v].push_back(u);
	}
	dfs(1);
	
	scanf("%d", &q);
	rep(i, q) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int x = lca(a, b), y = lca(c, d);
		if(dep[x] > dep[y]) {
			swap(x, y); swap(a, c); swap(b, d);
		}
		l0 = dep[a] + dep[b] - 2 * dep[x]; l1 = dep[c] + dep[d] - 2 * dep[y];
		if(x == y) {
			int ac = lca(a, c), bd = lca(b, d), ad = lca(a, d), bc = lca(b, c);
			if(ac != x || bd != x) {
				p0 = dep[a] - dep[ac]; q0 = dep[bd] + dep[a] - 2 * dep[x];
				p1 = dep[c] - dep[ac]; q1 = dep[bd] + dep[c] - 2 * dep[x];
			} else if(ad != x || bc != x) {
				p0 = dep[a] - dep[ad]; q0 = dep[bc] + dep[a] - 2 * dep[x];
				p1 = dep[ad] + dep[c] - 2 * dep[x]; q1 = dep[c] - dep[bc];
			} else {
				p0 = q0 = dep[a] - dep[x];
				p1 = q1 = dep[c] - dep[x];
			}
		} else {
			int ay = lca(a, y), by = lca(b, y);
			if(ay == y) {
				int ac = lca(a, c), ad = lca(a, d);
				if(ac != y) {
					p0 = dep[a] - dep[ac]; q0 = dep[a] - dep[y];
					p1 = dep[c] - dep[ac]; q1 = dep[c] - dep[y];
				} else if(ad != y) {
					p0 = dep[a] - dep[ad]; q0 = dep[a] - dep[y];
					p1 = dep[c] + dep[ad] - 2 * dep[y]; q1 = dep[c] - dep[y];
				} else {
					p0 = q0 = dep[a] - dep[y];
					p1 = q1 = dep[c] - dep[y];
				}
			} else if(by == y) {
				int bc = lca(b, c), bd = lca(b, d);
				if(bc != y) {
					p0 = dep[a] + dep[y] - 2 * dep[x]; q0 = dep[a] + dep[bc] - 2 * dep[x];
					p1 = dep[c] - dep[y]; q1 = dep[c] - dep[bc];
				} else if(bd != y) {
					p0 = dep[a] + dep[y] - 2 * dep[x]; q0 = dep[a] + dep[bd] - 2 * dep[x];
					p1 = dep[c] - dep[y]; q1 = dep[c] + dep[bd] - 2 * dep[y];
				} else {
					p0 = q0 = dep[a] + dep[y] - 2 * dep[x];
					p1 = q1 = dep[c] - dep[y];
				}
			} else {
				printf("-1\n"); continue;
			}
		}
		
		LL ans = INF;
		ans = min(ans, calc(2 * l0, 2 * l1, p0, q0, p1, q1));
		ans = min(ans, calc(2 * l0, 2 * l1, 2 * l0 - p0, 2 * l0 - q0, p1, q1));
		ans = min(ans, calc(2 * l0, 2 * l1, p0, q0, 2 * l1 - p1, 2 * l1 - q1));
		ans = min(ans, calc(2 * l0, 2 * l1, 2 * l0 - p0, 2 * l0 - q0, 2 * l1 - p1, 2 * l1 - q1));
		printf("%lld\n", ans == INF ? -1 : ans);
	}
	return 0;
}