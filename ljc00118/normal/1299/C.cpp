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

const double eps = 1e-10;
const int N = 1e6 + 5;

ll s[N];
int a[N], st[N];
int n, top;

inline double calc(int x) { return (double)(s[st[x]] - s[st[x - 1]]) / (st[x] - st[x - 1]); }

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), s[i] = s[i - 1] + a[i];
    st[++top] = 1;
    for (int i = 2; i <= n; i++) {
        st[++top] = i;
        while (top >= 2 && calc(top) <= calc(top - 1) + eps) --top, st[top] = i;
    }
    for (int i = 1; i <= top; i++) {
        double now = calc(i);
        for (int j = st[i - 1] + 1; j <= st[i]; j++) printf("%.9lf\n", now);
    }
    return 0;
}