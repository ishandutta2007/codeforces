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

const int MAXN = 210000;

int n;
vector<int> eds[MAXN];
int a[MAXN];
int pos[MAXN];
int was[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	rep(i, 1, n) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
		cin >> a[i], --a[i], pos[a[i]] = i;
	for (int i = 0; i < n; ++i) {
		sort(eds[i].begin(), eds[i].end(), [] (int x, int y) {
				return pos[x] < pos[y];
				});
	}
	vector<int> cur;
	queue<int> qu;
	qu.push(0);
	was[0] = 1;
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		cur.push_back(x);
		for (int u: eds[x]) {
			if (!was[u])
				qu.push(u), was[u] = 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (cur[i] != a[i]) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}