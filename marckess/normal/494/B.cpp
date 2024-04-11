#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005, mod = 1000000007;
int n, m, nex[MX], dp[MX], sum[MX];
string s, t;

vi obtZF (const string &s) {
	int n = s.size();
	vi zf(n);

	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r)
			zf[i] = min (r - i + 1, zf[i - l]);

		while (i + zf[i] < n && s[zf[i]] == s[i + zf[i]])
			zf[i]++;

		if (i + zf[i] - 1 > r)
			l = i, r = i + zf[i] - 1;
	}

	return zf;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(nex, -1, sizeof(nex));

	cin >> s >> t;
	n = s.size(), m = t.size();

	vi z = obtZF(t + s);

	dp[n] = sum[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		if (z[i + m] >= m) nex[i] = i + m;
		else nex[i] = nex[i + 1];

		dp[i] = dp[i + 1];
		if (nex[i] != -1)
			(dp[i] += sum[nex[i]]) %= mod;

		sum[i] = (dp[i] + sum[i + 1]) % mod;
	}

	cout << MOD(dp[0] - 1, mod) << endl;

	return 0;
}