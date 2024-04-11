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

int a[233], f[233];
int T, d, m, len, ans;

int main() {
    read(T);
    while (T--) {
        read(d); read(m); ans = len = 0;
        for (int i = 0; ; i++) {
            if ((1 << i) > d) break;
            int r = min(d, (1 << (i + 1)) - 1);
            a[++len] = r - (1 << i) + 1;
        }
        for (int i = 1; i <= len; i++) {
            f[i] = a[i] % m;
            for (int j = 1; j < i; j++) {
                f[i] += 1ll * f[j] * a[i] % m;
                if (f[i] >= m) f[i] -= m;
            }
            ans += f[i];
            if (ans >= m) ans -= m;
        }
        print(ans, '\n');
    }
    return 0;
}