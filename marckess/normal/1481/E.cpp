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

const int MX = 500005;
int n, a[MX], ini[MX], fin[MX], cn[MX], dp[MX];
vi pos, in[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(ini, -1, sizeof(ini));
	memset(fin, -1, sizeof(fin));
	
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		
		if (ini[a[i]] == -1) {
			pos.pb(i);
			ini[a[i]] = i;
		}
		
		in[a[i]].pb(i);
		fin[a[i]] = i;
		cn[a[i]]++;
	}
	
	for (int i = n - 1, mx = 0; i >= 0; i--) {
		if (i == ini[a[i]]) {
			dp[i] = dp[fin[a[i]] + 1] + cn[a[i]];
		} else {
			int j = lower_bound(all(in[a[i]]), i) - in[a[i]].begin();
			dp[i] = int(in[a[i]].size()) - j;
		}
		
		dp[i] = max(dp[i], mx);
		mx = max(mx, dp[i]);
	}
	
	cout << n - dp[0] << endl;
	
	return 0;
}