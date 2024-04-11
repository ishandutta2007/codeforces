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

const int N = 1e5 + 5;

int a[N], b[N];
int T, n;

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]);
        b[1] = a[1]; b[n + 1] = a[n];
        for (int i = 2; i <= n; i++) {
            b[i] = a[i] * a[i - 1] / __gcd(a[i], a[i - 1]);
        }
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            if (__gcd(b[i], b[i + 1]) != a[i]) {
                ans = 0;
                break;
            }
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}