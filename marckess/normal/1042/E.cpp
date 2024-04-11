#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1005, mod = 998244353;

struct Mat {
	ll x, y, a, e[2];
	bool operator < (const Mat ot) const {
		return a < ot.a;
	}
	void init (int i, int j) {
		x = i, y = j;
		cin >> a;
	}
};

int n, m, x, y, l = 0, ult;
Mat v[MX*MX];
ll a[2], b[2], e[2];

ll pot (ll b, ll p) {
    ll res = 1;
    b %= mod;
    
    while (p) {
        if (p & 1) res = res * b % mod;
        b = b * b % mod;
        p /= 2;
    }
    
    return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	FORR(i, 1, n) FORR(j, 1, m) v[l++].init(i, j);
	cin >> x >> y;

	FOR(i, l) if (v[i].x == x && v[i].y == y) ult = v[i].a;
	sort(v, v+l);
	FOR(i, l) if (v[i].a == ult) {
		v[i].x = x, v[i].y = y;
		l = i+1;
	}

    int i = 0, j = 0;
    while (i < l) {
        while (v[j].a < v[i].a) {
            a[0] = (a[0] + v[j].x * v[j].x) % mod;
            a[1] = (a[1] + v[j].y * v[j].y) % mod;
            
            b[0] = (b[0] + v[j].x) % mod;
            b[1] = (b[1] + v[j].y) % mod;
            
            e[0] = (e[0] + v[j].e[0]) % mod;
            e[1] = (e[1] + v[j].e[1]) % mod;
            
            j++;
        }
        
        if (j) {
            ll inv = pot(j, mod-2);
            v[i].e[0] = (e[0] + a[0] - 2 * v[i].x * b[0] + v[i].x * v[i].x * j) % mod * inv % mod;
            v[i].e[1] = (e[1] + a[1] - 2 * v[i].y * b[1] + v[i].y * v[i].y * j) % mod * inv % mod;
        } else {
            v[i].e[0] = v[i].e[1] = 0;
        }
    
        i++;
    }
    
    cout << MOD(v[l-1].e[0] + v[l-1].e[1], mod) << endl;
    
	return 0;
}