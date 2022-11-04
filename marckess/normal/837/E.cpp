#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vector<ll> v;

void fac (ll n) {
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            v.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 1)
        v.push_back(n);
}

ll gcd (ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll f (ll a, ll b) {
    ll d = gcd(a, b);
    a /= d;
    b /= d;

    if (a == 1)
        return b;

    ll s = 1e18;
    for (ll x : v)
        if (a % x == 0)
            s = min(b % x, s);

    return s + f(a, b - s);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll a, b;
    cin >> a >> b;

    fac(a);
    cout << f(a, b) << endl;

    return 0;
}