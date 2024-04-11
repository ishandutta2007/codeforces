#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) (((n % k) + k ) % k)

vvi matMul (vvi &a, vvi &b, ll m) {
    vvi res(a.size(), vi(b.size()));

    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[0].size(); j++){
            for (int k = 0; k < b.size(); k++)
                res[i][j] += (a[i][k] * b[k][j]) % m;
            res[i][j] %= m;
        }

    return res;
}

vvi matPot (vvi b, ll p, ll m) {
    vvi res = {{1, 0}, {0, 1}};

    while (p) {
        if (p & 1)
            res = matMul (res, b, m);
        b = matMul(b, b, m);
        p >>= 1;
    }

    return res;
}

ll pot (ll b, ll p, ll m) {
    ll res = 1;

    while (p) {
        if (p & 1)
            res = (res * b) % m;
        b = (b * b) % m;
        p >>= 1;
    }

    return res;
}

ll n, k, l, m;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> l >> m;
    vvi fib = {{1, 1}, {1, 0}};

    if (l == 0 && k == 0) {
        cout << 1 % m << endl;
        return 0;
    }

    if (l < 63 && (1LL << l) <= k) {
        cout << 0 << endl;
        return 0;
    }

    vi res(65);

    for (ll i = 0; i < l; i++)
        if (i < 63 && (k & (1LL << i))) 
            res[i] = MOD(pot(2, n, m) - matPot(fib, n+1, m)[0][0], m);
        else
            res[i] = matPot(fib, n+1, m)[0][0];

    ll sum = 1;
    for (int i = 0; i < l; i++) 
        sum = (sum * res[i]) % m;

    cout << sum << endl;

    return 0;
}