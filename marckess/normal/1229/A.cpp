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

const int MX = 7007;
int n, b[MX];
map<ll, int> mp;
ll res, a[MX];
vl v;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	for (int i = 0; i < n; i++)
		cin >> b[i];

	for (int i = 0; i < n; i++)
		if (mp[a[i]] > 1) {
			res += b[i];
			v.pb(a[i]);
		}

	for (int i = 0; i < n; i++)
		if (mp[a[i]] == 1) {
			int f = 0;
			for (int j = 0; j < v.size(); j++)
				f |= (v[j] & a[i]) == a[i];
			if (f)
				res += b[i];
		}

	cout << res << endl;

	return 0;
}