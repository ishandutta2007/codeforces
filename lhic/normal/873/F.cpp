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

const int AL = 26;
const int SYM = 'a';

const int MAXN = 1000000;
int dp[MAXN];
int mn[MAXN];

ll ans = 0;
string t;

struct SA {
	vector<int> sf;
	vector<array<int, AL>> go;
	vector<int> len;
	int newn() {
		sf.push_back(-1);
		go.emplace_back(array<int, AL>());
		go.back().fill(-1);
		len.push_back(0);
		return sf.size() - 1;
	}
	SA(string s) {
		int cur = newn();
		for (int i = 0; i < s.size(); ++i) {
			int c = s[i] - SYM;
			int nw = newn();
			len[nw] = i + 1;
			while (cur != -1 && go[cur][c] == -1)
				go[cur][c] = nw, cur = sf[cur];
			if (cur == -1)
				sf[nw] = 0;
			else {
				int q = go[cur][c];
				if (len[q] == len[cur] + 1)
					sf[nw] = q;
				else {
					int cl = len.size();
					len.push_back(len[cur] + 1);
					go.push_back(go[q]);
					sf.push_back(sf[q]);
					sf[q] = sf[nw] = cl;
					while (cur != -1 && go[cur][c] == q)
						go[cur][c] = cl, cur = sf[cur];
				}
			}
			cur = nw;
			if (t[i] == '1')
				mn[cur] += 1;
		}
		int now = cur;
		while (now != -1)
			++dp[now], now = sf[now];
		vector<pair<int, int> > vv;
		for (int i = 0; i < len.size(); ++i)
			vv.emplace_back(len[i], i);
		sort(ALL(vv));
		reverse(ALL(vv));
		for (auto tmp: vv) {
			int i = tmp.second;
			for (int j = 0; j < AL; ++j)
				if (go[i][j] != -1)
					dp[i] += dp[go[i][j]];
			if (sf[i] != -1)
				mn[sf[i]] += mn[i];
			ans = max(ans, ll(len[i]) * (dp[i] - mn[i]));
		}
	}
};




int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int n;
	cin >> n;
	string s;
	cin >> s;
	cin >> t;
	SA cur(s);
	cout << ans << "\n";
	return 0;
}