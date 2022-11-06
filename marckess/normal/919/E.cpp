#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

ll a, b, p, x;

ll gcd (ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

ll pot (ll b, int p, int m) {
    if (p == 0)
        return b;
    
    ll res = 1;

    while (p) {
        if (p & 1) {
            res *= b;
            res %= m;
        }

        b *= b;
        b %= m;
        p /= 2;
    }

    return res;
}

int bn[1000005], an[1000005];
ll tb = 0, ta = 0;
int cn[1000005], tc;
ll acu;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> a >> b >> p >> x;
    fill (bn, bn+1000005, -1);
    fill (an, an+1000005, -1);
    fill (cn, cn+1000005, -1);

    while (1) {
        acu = b * pot (tb+1, p-2, p);
        acu %= p;

        if (bn[acu] != -1)
            break;

        bn[acu] = tb++;
    }

    acu = 1;
    while (1) {
        acu *= a;
        acu %= p;

        if (an[acu] != -1)
            break;

        an[acu] = ta++;
    }

    int d = gcd(ta, tb);
    ll res = 0;

    while (1) {
        acu = ta * ll(tc);
        acu %= tb;

        if (cn[acu] != -1)
            break;

        cn[acu] = tc++;
    }

    acu = 1;
    for (int i = 0; i < ta && i < x; i++) {
        acu *= a;
        acu %= p;

        if (bn[acu] != -1 && acu % d == bn[acu] % d) {
            ll e = cn[MOD(bn[acu] - i, tb)];

            if (i + e * ta + 1 > x)
                continue;

            res++;
            res += (x - i - e * ta - 1) / (ta * tb / d);
        }
    }

    cout << res << endl;

    return 0;
}