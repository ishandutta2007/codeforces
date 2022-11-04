#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005;
int n, k, a[MX], mn, res;

void solve () {
	mn = 1e9;
	
	cin >> n >> k;
	forn (i, n) {
		cin >> a[i];
		mn = min(mn, a[i]);
	}
	
	res = 0;
	forn (i, n) res += (k - a[i]) / mn;
	res -= (k - mn) / mn;
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 	
	int t;
	cin >> t;
	while (t--)
		solve(); 	

	return 0;
}