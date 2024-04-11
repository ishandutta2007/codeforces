/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

typedef unsigned long long mask_t;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const mask_t ONE = (mask_t)1;

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

mask_t mask_for(char c) {
    switch (c) {
        case 'A':
            return 0;
        case 'T':
            return 1;
        case 'G':
            return 2;
        case 'C':
            return 3;
    }

    return 100;
}

inline constexpr mask_t full(int len) {
    return (ONE << len) - ONE;
}

inline mask_t rotate(mask_t mask, int len, int shift) {
    shift = len - shift;
    mask_t up = full(shift) << (len - shift);
    mask_t down = full(len) ^ up;

    return ((mask & up) >> (len - shift)) | ((mask & down) << shift);
}

mask_t populate(char* buf, int& mlen) {
    mlen = 0;
    int l = strlen(buf);
    mask_t res = 0;
    while (mlen + 2 * l < 64) {
        for (int i = 0; i < l; i++) {
            res |= mask_for(buf[i]) << mlen;
            mlen += 2;
        }
    }

    return res;
}

int n;
char s[MAXN];
mask_t mem[MAXN / 32 + 1000];
char cnt[1 << 16];
char buf[20];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cnt[0] = 0;
    for (int i = 1; i < (1 << 16); i++) {
        cnt[i] = cnt[i >> 2] + ((i & 3) == 3);
    }

    gets(s);
    n = strlen(s);

    for (int i = 0; i < n; i += 32) {
        for (int j = i; j < min(i + 32, n); j++) {
            mem[i >> 5] |= mask_for(s[j]) << ((j - i) * 2);
        }
    }

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int pos;
            char c;
            scanf("%d %c", &pos, &c);
            pos--;

            int idx = pos >> 5;
            int shift = (pos & full(5)) << 1;

            mem[idx] &= ~(3ull << shift);
            mem[idx] |= (mask_for(c) << shift);
        } else {
            int l, r;
            scanf("%d %d %s", &l, &r, buf);
            l--, r--;
            int mlen = 0;
            mask_t m = populate(buf, mlen);

            int ans = 0;

            auto single = [&](int l) {
                int idx = l >> 5;
                int shift = (l & full(5)) << 1;

                mask_t val = (mem[idx] >> shift) & 3ull;

                if (val == (m & 3)) {
                    ans++;
                }

                m = rotate(m, mlen, 2);
            };
            
            while (l <= r && (l & full(5))) {
                single(l++);
            }

            if (l <= r) {
            int idxl = l >> 5;
            int idxr = r >> 5;
            int steps = idxr - idxl;
            l += 32 * steps;
            auto memptr = mem + idxl;
            while (steps--) {
                mask_t tmask = m | ((m & full(64 - mlen)) << mlen);
                m = rotate(m, mlen, 64 - mlen);
                mask_t xored = ~(tmask ^ *memptr++);
                ans += cnt[xored & full(16)] + cnt[(xored >> 16) & full(16)] + cnt[(xored >> 32) & full(16)] + cnt[xored >> 48];
            }

            while (l <= r) {
                single(l++);
            }
            }

            printf("%d\n", ans);
        }
    }

    return 0;
}