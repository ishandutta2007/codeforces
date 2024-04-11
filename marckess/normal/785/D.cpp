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

ll mod = 1e9 + 7, fac[200010];
string s;
ll aper[200010], cer[200010];

ll x, y;
ll extGCD (ll a, ll b) {
    if ( !a ) {
        x = 0;
        y = 1;
        return b;
    }
    ll d = extGCD(b % a, a);
    ll temp = x;
    x = y - (b / a) * x;
    y = temp;
    return d;
}

inline ll divMOD (ll a, ll b) {
    extGCD (b, mod);
    x = MOD(x, mod);
    return (a * x) % mod;
}

ll comb(ll n, ll k) {
    return divMOD(fac[n], (fac[n-k] * fac[k]) % mod);
}

void obtFac () {
    fac[0] = 1;
    for (ll i = 1; i < 200005; i++)
        fac[i] = (i * fac[i-1]) % mod;
}

void obtAper () {
    for (int i = 0, c = 0; s[i]; i++) {
        if ( s[i] == '(' )
            c++;
        aper[i] = c;
    }
}

void obtCer () {
    for (int i = s.size() - 1, c = 0; i >= 0; i-- ) {
        if ( s[i] == ')' )
            c++;
        cer[i] = c;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll res = 0;
    cin >> s;

    obtFac();
    obtAper();
    obtCer();

    for (int i = 0; s[i]; i++) {
        if ( s[i] != '(' || cer[i] == 0 )
            continue;
        res += comb(aper[i] + cer[i] - 1, aper[i]);
        res %= mod;
    }

    cout << res << endl;

    return 0;
}