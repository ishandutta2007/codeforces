#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

const int N = 5e5 + 5;

int a[N], f[N], v1[N], v2[N], val[N];
int T, n;

void add(int x, int y) {
    while (x <= n) {
        f[x] += y;
        x += (x & -x);
    }
}

int query(int x) {
    int ans = 0;
    while (x) {
        ans += f[x];
        x &= (x - 1);
    }
    return ans;
}

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]), f[i] = 0;
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            add(a[i], 1);
            v1[i] = i - query(a[i]);
            ans += v1[i];
            v2[i] = a[i] - (i - v1[i]);
            val[i] = 2 * v2[i] - 2 * v1[i] + i;
        }
        sort(val + 1, val + n + 1);
        print(ans, ' ');
        for (int i = 1; i <= n; i++) {
            ans += val[i] - i;
            print(ans, i == n ? '\n' : ' ');
        }
    }
    return 0;
}