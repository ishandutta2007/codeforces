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

int x;

void solve () {
	cin >> x;
	ll res = 1e18;
	
	forn (i, (1 << 9)) {
		if (!i) continue;
		
		string t; 
		ll s = 0;
		
		forn (j, 9)
			if (i & (1 << j)) {
				t.pb('1' + j);
				s += 1 + j;
			}
		
		if (t.size() && s == x)
			res = min(res, stoll(t));
	} 
	
	if (res == 1e18) cout << -1 << endl;
	else cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	
	
	return 0;
}