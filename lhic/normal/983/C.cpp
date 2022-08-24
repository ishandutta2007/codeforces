#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

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
const int MX = 50000;

vector<pair<int, int> > vv;
vector<tuple<int, int, int, int, int> > qu[MX + 100];
int dp[2010][10][10][10][10];
const int INF = 1e9;

void upd(int x, int cur, int a, int b, int c, int dd) {
	if (dp[x][cur][a][b][c] > dd) {
		dp[x][cur][a][b][c] = dd;
		qu[dd].emplace_back(x, cur, a, b, c);
	}
}
int n;
vector<int> now;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		vv.emplace_back(a, b);
	}
	for (int i = 0; i <= n; ++i) {
		for (int cur = 1; cur <= 9; ++cur)
			for (int a = 0; a <= 9; ++a)
				for (int b = 0; b <= 9; ++b)
					for (int c = 0; c <= 9; ++c)
						dp[i][cur][a][b][c] = INF;
	}
	dp[0][1][0][0][0] = 0;
	qu[0].push_back(make_tuple(0, 1, 0, 0, 0));
	for (int it = 0; it < MX; ++it) {
		for (int j = 0; j < qu[it].size(); ++j) {
			int x, cur, a, b, c;
			tie(x, cur, a, b, c) = qu[it][j];
			if (dp[x][cur][a][b][c] != it)
				continue;
			if (cur > 1)
				upd(x, cur - 1, a, b, c, it + 1);
			if (cur < 9)
				upd(x, cur + 1, a, b, c, it + 1);
			now.clear();
			int fl = 0;
			for (int i: {a, b, c}) {
				if (!fl && i == cur)
					fl = 1;
				else if (i != 0)
					now.push_back(i);
			}
			if (fl) {
				while (now.size() < 3)
					now.push_back(0);
				upd(x, cur, now[0], now[1], now[2], it + 1);
			}
			else {
				if (x < n && vv[x].first == cur) {
					if (now.size() < 3) {
						now.push_back(vv[x].second);
						while (now.size() < 3)
							now.push_back(0);
						upd(x + 1, cur, now[0], now[1], now[2], it + 1);
					}
					else if (now.size() == 3) {
						now.push_back(vv[x].second);
						upd(x + 1, now[0], now[1], now[2], now[3], it + 2 + abs(now[0] - cur));
						upd(x + 1, now[1], now[0], now[2], now[3], it + 2 + abs(now[1] - cur));
						upd(x + 1, now[2], now[1], now[0], now[3], it + 2 + abs(now[2] - cur));
						upd(x + 1, now[3], now[1], now[2], now[0], it + 2 + abs(now[3] - cur));
					}
				}
			}
		}
	}
	int ans = 1e9;
	for (int i = 1; i <= 9; ++i) {
		ans = min(ans, dp[n][i][0][0][0]);
	}
	cout << ans << "\n";
	return 0;
}