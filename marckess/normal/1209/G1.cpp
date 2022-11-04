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

const int MX = 200005;
int n, q, a[MX], fin[MX], cn, mx, res;
map<int, int> mp; 

void solve () {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		fin[a[i]] = i; 
		mp[a[i]]++;
	}

	for (int i = 0, to = 0; i < n; i++) {
		to = max(to, fin[a[i]]);
		mx = max(mx, mp[a[i]]);
		cn++;

		if (i == to) {
			res += cn - mx;
			cn = mx = 0;
		}
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t; t = 1;
	while (t--)
		solve();	

	return 0;
}