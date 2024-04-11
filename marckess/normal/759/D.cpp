#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 5005, mod = 1000000007;
int n, dp[MX][MX], acu[MX], ult[256];
string s;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);	

	cin >> n >> s;

	for (int i = n - 1; i + 1; i--) {
		dp[i][n] = 1;
		if (!ult[s[i]]) acu[n]++;

		for (int j = n - 1; j + 1; j--) {
			dp[i][j] = acu[j + 1];
			acu[j] += dp[i][j];
			if (ult[s[i]]) acu[j] -= dp[ult[s[i]]][j];
			if (acu[j] >= mod) acu[j] -= mod;
			if (acu[j] < 0) acu[j] += mod;
		}
		ult[s[i]] = i;
	}

	cout << dp[0][0] << endl;

	return 0;
}