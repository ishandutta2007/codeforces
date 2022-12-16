// LUOGU_RID: 91573034
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
#define fir first
#define sec second

const ll maxn = 1e6 + 10, inf = 1e18;
#define id(i, j) ((i) * m + (j) + 1)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
ll n, m, p, q, dis[maxn];
struct Edge {
	ll v, w, nxt;
} e[maxn << 1];
ll h[maxn], cnt_e;
void add(ll x, ll y, ll z) { e[++cnt_e] = {y, z, h[x]}, h[x] = cnt_e; }

int main() {
	cin >> n >> m >> p >> q;
	vector <string> mp(n);
	for (int i = 0; i < n; ++i) cin >> mp[i];
	auto add2 = [&] (ll i, ll j, ll x, ll y, ll z) {
		if (x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == '#') return;
		add(id(x, y), id(i, j), z);
	};
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (mp[i][j] == 'L' || mp[i][j] == 'R') {
				int x = i, y = (mp[i][j] == 'L' ? j + 1 : j - 1);
				add2(i, j, x + 1, y, p), add2(i, j, x - 1, y, p);
				add2(i, j, x, y * 2 - j, q);
			}
			if (mp[i][j] == 'U' || mp[i][j] == 'D') {
				int x = (mp[i][j] == 'U' ? i + 1 : i - 1), y = j;
				add2(i, j, x, y + 1, p), add2(i, j, x, y - 1, p);
				add2(i, j, x * 2 - i, y, q);
			}
		}
	memset(dis, 0x3f, sizeof dis);
	priority_queue < pll, vector <pll>, greater <pll> > pq;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) if (mp[i][j] == '.') pq.push({dis[id(i, j)] = 0, id(i, j)});
	while (!pq.empty()) {
		ll u = pq.top().sec, val = pq.top().fir; pq.pop();
		if (val != dis[u]) continue;
		for (int j = h[u]; j; j = e[j].nxt) {
			ll v = e[j].v, w = e[j].w;
			if (dis[v] > val + w)
				dis[v] = val + w, pq.push({dis[v], v});
		}
	}
	ll ans = inf;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (i < n - 1) ans = min(ans, dis[id(i, j)] + dis[id(i + 1, j)]);
			if (j < m - 1) ans = min(ans, dis[id(i, j)] + dis[id(i, j + 1)]);
		}
	if (ans == inf) ans = -1;
	cout << ans << endl;
	return 0;
}