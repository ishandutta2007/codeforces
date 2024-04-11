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
const int MAXN = 120000;

int n;
string s[MAXN];
int tp[MAXN];
int fl[MAXN];
int av[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		av[i] = 1;
	for (int i = 0; i < n; ++i) {
		cin >> s[i] >> tp[i];
		cnt += tp[i];
		fl[i] = 1;
		for (int j = 0; j < s[i].size(); ++j) {
			if (!isdigit(s[i][j]))
				fl[i] = 0;
		}
		if (s[i][0] == '0')
			fl[i] = 0;
		if (fl[i] == 1) {
			int cur = 0;
			for (char c: s[i])
				cur = (cur * 10 + c - '0');
			if (cur <= n) {
				fl[i] = cur;
				av[cur] = 0;
			} else {
				fl[i] = 0;
			}
		}
	}
	set<int> av1, av2;
	for (int i = 1; i <= cnt; ++i)
		if (av[i])
			av1.insert(i);
	for (int i = cnt + 1; i <= n; ++i)
		if (av[i])
			av2.insert(i);
	set<int> go1, go2;
	for (int i = 0; i < n; ++i) {
		if (fl[i]) {
			if (tp[i] && fl[i] > cnt)
				go1.insert(i);
			else if (!tp[i] && fl[i] <= cnt)
				go2.insert(i);
		}
	}
	vector<pair<string, string>> ans;
	while (av1.size() + av2.size() && go1.size() + go2.size()) {
		if (av1.size() && go1.size()) {
			int x = *go1.begin();
			go1.erase(x);
			int y = *av1.begin();
			av1.erase(y);
			ans.emplace_back(s[x], to_string(y));
			av2.insert(fl[x]);
		} else if (av2.size() && go2.size()) {
			int x = *go2.begin();
			go2.erase(x);
			int y = *av2.begin();
			av2.erase(y);
			ans.emplace_back(s[x], to_string(y));
			av1.insert(fl[x]);
		} else {
			assert(false);
		}
	}
	if (go1.size() + go2.size()) {
		assert(go1.size() == go2.size());
		vector<string> v1, v2;
		for (int i: go1)
			v1.push_back(s[i]);
		for (int i: go2)
			v2.push_back(s[i]);
		ans.emplace_back(v1[0], "aba");
		for (int i = 0; i < v1.size(); ++i) {
			ans.emplace_back(v2[i], v1[i]);
			if (i + 1 < v1.size())
				ans.emplace_back(v1[i + 1], v2[i]);
			else
				ans.emplace_back("aba", v2[i]);
		}
	}
	else {
		for (int i = 0; i < n; ++i)
			if (!fl[i]) {
				if (tp[i] == 1) {
					int x = *av1.begin();
					av1.erase(x);
					ans.emplace_back(s[i], to_string(x));
				}
				else {
					int x = *av2.begin();
					av2.erase(x);
					ans.emplace_back(s[i], to_string(x));
				}
			}
	}
	cout << ans.size() << "\n";
	for (auto x: ans)
		cout << "move " << x.first << " " << x.second << "\n";

	return 0;
}