#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int N = 1e5 + 5;
const int LOG = 20;

int n;
int a[N];
int rr[LOG][N];
ll cnt[N];
vector< pair< int, ll > > ar;
vector< ll > pref_sum, pref_cnt;
int sz;

ll f(ll T, ll k) {
    ll cnt = T / k;
    return T * cnt - k * cnt * (cnt + 1) / 2;
}

ll count_triangle(ll A, ll B, ll C) {
    if(A + B > C) return 0;
//    ll res = 0;
//    for(ll x = 1;A * x <= C;x++) {
//        res += (C - A * x) / B;
//    }
//    return res;
    if(A > B) swap(A, B);
    ll k = B / A;
    return f(k * C / B, k) + count_triangle(A, B - A * k, C - A * (k * C / B));
//    return 0;
}

ll count_solutions(ll A, ll B, ll C, ll cx, ll cy) {
    assert(A > 0);
    assert(B > 0);
    if(C <= 0 || cx <= 0 || cy <= 0) return 0;
    if(A * cx + B * cy <= C) return cx * cy;
    if(cx >= C / A && cy >= C / B) return count_triangle(A, B, C);
    return count_triangle(A, B, C) - count_triangle(A, B, C - B * cy) - count_triangle(A, B, C - A * cx);
}

ll count_leq(ll x) {
    ll res = 0;
    for(pair< int, ll > p : ar) {
        if(p.first > x) continue;
        ll L = x / p.first;
        L = min(L, p.second);
        res += L * (p.second + 1) - L * (L + 1) / 2;
    }
    for(int j = 0, i = 1;i < (int)ar.size();i++) {
        while(pref_sum[i - 1] - pref_sum[j] > x) j++;
        while(j < i && pref_sum[i] - (j ? pref_sum[j - 1] : 0ll) > x) {
            ll S0 = pref_sum[i - 1] - pref_sum[j];
            ll A = ar[j].first;
            ll B = ar[i].first;
            ll C = x - S0;
            res += count_solutions(A, B, C, ar[j].second, ar[i].second);
            j++;
        }
        if(j < i) {
            res += ar[i].second * (pref_cnt[i - 1] - (j ? pref_cnt[j - 1] : 0ll));
        }
        j = max(0, j - 1);
    }
    return res;
}

ll slow_count_leq(ll x) {
    ll res = 0;
    vector< int > arr;
    for(pair< int, ll > p : ar) {
        for(int j = 0;j < p.second;j++) arr.push_back(p.first);
    }
    for(int l = 0;l < (int)arr.size();l++) {
        ll cur = 0;
        for(int r = l;r < (int)arr.size();r++) {
            cur += arr[r];
            if(cur > x) break;
            res++;
        }
    }
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

//#define TEST

#ifndef TEST
    cin >> n;
#else
    mt19937 rnd(time(NULL));
    n = rnd() % 100 + 1;
#endif

    for(int i = 1;i <= n;i++) {
#ifndef TEST
        cin >> a[i];
#else
        a[i] = rnd() % 20 + 1;
#endif
        rr[0][i] = a[i];
    }

    for(int j = 1;j < LOG;j++) {
        for(int i = 1;i + (1 << j) - 1 <= n;i++) {
            rr[j][i] = __gcd(rr[j - 1][i], rr[j - 1][i + (1 << (j - 1))]);
        }
    }

    for(int l = 1;l <= n;l++) {
        int r = l;
        int cur_gcd = a[l];
        int last_r = l - 1;
        while(r <= n) {
            for(int j = LOG - 1;j >= 0;j--) {
                if(r + (1 << j) > n) continue;
                if(rr[j][r + 1] % cur_gcd) continue;
                r += (1 << j);
            }

            cnt[cur_gcd] += r - last_r;
            if(r == n) break;
            last_r = r;
            r++;
            cur_gcd = __gcd(cur_gcd, a[r]);
        }
    }

    ar.reserve(N);

    for(int x = 0;x < N;x++) {
        if(!cnt[x]) continue;
        ar.push_back({x, cnt[x]});
    }

    sz = (int)ar.size();

    pref_sum.resize(sz);
    pref_cnt.resize(sz);

    for(int i = 0;i < sz;i++) {
        if(i) {
            pref_sum[i] = pref_sum[i - 1];
            pref_cnt[i] = pref_cnt[i - 1];
        }
        pref_sum[i] += ar[i].first * ar[i].second;
        pref_cnt[i] += ar[i].second;
    }

    ll bsize = 1ll * n * (n + 1) / 2;
    ll csize = 1ll * bsize * (bsize + 1) / 2;
    ll med   = (csize + 1) / 2;

//    cout << count_leq(6) << ", med = " << med << "\n";

//    return 0;

    ll bl = 0;
    ll br = inf64;
    ll bm;

    while(br - bl > 1) {
        bm = (bl + br) / 2;
//        cout << bl << " .. " << br << "\n";
        if(count_leq(bm) < med) {
            bl = bm;
        }else {
            br = bm;
        }
    }

#ifndef TEST
    cout << br << "\n";
#else
    ll fs = br;
    bl = 0;
    bl = inf64;
    while(br - bl > 1) {
        bm = (bl + br) / 2;
        if(slow_count_leq(bm) < med) {
            bl = bm;
        }else {
            br = bm;
        }
    }
    ll sl = br;
    if(sl == fs) {
        cout << "OK (" << fs << " == " << sl << ")\n";
    }else {
        cout << "WA!\n";
        cout << n << "\n";
        for(int i = 1;i <= n;i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
        cout << "expected = " << sl << "\n";
        cout << "found    = " << fs << "\n";
    }
#endif

    return 0;
}