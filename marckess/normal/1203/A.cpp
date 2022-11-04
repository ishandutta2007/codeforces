#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int q;
	cin >> q;
	while (q--) {
	    int n, f = 0;
	    cin >> n;
	    vi a(n), b(n), c(n);
	    iota(all(b), 1);
	    c = b;
	    reverse(all(c));
	    forn(i, n) cin >> a[i];
	    for (int i = 0; i < n; i++) {
	        if (a == b || a == c) f = 1;
	        a.pb(a.front());
	        a.erase(a.begin());
	    }
	    if (f) cout << "YES" << endl;
	    else cout << "NO" << endl;
	}
 
	return 0;
}