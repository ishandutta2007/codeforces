#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

#define rep(i, l, r) for (int i = l; i < r; ++i)

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

const int MAXN = 1200;
const int INF = 1e6;

int n;

string s[MAXN];

int v[MAXN];

vector<pair<string, int> > rq1[MAXN];
vector<int> rq[MAXN];

set<tuple<int, int, int> > ss;

map<pair<string, int>, int> mm;

set<string> in;

vector<pair<string, int >> ans;
int dd[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	rep(i, 0, n) {
		cin >> s[i] >> v[i];
		int k;
		cin >> k;
		rep(j, 0, k) {
			string a;
			int b;
			cin >> a >> b;
			rq1[i].push_back({a, b});
		}
	}
	rep(i, 0, n) {
		mm[{s[i], v[i]}] = i;
	}
	rep(i, 0, n) {
		for (auto x: rq1[i])
			rq[i].emplace_back(mm[{x.first, x.second}]);
	}
	fill(dd, dd + n, INF);
	dd[0] = 0;
	ss.insert({0, -v[0], 0});
	while (!ss.empty()) {
		int x = get<2>(*ss.begin());
		ss.erase(ss.begin());
		if (in.count(s[x]))
			continue;
		if (x != 0)
			ans.push_back({s[x], v[x]});
		in.insert(s[x]);
		for (int y: rq[x]) {
			if (dd[y] > dd[x] + 1) {
				ss.erase({dd[y], -v[y], y});
				dd[y] = dd[x] + 1;
				ss.insert({dd[y], -v[y], y});
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (auto x: ans)
		cout << x.first << " " << x.second << "\n";
	return 0;
}