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

const int N = 4e5 + 5;

int f[N], a[N];
int n, k, maxn;

void add(int x, int y) {
    if (x <= n * 2) f[x] += y;
}

int main() {
    read(n); read(k);
    for (int i = 1; i <= n; i++) read(a[i]);
    sort(a + 1, a + n + 1); reverse(a + 1, a + n + 1);
    int l = 1, r = 1000000000 + n * 2, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        memset(f, 0, sizeof(f));
        add(1, 1); add(2, -1);
        ll cnt = 1;
        int mi = 1, now = 1;
        for (int i = 1; i <= n; i++) {
            if (cnt >= k) break;
            while (now == 0) {
                ++mi;
                now += f[mi];
            }
            auto add = [&](int l, int r, int val) {
                if (l > mid) return;
                cnt += (min(r, mid) - l + 1) * val;
                ::add(l, val); ::add(r + 1, -val);
            };
            add(mi, mi, -1); --now;
            add(mi + 2, mi + (a[i] - 1) / 2 + 1, 1);
            add(mi + 2, mi + (a[i] - 1) / 2 + (a[i] % 2 == 0) + 1, 1);
        }
        if (cnt >= k) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    if (ans == -1) print(-1, '\n');
    else print(ans - 1, '\n');
    return 0;
}