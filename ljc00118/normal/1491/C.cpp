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

const int N = 5005;

int a[N], f[N];
int T, n; ll ans;

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            f[i] = i;
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
                f[i] = i + 1;
            }
        }
        f[n + 1] = n + 1;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] >= n - i + 1) {
                ans += a[i] - (n - i + 1);
                a[i] = n - i + 1;
            }
            while (a[i] > 1) {
                ++ans;
                int pos = i;
                while (pos <= n) {
                    --a[pos];
                    if (a[pos] == 1) f[pos] = find(pos + 1);
                    if (pos + a[pos] + 1 > n) break;
                    pos = find(pos + a[pos] + 1);
                }
            }
        }
        print(ans, '\n');
    }
    return 0;
}