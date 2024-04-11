#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

struct RangeTree {
    int n; // 1 .. n;
    vector< ll > t;

    void build(int v, int tl, int tr, const vector< ll > &a) {
        if(tl == tr) {
            t[v] = a[tl];
        }else {
            int tm = (tl + tr) >> 1;
            build(v << 1, tl, tm, a);
            build(v << 1 | 1, tm + 1, tr, a);
            t[v] = max(t[v << 1], t[v << 1 | 1]);
        }
    }

    RangeTree(const vector< ll > & a, int _n): n(_n)
    {
        t.resize(4 * n, -inf64);
        build(1, 1, n, a);
    }

    ll get_max(int v, int tl, int tr, int l, int r) const {
        if(l <= tl && tr <= r) {
            return t[v];
        }else {
            int tm = (tl + tr) >> 1;
            ll res = -inf64;
            if(l <= tm) {
                res = max(res, get_max(v << 1, tl, tm, l, r));
            }
            if(r > tm) {
                res = max(res, get_max(v << 1 | 1, tm + 1, tr, l, r));
            }
            return res;
        }
    }

    ll get_max(int l, int r) const {
        return get_max(1, 1, n, l, r);
    }
};

const int N = 5e5 + 5;

int n;
int d[N];
ll pref[N];
ll suff[N];
ll suff2[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    int r = 0;
    for(int i = 1;i <= n;i++) {
        scanf("%d", &d[i]);
        r += d[i];
        r &= 1;
    }

    sort(d + 1, d + n + 1);
    reverse(d + 1, d + n + 1);

    for(int i = 1;i <= n;i++) {
        pref[i] = pref[i - 1] + d[i];
    }

    {
        multiset< int > Q;
        int tot_cnt = 0;
        ll  tot_sum = 0;
        for(int i = n;i >= 1;i--) {
            while(!Q.empty() && *(--Q.end()) > i) {
                tot_cnt--;
                tot_sum -= *(--Q.end());
                Q.erase(--Q.end());
            }
            suff[i] = tot_sum + 1ll * (n - i - tot_cnt) * i;
            tot_cnt++;
            tot_sum += d[i];
            Q.insert(d[i]);
        }
    }

    {
        multiset< int > Q;
        int tot_cnt = 0;
        ll  tot_sum = 0;
        for(int i = n;i >= 1;i--) {
            while(!Q.empty() && *(--Q.end()) > i + 1) {
                tot_cnt--;
                tot_sum -= *(--Q.end());
                Q.erase(--Q.end());
            }
            suff2[i] = tot_sum + 1ll * (n - i - tot_cnt) * (i + 1);
            tot_cnt++;
            tot_sum += d[i];
            Q.insert(d[i]);
        }
    }

    vector< int > result;

    vector< ll > value(n + 10);

    for(int i = 1;i <= n;i++) {
        value[i] = pref[i] - suff2[i] - 1ll * i * (i + 1);
    }

    for(int i = n - 2;i >= 1;i--) {
        value[i] = max(value[i], value[i + 1]);
    }

    vector< ll > value2(n + 10), value3(n + 10);

    for(int i = 1;i <= n;i++) {
        value2[i] = pref[i] - suff[i] - 1ll * i * (i - 1) - i;
        value3[i] = pref[i] - suff[i] - 1ll * i * (i - 1);
    }

    RangeTree rt2(value2, n), rt3(value3, n);

    for(int i = 1;i <= n + 1;i++) {
        if(i > 1 && d[i - 1] == d[i]) continue;
        int L = i == n + 1 ? 0 : d[i];
        int R = i == 1     ? n : d[i - 1] - 1;
        for(int x = L;x <= R;x++) {
            if((x & 1) != r) continue;

            int ok = 1;

//            for(int k = i;k < n;k++) {
//                ok &= (pref[k] - suff2[k] - 1ll * k * (k + 1) + x <= 0);
//            }

            if(i < n) ok &= (value[i] + x <= 0);

            if(i <= n) {
                ok &= (pref[i - 1] + x - suff[i] - min(d[i], i) - 1ll * i * (i - 1) <= 0);
            }

//            for(int k = 1;k < i;k++) {
//                ok &= (pref[k] - suff[k] - 1ll * k * (k - 1) - min(k, x) <= 0);
//            }

            int l1 = 1;
            int r1 = min(i - 1, x);
            int l2 = max(x + 1, 1);
            int r2 = i - 1;

            if(l1 <= r1)
                ok &= (rt2.get_max(l1, r1) <= 0);

//            for(int k = l1;k <= r1;k++) {
////                ok &= (pref[k] - suff[k] - 1ll * k * (k - 1) - k <= 0);
//                ok &= (value2[k] <= 0);
//            }

            if(l2 <= r2)
                ok &= (rt3.get_max(l2, r2) - x <= 0);

//            for(int k = l2;k <= r2;k++) {
////                ok &= (pref[k] - suff[k] - 1ll * k * (k - 1) - x <= 0);
//                ok &= (value3[k] - x <= 0);
//            }

            if(ok) {
                result.push_back(x);
            }
        }
    }

    sort(result.begin(), result.end());

    if(result.empty()) {
        puts("-1");
        return 0;
    }

    for(int x : result) {
        printf("%d ", x);
    }

    printf("\n");

    return 0;
}