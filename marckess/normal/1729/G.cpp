#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 505, mod = 1000000007;
int n, m, /*dp[2][MX][MX],*/ sig[MX], vis[MX][MX];
vi pos;
string s, t;
ii mem[MX][MX];

void sum (int &a, int b) {
	a += b;
	if (a >= mod)
		a -= mod;
}

ii dp (int i, int j) {
	if (i == pos.size()) {
		if (j == n)
			return ii(0, 1);
		else
			return ii(1e9, 0);
	}
	
	if (j < pos[i]) return ii(1e9, 0);
	
	ii &res = mem[i][j];
	if (vis[i][j]) return res;
	vis[i][j] = 1;
	
	ii x = dp(i + 1, j);
	ii y = dp(sig[i], sig[i] < pos.size() ? pos[sig[i]] + m - 1 : n);
	y.fi++;
	
	if (x.fi == y.fi)
		return res = ii(x.fi, (x.se + y.se) % mod);
	return res = min(x, y);
}

void main_() {
	cin >> s >> t;
	n = s.size(), m = t.size();
	
	pos.clear();
	
	forn (i, n - m + 1)
		if (s.substr(i, m) == t)
			pos.pb(i);
	
	if (!pos.size()) {
		cout << "0 1" << endl;
		return;
	}
	
	forn (i, pos.size())
		sig[i] = lower_bound(all(pos), pos[i] + m) - pos.begin();
	
	memset(vis, 0, sizeof(vis));
	ii res = dp(0, pos[0] + m - 1);
	
	cout << res.fi << " " << res.se << endl;
	
	/*
	memset(dp, 0, sizeof(dp));
	dp[pos.size() % 2][pos.size()][0] = 1;
		
	for (int i = int(pos.size()) - 1; i >= 0; i--) {
		int x = i % 2, y = (i + 1) % 2;
		memset(dp[x], 0, sizeof(dp[x]));
		
		forn (j, pos.size() + 1)
		forn (k, MX) {
			if (j < pos.size() && pos[j] + m - 1 < pos[i]) continue;
			
			sum(dp[x][j][k], dp[y][j][k]);
			
			if (k)
				sum(dp[x][j][k], dp[y][i + 1][k - 1]);
		}
	}
	
	forn (k, MX)
		if (dp[0][0][k]) {
			cout << k << " " << dp[0][0][k] << endl;
			return;
		}
	
	cout << -1 << " " << -1 << endl; */
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}