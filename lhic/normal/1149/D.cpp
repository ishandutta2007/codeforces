#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int N = 72;

int n, m;
ll A, B;

int dp[N][1 << 17];
int p[N];
int sz[N];

int get(int a) {
	if (a == p[a])
		return a;
	return p[a] = get(p[a]);
}

void un(int a, int b) {
	a = get(a), b = get(b);
	if (a == b)
		return;
	if (sz[a] > sz[b])
		swap(a, b);
	p[a] = b;
	sz[b] += sz[a];
}

vector<pair<int, int>> eds[N];
int sv[N][N];
int cl[N];

list<int> lst[N * N];
vector<pair<int, int> > ed;

list<int>::iterator IT[N << 17];
int ans[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> A >> B;
	vector<pair<int, int>> cur;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cur.emplace_back(i, j);
		}
	sort(ALL(cur), [&] (pair<int, int> x, pair<int, int> y) {
				return x.first * A + x.second * B < y.first * A + y.second * B;
			});
	for (int i = 0; i < cur.size(); ++i)
		sv[cur[i].first][cur[i].second] = i;
	for (int i = 0; i < n; ++i)
		p[i] = i, sz[i] = 1;
	for (int i = 0; i < n; ++i)
		ans[i] = cur.size();
	for (int i = 0; i < m; ++i) {
		int a, b;
		int c;
		cin >> a >> b >> c;
		--a, --b;
		if (c == A)
			c = 0;
		else
			c = 1;
		if (c == 0) {
			un(a, b);
			eds[a].emplace_back(b, c);
			eds[b].emplace_back(a, c);
		}
		else {
			ed.emplace_back(a, b);
		}
	}
	for (auto e: ed) {
		int a, b;
		tie(a, b) = e;
		if (get(a) != get(b)) {
			eds[a].emplace_back(b, 1);
			eds[b].emplace_back(a, 1);
		}
	}
	int cc = 0;
	fill(cl, cl + n, -1);
	for (int i = 0; i < n; ++i)
		if (p[i] == i && sz[i] >= 4)
			cl[i] = cc++;
	for (int i = 0; i < n; ++i) {
		cl[i] = cl[get(i)];
	}
	for (int i = 0; i < n; ++i) {
		if (cl[i] == -1)
			cl[i] = 0;
		else
			cl[i] = (1 << cl[i]);
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < (1 << cc); ++j)
			dp[i][j] = cur.size() - 1;
	int msk = (1 << cc) - 1;
	dp[0][cl[0]] = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < (1 << cc); ++j) {
			lst[dp[i][j]].push_back((i << cc) + j);
			IT[(i << cc) + j] = prev(lst[dp[i][j]].end());
		}
	for (int qq = 0; qq < cur.size(); ++qq) {
		int x = cur[qq].first;
		int y = cur[qq].second;
		while (!lst[qq].empty()) {
			int tmp = lst[qq].front();
			lst[qq].pop_front();
			int v = tmp >> cc;
			int k = tmp & msk;
			ans[v] = min(ans[v], dp[v][k]);
			int m1, m2;
			if (x + 1 < N)
				m1 = sv[x + 1][y];
			else
				m1 = cur.size() - 1;
			if (y + 1 < N)
				m2 = sv[x][y + 1];
			else
				m2 = cur.size() - 1;
			for (auto e: eds[v]) {
				int u = e.first;
				if (e.second == 0) {
					if (dp[u][k] > m1) {
						lst[dp[u][k]].erase(IT[(u << cc) + k]);
						dp[u][k] = m1;
						lst[dp[u][k]].push_front((u << cc) + k);
						IT[(u << cc) + k] = lst[dp[u][k]].begin();
					}
				}
				else if ((k & cl[u]) == 0) {
					int nk = k | cl[u];
					if (dp[u][nk] > m2) {
						lst[dp[u][nk]].erase(IT[(u << cc) + nk]);
						dp[u][nk] = m2;
						lst[dp[u][nk]].push_front((u << cc) + nk);
						IT[(u << cc) + nk] = lst[dp[u][nk]].begin();
					}
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		int x = ans[i];
		cout << cur[x].first * A + cur[x].second * B << " ";
	}
	cout << "\n";
	return 0;
}