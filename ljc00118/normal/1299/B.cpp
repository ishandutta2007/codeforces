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

const int N = 1e5 + 5;

int x[N], y[N];
int n, s = 1, t = 1;

inline int calc(int x) { return (x - 1) % n + 1; }

int main() {
    read(n);
    if (n & 1) { printf("NO\n"); return 0; }
    for (int i = 1; i <= n; i++) read(x[i]), read(y[i]);
    for (int i = 2; i <= n; i++) {
        if (x[i] < x[s] || (x[i] == x[s] && y[i] < y[s])) s = i;
        if (x[i] > x[t] || (x[i] == x[t] && y[i] > y[t])) t = i;
    }
    if ((s + n / 2 - 1) % n + 1 != t) { printf("NO\n"); return 0; }
    for (int i = 1; i <= n / 2; i++) {
        if (x[calc(s + 1)] - x[s] != x[t] - x[calc(t + 1)]) { printf("NO\n"); return 0; }
        if (y[calc(s + 1)] - y[s] != y[t] - y[calc(t + 1)]) { printf("NO\n"); return 0; }
        s = calc(s + 1); t = calc(t + 1);
    }
    printf("YES\n");
    return 0;
}