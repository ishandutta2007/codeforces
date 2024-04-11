#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

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

const int MAXN = 310000;

int n, q;

vector<pair<int, int>> go[MAXN];
int tm1;
pair<int, int> lst[MAXN];
int ts[MAXN];
vector<int> vv[MAXN];

void solve() {
	cin >> n;
	cin >> q;
	for (int i = 0; i < n; ++i)
		go[i].clear();
	int fl = 0;
	for (int i = 0; i < q; ++i) {
		int k;
		++tm1;
		cin >> k;
		vv[i].clear();
		for (int j = 0; j < k; ++j) {
			int x;
			cin >> x;
			--x;
			vv[i].push_back(x);
		}
		for (int j = 0; j < vv[i].size(); ++j) {
			for (auto e: go[vv[i][j]]) {
				if (ts[e.first] < tm1) {
					ts[e.first] = tm1;
					lst[e.first] = make_pair(n, n);
				}
				if (lst[e.first].second <= e.second) {
					fl = 1;
					break;
				}
				if (lst[e.first].first <= e.second)
					continue;
				lst[e.first].first = e.second;
				int len = 0;
				while (e.second + len < vv[e.first].size() && j + len < vv[i].size() && vv[e.first][e.second + len] == vv[i][j + len])
					++len;
				lst[e.first].second = lst[e.first].first + len;
			}
		}
		for (int j = 0; j < vv[i].size(); ++j)
			go[vv[i][j]].emplace_back(i, j);
	}
	if (fl)
		cout << "Human\n";
	else
		cout << "Robot\n";
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i)
		solve();
	return 0;
}