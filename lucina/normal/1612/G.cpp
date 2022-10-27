#include<bits/stdc++.h>
using namespace std;
const int nax = 5e5 + 10;
const int64_t MOD = 1e9 + 7;
const int64_t INV2 = (MOD + 1) >> 1;
inline int64_t add(int64_t a, int64_t b) {
    return (a += b) >= MOD ? a - MOD : a;
}
inline int64_t sub(int64_t a, int64_t b) {
    return (a -= b) < 0 ? a + MOD : a;
}
inline int64_t mul(int64_t a, int64_t b) {
    return a * b % MOD;
}
int a[nax];
int n;
const int L = 1e6;
const int LN = L * 2 + nax;

inline int64_t sum(int64_t x) {
    return x * (x  + 1) % MOD;
}
inline int64_t sum(int64_t l, int64_t r) {
    return sub(sum(r), sum(l - 1)) * INV2 % MOD;
}

int in[L * 2 + 5];
int out[L * 2 + 5];
int fac[L + 5];


int main() {
cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            in[-a[i] + 1 + L] += 1;
            out[a[i] - 1 + L] += 1;
        } else {
            in[-a[i] + 1 + L] += 1;
            out[a[i] - 1 + L] += 1;
        }
    }

    fac[0] = 1;
    for (int i = 1 ; i < L ; ++ i) {
        fac[i] = mul(fac[i - 1], i);
    }
    int64_t ans_val = 0;
    int64_t ans_cnt = 1;
    int64_t cur_idx = 0;
    int keep_cnt[2]{};
    for (int s = -L + 1 ; s <= L - 1; ++ s) {
        int &cnt = keep_cnt[abs(s) % 2];
        cnt += in[s + L];
        if (cnt > 0) {
            int64_t start = cur_idx;
            int64_t ed = cur_idx + cnt - 1;
            int64_t v = sum(start % MOD, ed % MOD);
            ans_val += 1LL * s * v;
            ans_val %= MOD;
            if (ans_val < 0) ans_val += MOD;
            ans_cnt = mul(ans_cnt, fac[cnt]);
            cur_idx += cnt;
        }
        cnt -= out[s + L];
    }
    cout << ans_val << ' ' << ans_cnt << '\n';

    /**
        The above naive algorithm yield maximum value.
        We can actually do Scanline - like method to get value above,
        but while doing this. We need to maintain some DP-like things,
        To count number of arrays.
    */
}