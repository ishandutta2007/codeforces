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

int v1[N], v2[N];
int T, n, l1, l2;

int main() {
    read(T);
    while (T--) {
        read(n);
        l1 = l2 = 0;
        for (int i = 1; i <= n * 2; i++) {
            int x, y;
            read(x); read(y);
            if (x == 0) v1[++l1] = abs(y);
            else v2[++l2] = abs(x);
        }
        double ans = 0;
        sort(v1 + 1, v1 + n + 1); sort(v2 + 1, v2 + n + 1);
        for (int i = 1; i <= n; i++) ans += sqrt(1ll * v1[i] * v1[i] + 1ll * v2[i] * v2[i]);
        printf("%.10lf\n", ans);
    }
    return 0;
}