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

const int N = 5e5 + 5, md = 1e9 + 7;

inline int add(int x, int y) {
    x += y;
    if (x >= md) x -= md;
    return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

ll a[N];
int cnt[64];
int T, n;

int main() {
    read(T);
    while (T--) {
        memset(cnt, 0, sizeof(cnt));
        read(n);
        for (int i = 1; i <= n; i++) {
            ll x; read(x); a[i] = x;
            for (int j = 0; j <= 59; j++) {
                if ((x >> j) & 1) {
                    ++cnt[j];
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int sum1 = 0, sum2 = 0;
            for (int j = 0; j <= 59; j++) {
                if ((a[i] >> j) & 1) {
                    sum1 = add(sum1, mul((1ll << j) % md, cnt[j]));
                    sum2 = add(sum2, mul((1ll << j) % md, n));
                } else {
                    sum2 = add(sum2, mul((1ll << j) % md, cnt[j]));
                }
            }
            ans = add(ans, mul(sum1, sum2));
        }
        print(ans, '\n');
    }
    return 0;
}