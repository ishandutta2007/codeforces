#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()

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
const int MAXN = 100000;

int n;
string s[MAXN];

vector<pair<int, int> > vv;
int ans[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		for (int j = 0; j < s[i].size(); ++j) {
			int cur = 1;
			for (int k = j; k < s[i].size(); ++k) {
				cur = (cur * 10 + s[i][k] - '0');
				vv.emplace_back(cur, i);
			}
			if (j == 0)
				ans[i] = cur;
		}
	}
	sort(ALL(vv));
	vv.resize(unique(ALL(vv)) - vv.begin());
	for (int i = 0; i < vv.size(); ++i) {
		if (i != 0 && vv[i].first == vv[i - 1].first)
			continue;
		if (i != vv.size() - 1 && vv[i + 1].first == vv[i].first)
			continue;
		ans[vv[i].second] = min(ans[vv[i].second], vv[i].first);
	}
	for (int i = 0; i < n; ++i) {
		string s;
		while (ans[i] != 1)
			s += char('0' + ans[i] % 10), ans[i] /= 10;
		reverse(s.begin(), s.end());
		cout << s << "\n";
	}
	return 0;
}