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

double t1[N], t2[N];
int a[N];
int T, n, l;

int main() {
    read(T);
    while (T--) {
        read(n); read(l);
        for (int i = 1; i <= n; i++) read(a[i]);
        a[n + 1] = l; t2[n + 1] = 0;
        for (int i = 1; i <= n + 1; i++) t1[i] = t1[i - 1] + (double)(a[i] - a[i - 1]) / i;
        for (int i = n; i >= 0; i--) t2[i] = t2[i + 1] + (double)(a[i + 1] - a[i]) / (n - i + 1);
        for (int i = 1; i <= n + 1; i++) {
            if (t1[i] >= t2[i]) {
                if (t1[i - 1] <= t2[i]) printf("%.10lf\n", t2[i] + (a[i] - a[i - 1] - (t2[i] - t1[i - 1]) * i) / (n + 2));
                else printf("%.10lf\n", t1[i - 1] + (a[i] - a[i - 1] - (t1[i - 1] - t2[i]) * (n - i + 2)) / (n + 2));
                break;
            }
        }
    }
    return 0;
}