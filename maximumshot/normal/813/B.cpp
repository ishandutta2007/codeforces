#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

vec< ll > getpw(ll x) {
    vec< ll > pwx(100, inf64 + 1);
    pwx[0] = 1;
    {
        double cur = 1.0;
        for(int i = 1;i < 100;i++) {
            cur *= (double)x;
            if(cur > 1e18 + 100) break;
            pwx[i] = pwx[i - 1] * x;
        }
    }
    return pwx;
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    ll x, y, l, r;

    cin >> x >> y >> l >> r;

    vec< ll > pwx = getpw(x);
    vec< ll > pwy = getpw(y);

    set< ll > q;

    q.insert(-1);

    for(int i = 0;i < 100;i++) {
        for(int j = 0;j < 100;j++) {
            q.insert(pwx[i] + pwy[j]);
        }
    }

    ll result = 0;

    set< ll > :: iterator ptr, nxt;

    ptr = q.begin();

    while(1) {
        nxt = ptr;
        nxt++;
        if(nxt == q.end()) break;
        ll t1, t2;
        t1 = *ptr + 1;
        t2 = *nxt - 1;
        if(t1 > t2) {
            ptr++;
            continue;
        }
        ll ql, qr;
        ql = max(t1, l);
        qr = min(t2, r);
        if(ql <= qr) {
            result = max(result, qr - ql + 1);
        }
        ptr++;
    }

    cout << result << "\n";

    return 0;
}