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

int n;
string s;
vi v;
ll res;

void solve () {
	cin >> n >> s;
	
	v.clear();
	forn (i, n)
		if (s[i] == '*') {
			int sz = v.size();
			v.pb(i - sz);
		}
	
	if (!v.size()) {
		cout << 0 << endl;
		return;
	}
	
	res = 0;
	
	int m = v[(int)v.size() / 2];
	for (int x : v)
		res += abs(x - m);
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