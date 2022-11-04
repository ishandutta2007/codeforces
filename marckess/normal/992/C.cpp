#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int mod = 1'000'000'007;
ll x, k;

ll pot (ll b, ll p) {
    ll res = 1;
    b %= mod;

    while (p) {
        if (p & 1)
            res = res * b % mod;
        b = b * b % mod;
        p /= 2;
    }

    return res;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> x >> k;

    if (!x) {
        cout << 0 << endl;
        return 0;
    }

    ll y = pot(2, k);
    ll inv = pot(2, mod-2);
    ll a = x % mod * y % mod;
    ll b = (a - y) % mod;
    ll res = (a * (a + 1) % mod - b * (b + 1) % mod) % mod;

    cout << MOD((res * pot(inv, k)), mod) << endl;

    return 0;
}