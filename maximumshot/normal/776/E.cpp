#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

ll const X = 100005;
ll const mod = inf + 7;

ll F[X];
ll G[X];
map< ll, ll > mf, mg;

ll f(ll n, bool fl = 1) {
    if(fl && n < X) return F[n];
    if(mf.count(n)) return mf[n];
    ll res = 1;
    ll nn = n;
    for(ll x = 2;x * x <= n;x++) {
        if(n % x) continue;
        ll value = 1;
        while(n % x == 0) {
            value *= x;
            n /= x;
        }
        res *= (value - value / x);
    }
    if(n > 1) {
        res *= (n - 1);
    }
    if(!fl) F[nn] = res;
    return mf[nn] = res;
}

ll g(ll n, bool fl = 1) {
    if(fl && n < X) return G[n];
    if(mg.count(n)) return mg[n];
    ll res = 0;
    ll nn = n;
    for(ll d = 1;d * d <= n;d++) {
        if(n % d) continue;
        res += f(d);
        if(d * d != n) {
            res += f(n / d);
        }
    }
    if(!fl) G[nn] = res;
    return mg[nn] = res;
}

int main() {

    for(int i = 1;i < X;i++) {
        f(i, 0);
        g(i, 0);
    }

    ll n, k;

    cin >> n >> k;

    ll cur = g(n);

    for(ll kk = 1;kk <= k && cur > 1;kk++) {
        if(kk % 2) {
            cur = f(cur);
        }else
            cur = g(cur);
    }

    cout << cur % mod << "\n";

    return 0;
}