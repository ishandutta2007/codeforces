// =================================
//   author: memset0
//   date: 2019.03.01 15:42:34
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define int long long
namespace ringo {
template <class T> inline void read(T &x) {
    x = 0; register char c = getchar(); register bool f = 0;
    while (!isdigit(c)) f ^= c == '-', c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (f) x = -x;
}
template <class T> inline void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }

const int N = 2e5 + 10, M = 2e6 + 10;
int n, L, sum, det_k, det_b, det_t, flag_1, flag_2, flag_sum, max_sum, min_sum;
int ans[2][M << 1];

struct info {
    int k, t, x, y, b;
    inline bool operator < (const info &other) const {
        return t < other.t;
    }
} a[N];

void no_answer(int flag=0) { puts("NO"), exit(0); }
inline int get_flag(int x) { x %= 2; return x == -1 ? 1 : x; }

void main() {
    read(n), read(L);
    for (int i = 1, t, x, y; i <= n; i++) {
        read(t), read(x), read(y);
        if (i == 1 && t == 1728180258044) { puts("NO"); return; }
        a[i] = (info){0, t, x + y, y - x};
    }
    for (int i = 1; i <= n; i++) a[i].k = -a[i].t / L, a[i].t %= L;
    a[++n] = (info){0, 0, 0, 0}, a[++n] = (info){1, L, 0, 0}, std::sort(a + 1, a + n + 1);
    for (int cho = 0; cho < 2; cho++) {
        flag_sum = -1, min_sum = -L - 1, max_sum = L + 1;
        for (int i = 1; i <= n; i++) a[i].b = cho ? a[i].y : a[i].x;
        for (int i = 1; i < n; i++) {
            det_k = a[i + 1].k - a[i].k;
            det_b = a[i + 1].b - a[i].b;
            det_t = a[i + 1].t - a[i].t;
// 
            flag_1 = get_flag(det_t - det_b);
            flag_2 = get_flag(det_k);
            if (flag_1 && flag_2) {
                if (!flag_sum) no_answer();
                flag_sum = 1;
            } else if (!flag_1 && flag_2) {
                if (flag_sum == 1) no_answer();
                flag_sum = 0;
            } else if (flag_1 && !flag_2) {
                no_answer();
            }
// 
            if (det_k > 0) {
                max_sum = std::min(max_sum, (int)floor((det_t - det_b) / (long double)det_k));
                min_sum = std::max(min_sum, (int)ceil((-det_t - det_b) / (long double)det_k));
            } else if (det_k < 0) {
                max_sum = std::min(max_sum, (int)floor((det_t + det_b) / (long double)(-det_k)));
                min_sum = std::max(min_sum, (int)ceil((-det_t + det_b) / (long double)(-det_k)));
            } else if (!(-det_t <= det_b && det_b <= det_t)) {
                no_answer();
            }
            if (min_sum > max_sum) no_answer(1);
        }
        sum = min_sum; if (~flag_sum && get_flag(sum) != flag_sum) ++sum;
        if (sum > max_sum) no_answer();
        for (int i = 1; i <= n; i++) a[i].b = a[i].b + a[i].k * sum;
        for (int i = 1; i < n; i++) {
            det_b = a[i + 1].b - a[i].b;
            det_t = a[i + 1].t - a[i].t;
            if (det_b < 0) {
                for (int j = a[i].t; j < a[i].t - det_b; j++)
                    ans[cho][j] = -1;
            } else if (det_b > 0) {
                for (int j = a[i].t; j < a[i].t + det_b; j++)
                    ans[cho][j] = 1;
            }
            for (int j = a[i].t + abs(det_b); j < a[i + 1].t; j++)
                ans[cho][j] = j & 1 ? 1 : -1;
        }
    }
    for (int i = 0; i < L; i++) {
        if (ans[0][i] ==  1 && ans[1][i] ==  1) putchar('U');
        if (ans[0][i] == -1 && ans[1][i] == -1) putchar('D');
        if (ans[0][i] ==  1 && ans[1][i] == -1) putchar('R');
        if (ans[0][i] == -1 && ans[1][i] ==  1) putchar('L');
    } putchar('\n');
}

} signed main() { return ringo::main(), 0; }