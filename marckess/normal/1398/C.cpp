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

const int MX = 100005;
string s;
int n, a[MX];
map<int, int> mp;

void solve () {
	mp.clear();

	cin >> n >> s;
	forn (i, n) a[i] = s[i] - int('0') - 1;

	mp[0] = 1;

	int acu = 0;
	ll res = 0;
	forn (i, n) {
		acu += a[i];
		res += mp[acu];
		mp[acu]++;
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