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
typedef long long llong;
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

const int MAXN = 220000;

int w[MAXN][2];
int go[MAXN][2];
queue<pair<int, int> > qu;
int was[MAXN];
vector<int> eds[MAXN];
vector<int> be[MAXN];
int n, m;

int fldraw = 0;

void dfsDraw(int v) {
	was[v] = 1;
	for (int u: eds[v]) {
		if (was[u] == 2)
			continue;
		if (was[u] == 1)
			fldraw = 1;
		else
			dfsDraw(u);
	}
	was[v] = 2;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int x;
			cin >> x;
			--x;
			eds[i].push_back(x);
			be[x].push_back(i);
		}
	}
	int s;
	cin >> s;
	--s;
	dfsDraw(s);
	memset(was, 0, sizeof(was));
	for (int i = 0; i < n; ++i) {
		if (eds[i].empty()) {
			w[i][0] = 1;
			go[i][0] = -1;
			qu.push(make_pair(i, 0));
		}
	}
	while (!qu.empty()) {
		int x, y;
		tie(x, y) = qu.front();
		qu.pop();
		for (int u: be[x]) {
			if (!w[u][y ^ 1]) {
				w[u][y ^ 1] = 1;
				go[u][y ^ 1] = x;
				qu.push(make_pair(u, y ^ 1));
			}
		}
	}
	if (w[s][1]) {
		vector<int> ans;
		int now = s;
		int cur = 1;
		while (now != -1) {
			ans.push_back(now);
			now = go[now][cur];
			cur ^= 1;
		}
		cout << "Win\n";
		for (int i: ans)
			cout << i + 1 << " ";
		cout << "\n";
	}
	else if (fldraw) {
		cout << "Draw\n";
	}
	else {
		cout << "Lose\n";
	}
	return 0;
}