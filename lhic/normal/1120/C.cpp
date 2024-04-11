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

const int AL = 26;
const int SYM = 'a';

struct SA {
	vector<int> sf;
	vector<array<int, AL>> go;
	vector<int> len;
	vector<int> en;
	int newn(int x) {
		sf.push_back(-1);
		go.emplace_back(array<int, AL>());
		go.back().fill(-1);
		len.push_back(0);
		en.push_back(x);
		return sf.size() - 1;
	}
	SA(string s) {
		int cur = newn(0);
		for (int i = 0; i < s.size(); ++i) {
			int c = s[i] - SYM;
			int nw = newn(i + 1);
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
					en.push_back(en[q]);
					sf[q] = sf[nw] = cl;
					while (cur != -1 && go[cur][c] == q)
						go[cur][c] = cl, cur = sf[cur];
				}
			}
			cur = nw;
		}
	}
};



const int MAXN = 5100;

int n, a, b;
int dp[MAXN];

string s;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> a >> b;
	cin >> s;
	SA sa(s);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i)
		dp[i] = i * a;
	for (int i = 0; i < n; ++i) {
		int now = 0;
		dp[i + 1] = min(dp[i + 1], dp[i] + a);
		for (int j = i; j < n; ++j) {
			now = sa.go[now][s[j] - 'a'];
			if (now == -1 || sa.en[now] > i)
				break;
			dp[j + 1] = min(dp[j + 1], dp[i] + b);
		}
	}
	cout << dp[n] << "\n";
	return 0;
}