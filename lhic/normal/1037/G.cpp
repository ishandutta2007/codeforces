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
const int MAXN = 100010;

string s;
int n;
int nx[MAXN][30];
int pr[MAXN][30];
int gl[MAXN][30];
int gr[MAXN][30];
int tmp[30];
int sm[MAXN];
int sm2[30];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> s;
	n = s.size();
	for (int i = 0; i < 26; ++i)
		nx[n][i] = n;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < 26; ++j)
			nx[i][j] = nx[i + 1][j];
		nx[i][s[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; ++i)
		pr[0][i] = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 26; ++j)
			pr[i + 1][j] = pr[i][j];
		pr[i + 1][s[i] - 'a'] = i;
	}
	for (int i = n - 1; i >= 0; --i) {
		sm[i] = sm2[s[i] - 'a'];
		vector<pair<int, int>> vv;
		for (int j = 0; j < 26; ++j)
			if (nx[i][j] != n)
				vv.emplace_back(nx[i][j], j);
		sort(vv.begin(), vv.end());
		for (int j_ = 0; j_ < vv.size(); ++j_) {
			int j = vv[j_].second;
			fill(tmp, tmp + 30, 0);
			int r = vv[j_].first;
			for (int g = 0; g < 26; ++g) {
				if (nx[i][g] < r) {
					int lst = pr[r][g];
					int go = gl[i][g] ^ sm[nx[i][g]] ^ sm[lst] ^ gl[lst + 1][j]; 
					tmp[go] = 1;
				}
			}
			while (tmp[gl[i][j]])
				++gl[i][j];
		}
		if (i)
			sm2[s[i - 1] - 'a'] ^= gl[i][s[i - 1] - 'a'];
	}
	for (int i = 1; i <= n; ++i) {
		vector<pair<int, int>> vv;
		for (int j = 0; j < 26; ++j)
			if (pr[i][j] != -1)
				vv.emplace_back(pr[i][j], j);
		sort(vv.rbegin(), vv.rend());
		for (int j_ = 0; j_ < vv.size(); ++j_) {
			int j = vv[j_].second;
			fill(tmp, tmp + 30, 0);
			int l = vv[j_].first + 1;
			for (int g = 0; g < 26; ++g) {
				if (pr[i][g] >= l) {
					int lst = nx[l][g];
					int go = gr[i][g] ^ sm[pr[i][g]] ^ sm[lst] ^ gr[lst][j]; 
					tmp[go] = 1;
				}
			}
			while (tmp[gr[i][j]])
				++gr[i][j];
		}
	}
	
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		fill(tmp, tmp + 30, 0);
		for (int j = 0; j < 26; ++j) {
			if (nx[l][j] < r) {
				int lst = pr[r][j];
				int go = sm[nx[l][j]] ^ sm[lst] ^ gl[l][j] ^ gr[r][j];
				tmp[go] = 1;
			}
		}
		int x = 0;
		while (tmp[x])
			++x;
		if (x)
			cout << "Alice\n";
		else
			cout << "Bob\n";
	}
	return 0;
}