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

const int MX = 2005;
const int MAXN = 2100;

int n, m;

bitset<MX> bb[MAXN];
int cc[MAXN];
int cnt[MAXN];

string s[MAXN];
vector<pair<int, int>> ed;
void add_edge(int a, int b) {
	ed.emplace_back(a, b);
}

int en[MAXN];

mt19937 rnd(123);
void no() {
	cout << "NO\n";
}
int go[MAXN][MAXN];
int dp[MAXN][MAXN];
int cur[MAXN];

void solve() {
	ed.clear();
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		bb[i].reset(), cnt[i] = 0, en[i] = 1;
	for (int i = 0; i < m; ++i) {
		cin >> s[i];
		cc[i] = 0;
		for (int j = 0; j < n; ++j)
			if (s[i][j] == '1')
				++cc[i];
		if (cc[i] != 1) {
			for (int j = 0; j < n; ++j)
				if (s[i][j] == '1')
					++cnt[j], bb[j][i] = 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		cur[i] = m;
		for (int j = 0; j < MAXN; ++j)
			dp[i][j] = 0;
	}
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			go[i][j] = go[j][i] = (bb[i] & bb[j]).count();
			++dp[i][go[i][j]];
			++dp[j][go[i][j]];
		}

	for (int it = 1; it < n; ++it) {
		int x = -1;
		for (int j = 0; j < n; ++j) {
			if (!en[j])
				continue;
			while (dp[j][cur[j]] == 0)
				--cur[j];
			if (cur[j] == cnt[j]) {
				x = j;
				break;
			}
		}
		if (x == -1)
			return no();
		int y = -1;
		en[x] = 0;
		for (int j = 0; j < n; ++j)
			if (en[j] && go[x][j] == cnt[x]) {
				y = j;
				break;
			}
		if (y == -1)
			return no();
		add_edge(x, y);
		for (int j = 0; j < n; ++j)
			if (en[j])
				--dp[j][go[j][x]];
		for (int j = 0; j < m; ++j) {
			if (bb[x][j]) {
				--cc[j];
				if (cc[j] == 1) {
					--cnt[y];
				}
			}
		}
	}
	cout << "YES\n";
	for (int i = 0; i < ed.size(); ++i) {
		cout << ed[i].first + 1 << " " << ed[i].second + 1 << "\n";
	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
		solve();
	}
	return 0;
}