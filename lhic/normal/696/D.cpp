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

const int MX = 300;

ll l;
int n;
int nowc = 1;
int go[MX][26];
int sf[MX];
int pp[MX];
int pc[MX];
ll cs[MX];
ll dp[50][MX][MX];
ll cur[MX], cur2[MX];

void add(string s, ll c) {
	int now = 0;
	for (char c: s) {
		int x = c - 'a';
		if (go[now][x]) {
			now = go[now][x];
		}
		else {
			go[now][x] = nowc;
			pc[nowc] = x;
			pp[nowc] = now;
			now = nowc++;
		}
	}
	cs[now] += c;
}

void build() {
	queue<int> qu;
	qu.push(0);
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		for (int i = 0; i < 26; ++i)
			if (go[x][i])
				qu.push(go[x][i]);
		if (x == 0)
			sf[x] = -1;
		else if (pp[x] == 0) {
			sf[x] = 0;
		}
		else {
			sf[x] = go[sf[pp[x]]][pc[x]];
			cs[x] += cs[sf[x]];
		}
		for (int i = 0; i < 26; ++i)
			if (!go[x][i])
				go[x][i] = go[sf[x]][i];
	}
}

ll cost[MX];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> l;
	for (int i = 0; i < n; ++i)
		cin >> cost[i];
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		add(s, cost[i]);
	}
	build();
	for (int i = 0; i < nowc; ++i)
		for (int j = 0; j < nowc; ++j)
			dp[0][i][j] = -1;
	for (int i = 0; i < nowc; ++i)
		for (int j = 0; j < 26; ++j)
			dp[0][i][go[i][j]] = max(dp[0][i][go[i][j]], cs[go[i][j]]);
	for (int i = 0; i < nowc; ++i)
		cur[i] = -1;
	cur[0] = 0;
	for (int it = 0; it + 1 < 50; ++it) {
		for (int i = 0; i < nowc; ++i)
			for (int j = 0; j < nowc; ++j)
				dp[it + 1][i][j] = -1;
		for (int i = 0; i < nowc; ++i)
			for (int j = 0; j < nowc; ++j) {
				if (dp[it][i][j] == -1)
					continue;
				for (int k = 0; k < nowc; ++k) {
					if (dp[it][j][k] == -1)
						continue;
					dp[it + 1][i][k] = max(dp[it + 1][i][k], dp[it][i][j] + dp[it][j][k]);
				}
			}
		if ((l >> it) & 1) {
			for (int j = 0; j < nowc; ++j)
				cur2[j] = -1;
			for (int j = 0; j < nowc; ++j) {
				if (cur[j] == -1)
					continue;
				for (int k = 0; k < nowc; ++k) {
					if (dp[it][j][k] == -1)
						continue;
					cur2[k] = max(cur2[k], cur[j] + dp[it][j][k]);
				}
			}
			for (int j = 0; j < nowc; ++j)
				cur[j] = cur2[j];
		}
	}
	ll ans = 0;
	for (int j = 0; j < nowc; ++j)
		ans = max(ans, cur[j]);
	cout << ans << "\n";
	return 0;
}