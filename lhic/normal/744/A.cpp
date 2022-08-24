#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 120000;
int n, m, k;
int fl[MAXN];
vector<int> eds[MAXN];
int was[MAXN];

pair<int, int> dfs1(int v) {
	was[v] = 1;
	int sz = 1;
	int f = 0;
	if (fl[v])
		f = 1;
	for (int u: eds[v]) {
		if (!was[u]) {
			pair<int, int> tmp = dfs1(u);
			f |= tmp.second;
			sz += tmp.first;
		}
	}
	return make_pair(sz, f);
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		--x;
		fl[x] = 1;
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	ll ans = -m;
	int mxg = 0;
	vector<int> vv;
	for (int i = 0; i < n; ++i) {
		if (!was[i]) {
			pair<int, int> tmp = dfs1(i);
			ans += (ll)tmp.first * (ll)(tmp.first - 1) / 2;
			if (tmp.second)
				mxg = max(mxg, tmp.first);
			else
				vv.push_back(tmp.first);
		}
	}
	for (int i: vv) {
		ans += (ll)mxg * (ll)i;
		mxg += i;
	}
	cout << ans << "\n";
	return 0;
}