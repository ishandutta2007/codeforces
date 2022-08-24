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

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
		cerr << (*i) << " ";
    }
    cerr << "\n";
}

const int MAXN = 1200000;

int n, m;
int fl[MAXN];
vector<int> eds[MAXN];
int was[MAXN];

void dfs1(int v) {
	was[v] = 1;
	for (int u: eds[v]) {
		if (!was[u])
			dfs1(u);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		if (a == b)
			fl[a] = 1;
		else
			eds[a].push_back(b), eds[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		if (eds[i].size() || fl[i]) {
			dfs1(i);
			break;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (eds[i].size() || fl[i]) {
			if (!was[i]) {
				cout << 0 << "\n";
				return 0;
			}
		}
	}
	ll ans = 0;
	ll cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (fl[i])
			++cnt;
		if (eds[i].size())
			ans += (ll)eds[i].size() * (ll)(eds[i].size() - 1) / 2;
	}
	ans += cnt * (m - cnt);
	ans += cnt * (cnt - 1) / 2;
	cout << ans << "\n";
	return 0;
}