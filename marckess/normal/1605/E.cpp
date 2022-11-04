
// Problem : E. Array Equalizer
// Contest : Codeforces - Codeforces Round #754 (Div. 2)
// URL : https://codeforces.com/contest/1605/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005, MA = 1000005;
int n, q, a[MX], b[MX];
vi pos[MA];
ii d[MX];
ll res[MA];

void main_() {
	cin >> n;
	forn (i, n) cin >> a[i + 1];
	forn (i, n) cin >> b[i + 1];
	
	d[1] = {-a[1], 1};
	for (int i = 2; i <= n; i++)
		d[i] = {b[i] - a[i], 0};
		
	for (int i = 1; i <= n; i++)
		for (int j = 2 * i; j <= n; j += i) {
			d[j].fi -= d[i].fi;
			d[j].se -= d[i].se;
		}
	
	for (int i = 1; i <= n; i++)
		if (d[i].se < 0) {
			d[i].fi *= -1;
			d[i].se *= -1;
		} 
	
	ll acu = 0, dec = 0, inc = 0;
	for (int i = 1; i <= n; i++) {
		acu += abs(d[i].fi);
		
		if (d[i].fi >= 0) {
			inc += d[i].se;
		} else if (d[i].se) {
			dec += d[i].se;
			
			ll p = abs(d[i].fi) / d[i].se;
			if (p < MA)
				pos[p].pb(i);
		}
	}
	
	forn (i, MA) {
		res[i] = acu;
		
		for (int j : pos[i]) {
			dec -= d[j].se;
			
			acu -= abs(d[j].fi + d[j].se * i);
			acu += abs(d[j].fi + d[j].se * (i + 1));
		}
		
		acu -= dec;
		acu += inc;
		
		for (int j : pos[i])
			inc += d[j].se;
	}
	
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		cout << res[x] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}