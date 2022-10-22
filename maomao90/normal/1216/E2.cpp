// time-limit: 2000
// problem-url: https://codeforces.com/contest/1216/problem/E2

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

#define INF 1000000005
#define LINF 1000000000000000005ll
#define MAXN 200000000
#define MAXL 19

int q;
ll pw[MAXL], pw2[MAXL];
ll k;

int len(ll x) {
    int res = 0;
    while (x) {
        x /= 10;
        res++;
    }
    return res;
}

ll cnt(ll x) {
    ll rk = LINF;
    RREP (k, 18, 0) {
        if (x < pw[k]) continue;
        ll cnt = x - pw[k] + 1;
        ll tmp = cnt * pw2[k];
        if (pw2[k] != 0 && cnt > LINF / pw2[k]) {
            tmp = LINF;
        }
        rk -= tmp;
        mxto(rk, 0ll);
        tmp = cnt * (cnt + 1) / 2 * (k + 1);
        if (cnt / 2 > LINF / (cnt + 1)) {
            tmp = LINF;
        } else if (cnt * (cnt + 1) / 2 > LINF / (k + 1)) {
            tmp = LINF;
        }
        rk -= tmp;
        mxto(rk, 0ll);
        x = pw[k] - 1;
    }
    return LINF - rk;
}

bool isPos(ll x) {
    return k <= cnt(x);
}

ll cnt2(ll x) {
    ll res = 0;
    RREP (k, MAXL - 1, 0) {
        if (x < pw[k]) continue;
        ll cnt = x - pw[k] + 1;
        ll tmp = cnt * (k + 1);
        if (cnt > LINF / (k + 1)) {
            tmp = LINF;
        }
        res += tmp;
        x = pw[k] - 1;
    }
    return res;
}

bool isPos2(ll x) {
    return k <= cnt2(x);
}

int main() {
    pw[0] = 1;
    REP (i, 1, MAXL) {
        pw[i] = pw[i - 1] * 10;
    }
    REP (i, 1, MAXL - 1) {
        pw2[i] = pw2[i - 1];
        ll tmp = (pw[i] - pw[i - 1]) * i;
        if (pw[i] - pw[i - 1] > LINF / i) {
            tmp = LINF;
        }
        pw2[i] += tmp;
        mnto(pw2[i], LINF);
    }
    cin >> q;
    while (q--) {
        cin >> k;
        ll lo = 1, hi = LINF, mid;
        while (lo < hi) {
            mid = lo + hi >> 1;
            if (isPos(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        cerr << hi << ' ' << cnt(hi - 1) << '\n';
        k -= cnt(hi - 1);
        lo = 1, hi = LINF;
        while (lo < hi) {
            mid = lo + hi >> 1;
            if (isPos2(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        cerr << ' ' << hi << ' ' << cnt2(hi - 1) << '\n';
        k -= cnt2(hi - 1);
        cerr << "  " << k << '\n';
        int j = -1;
        RREP (k, MAXL - 1, 0) {
            if (hi < pw[k]) continue;
            j = k;
            break;
        }
        int ans = hi % pw[j - k + 2] / pw[j - k + 1];
        cout << ans << '\n';
    }
}