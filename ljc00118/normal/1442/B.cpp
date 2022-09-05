#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5, md = 998244353;

set <int> all;
int a[N], b[N], pre[N], t[N];
int T, n, k, ans;

int main() {
    read(T);
    while (T--) {
        read(n); read(k); all.clear();
        for (int i = 1; i <= n; i++) read(a[i]), pre[a[i]] = i, t[i] = 0, all.insert(i);
        for (int i = 1; i <= k; i++) read(b[i]), t[pre[b[i]]] = i;
        ans = 1;
        for (int i = 1; i <= k; i++) {
            int x = pre[b[i]], l = 0, r = 0;
            auto it = all.upper_bound(x);
            if (it != all.end() && t[*it] < i) r = *it;
            --it;
            if (it != all.begin()) {
                --it;
                if (t[*it] < i) l = *it;
            }
            if (!l && !r) {
                ans = 0;
                break;
            }
            ans = ans * ((l > 0) + (r > 0)) % md;
            if (l) all.erase(l);
            else all.erase(r);
        }
        print(ans, '\n');
    }
    return 0;
}