#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
    x = 0; register char c = getchar(); register bool f = 0;
    while (!isdigit(c)) f ^= c == '-', c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (f) x = -x;
}

template < class T >
inline void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
    print(x), putchar(c);
}

const int N = 2e5 + 10;
int n, m, l, r, mid;
int a[N], cnt[N];
std::vector < int > now, ans;

bool check(int x) {
    // printf("check %d\n", x);
    now.clear();
    for (int i = 1; i <= 2e5; i++)
        for (int j = 1; j <= cnt[i] / x; j++) {
            now.push_back(i);
            // printf(">>> %d\n", i);
            if (m == (int)now.size())
                return true;
        }
    return false;
}

void main() {
    read(n), read(m);
    for (int i = 1; i <= n; i++) read(a[i]), ++cnt[a[i]];
    for (int i = 1; i <= m; i++) ans.push_back(a[i]);
    l = 1, r = n;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1, ans = now;
        else r = mid - 1;
    }
    for (int i = 1; i <= m; i++) print(ans[i - 1], " \n"[i == m]);
}

} signed main() { return ringo::main(), 0; }