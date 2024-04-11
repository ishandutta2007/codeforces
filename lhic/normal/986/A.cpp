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

int n, m, k, s;
int a[120000];
vector<int> eds[120000];
queue<int> qu;
int dd[120000];
const int INF = 1e9;
vector<int> go[120000];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m >> k >> s;
	for (int i = 0; i < n; ++i)
		cin >> a[i], --a[i];
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	for (int i = 0; i < k; ++i) {
		fill(dd, dd + n, INF);
		for (int j = 0; j < n; ++j)
			if (a[j] == i)
				dd[j] = 0, qu.push(j);
		while (!qu.empty()) {
			int x = qu.front();
			qu.pop();
			for (int u: eds[x])
				if (dd[u] > dd[x] + 1) {
					dd[u] = dd[x] + 1;
					qu.push(u);
				}
		}
		for (int i = 0; i < n; ++i) {
			go[i].push_back(dd[i]);
		}
	}
	for (int i = 0; i < n; ++i) {
		nth_element(go[i].begin(), go[i].begin() + s - 1, go[i].end());
		ll ans = 0;
		for (int j = 0; j < s; ++j)
			ans += go[i][j];
		cout << ans << " ";
	}
	cout << "\n";
	return 0;
}