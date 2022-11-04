#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forab(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int mx = 100005, mod = 1e9+7;
int n, m, q = 0, res[mx], inv[mx], s, op;
vii pos[mx];
string str;

ll pot (ll b, ll p) {
    ll res = 1;
    b %= mod;
    
    while (p) {
        if (p&1) res = res * b % mod;
        b = b * b % mod;
        p /= 2;
    }
    
    return res;
}

void solve (int j) {
    ll c = 1, acu = 0, a = 1;
    vii &v = pos[j];
    int n = v.size();
    
    for (int i = j, k = 0; k < n; i++) {
        acu *= 26;
        acu += c * a;
        acu %= mod;
        
        while (k < n && v[k].fi == i)
            res[v[k++].se] = acu;
        
        a = a * 25 % mod;
        c *= ll(i) * inv[i+1-j] % mod;
        c %= mod;
    }
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	forn(i,mx) inv[i] = pot(i,mod-2);
	
	cin >> m >> str;
	s = str.size();
	
	while (m--) {
	    cin >> op;
	    if (op == 1) {
	        cin >> str;
	        s = str.size();
	    } else {
	        cin >> n;
	        if (n >= s) 
	            pos[s].emplace_back(n, q);
	        q++;
	    }
	}
	
	forn(i, mx) {
	    sort(ALL(pos[i]));
	    solve(i);
	}
	
	forn(i, q)
	    cout << res[i] << endl;

	return 0;
}