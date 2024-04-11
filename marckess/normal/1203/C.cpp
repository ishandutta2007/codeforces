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
	
    int n;
    ll a, g = 0;
    cin >> n;
    while (n--) {
        cin >> a;
        g = __gcd(a, g);
    }
    ll res = 0;
    for (ll i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            res++;
            if (i * i < g) res++;
        }
    }
    cout << res << endl;
 
	return 0;
}