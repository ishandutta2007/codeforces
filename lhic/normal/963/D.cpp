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

const int MAXN = 101000;

string s;
int n;

int k[MAXN];
string t[MAXN];

int go[MAXN][26];

vector<int> gg[MAXN];

int sf[MAXN];
int pp[MAXN];
int pc[MAXN];
int cc = 1;

int newn(int p, int c) {
	pc[cc] = c;
	pp[cc] = p;
	return cc++;
}

void add(const string &s, int x) {
	int now = 0;
	for (char c: s) {
		int x = c - 'a';
		if (go[now][x]) {
			now = go[now][x];
		}
		else {
			now = go[now][x] = newn(now, x);
		}
	}
	gg[now].push_back(x);
}

void buildak() {
	queue<int> qu;
	qu.push(0);
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		for (int i = 0; i < 26; ++i)
			if (go[x][i])
				qu.push(go[x][i]);
		if (x == 0) {
			sf[x] = -1;
			continue;
		}
		else if (pp[x] == 0)
			sf[x] = 0;
		else
			sf[x] = go[sf[pp[x]]][pc[x]];
		for (int i = 0; i < 26; ++i)
			if (!go[x][i])
				go[x][i] = go[sf[x]][i];
		for (int i: gg[sf[x]])
			gg[x].push_back(i);
	}
}

vector<int> pos[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> s;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> k[i] >> t[i];
		add(t[i], i);
	}
	buildak();
	int now = 0;
	for (int i = 0; i < s.size(); ++i) {
		now = go[now][s[i] - 'a'];
		for (int x: gg[now])
			pos[x].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		if (pos[i].size() < k[i]) {
			cout << -1 << "\n";
			continue;
		}
		int ans = s.size();
		for (int j = k[i] - 1; j < pos[i].size(); ++j)
			ans = min(ans, pos[i][j] - pos[i][j - (k[i] - 1)] + (int)t[i].size());
		cout << ans << "\n";
	}
	return 0;
}