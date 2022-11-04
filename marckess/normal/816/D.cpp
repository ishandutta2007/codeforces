#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

const int mxN = 2e5+5;
ll n, a[mxN], fac[mxN], ifac[mxN], M = 1e9+7;

ll potMod (ll n, ll exp, ll mod) {
    ll pot = 1, acu = n;
    while ( exp ) {
        if ( exp & 1 ) {
            pot *= acu;
            pot %= mod;
        }
        acu *= acu;
        acu %= mod;
        exp >>= 1;
    }
    return pot;
}

void precal() {
    fac[0] = ifac[0] = 1;
    for (ll n = 1; n <= 2e5; n++) {
        fac[n] = (n * fac[n-1]) % M;
        ifac[n] = potMod (fac[n], M-2, M);
    }
}

ll nCr (ll n, ll r) {
    return (((fac[n] * ifac[r]) % M) * ifac[n-r]) % M;
}

ll obtRes () {
    //Si hay un numero impar de elementos en a;
    if ( n & 1 ){
        ll aux = 0;
        bool f = true;
        for (int i = n-1; i >= 0; i--) {
            a[i] += aux * (f ? 1 : -1);
            aux = a[i] - aux * (f ? 1 : -1);
            a[i] = MOD(a[i], M);
            aux = MOD(aux, M);
            f = !f;
        }
        n--;
    }

    ll x = 0, y = 0;
    for (int i = 0; i < n; i++){
        ll z = (a[i] *  nCr(n/2-1, i/2)) % M;
        if ( i & 1 )
            y = (y + z) % M;
        else
            x = (x + z) % M;
    }
    if ( (n * (n-1L) / 2L) & 1L )
        return MOD(x + y, M);
    else
        return MOD(x - y, M);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    precal();

    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    if ( n == 1 )
        cout << a[0] << endl;
    else
        cout << obtRes() << endl;

    return 0;
}