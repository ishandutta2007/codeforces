#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

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

const int N = 100010;

int n, q;
string t;

string s[3];

vector<int> ps;

int dp[260][260][260];

array<int, 26> nx[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	cin >> t;
	nx[n + 1].fill(n + 1);
	nx[n] = nx[n + 1];
	for (int i = n - 1; i >= 0; --i) {
		nx[i] = nx[i + 1];
		nx[i][t[i] - 'a'] = i + 1;
	}
	for (int i = 0; i < q; ++i) {
		char tp;
		int x;
		cin >> tp >> x;
		--x;
		if (tp == '+') {
			char c;
			cin >> c;
			s[x] += c;
			if (x == 0) {
				for (int a = 0; a <= s[1].size(); ++a)
					for (int b = 0; b <= s[2].size(); ++b) {
						int &ans = dp[s[x].size()][a][b]; 
						ans = nx[dp[s[x].size() - 1][a][b]][c - 'a'];
						if (a > 0)
							ans = min(ans, nx[dp[s[x].size()][a - 1][b]][s[1][a - 1] - 'a']);
						if (b > 0)
							ans = min(ans, nx[dp[s[x].size()][a][b - 1]][s[2][b - 1] - 'a']);
					}
			}
			else if (x == 1) {
				for (int a = 0; a <= s[0].size(); ++a)
					for (int b = 0; b <= s[2].size(); ++b) {
						int &ans = dp[a][s[x].size()][b]; 
						ans = nx[dp[a][s[x].size() - 1][b]][c - 'a'];
						if (a > 0)
							ans = min(ans, nx[dp[a - 1][s[x].size()][b]][s[0][a - 1] - 'a']);
						if (b > 0)
							ans = min(ans, nx[dp[a][s[x].size()][b - 1]][s[2][b - 1] - 'a']);
					}
			}
			else if (x == 2) {
				for (int a = 0; a <= s[0].size(); ++a)
					for (int b = 0; b <= s[1].size(); ++b) {
						int &ans = dp[a][b][s[x].size()]; 
						ans = nx[dp[a][b][s[x].size() - 1]][c - 'a'];
						if (a > 0)
							ans = min(ans, nx[dp[a - 1][b][s[x].size()]][s[0][a - 1] - 'a']);
						if (b > 0)
							ans = min(ans, nx[dp[a][b - 1][s[x].size()]][s[1][b - 1] - 'a']);
					}
			}
		}
		else {
			s[x].pop_back();
		}
		if (dp[s[0].size()][s[1].size()][s[2].size()] > n)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}