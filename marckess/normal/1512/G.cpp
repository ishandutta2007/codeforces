#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 10000005;
int n, dp[MX], bs[MX];

void solve () {
	cin >> n;
	cout << dp[n] << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 1; i < MX; i++)
		for (int j = i; j < MX; j += i)
			bs[j] += i;
	
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i < MX; i++)
		if (bs[i] < MX)
			if (dp[bs[i]] == -1)
				dp[bs[i]] = i;
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}