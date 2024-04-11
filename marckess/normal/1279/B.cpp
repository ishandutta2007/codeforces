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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, k;
ll a[MX], s[MX];

void solve () {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	s[0] = a[0];
	for (int i = 1; i < n; i++)
		s[i] = a[i] + s[i-1];

	int i = upper_bound(s, s+n, k) - s;
	int mx = i, res = 0;

	for (int i = 0; i < n; i++) {
		if (i && s[i-1] > k) break;
		int j = upper_bound(s+i+1, s+n, k + a[i]) - s;
		if (j - 1 > mx) {
			mx = j - 1;
			res = i + 1;
		}
	}

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