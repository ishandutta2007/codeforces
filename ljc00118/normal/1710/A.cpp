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

int a[N];
int T, n, m, k;

int main() {
    read(T);
    while (T--) {
        read(n); read(m); read(k);
        ll sum1 = 0, sum2 = 0;
        int ok1 = 0, ok2 = 0;
        for (int i = 1; i <= k; i++) {
            read(a[i]);
            int v1 = a[i] / n, v2 = a[i] / m;
            if (v1 >= 3) ok1 = 1;
            if (v1 >= 2) sum1 += v1;
            if (v2 >= 3) ok2 = 1;
            if (v2 >= 2) sum2 += v2;
        }
        int ans = 0;
        if (sum1 == m || (sum1 > m && (ok1 || (sum1 % 2 == m % 2)))) ans = 1;
        if (sum2 == n || (sum2 > n && (ok2 || (sum2 % 2 == n % 2)))) ans = 1;
        printf("%s\n", ans ? "Yes" : "No");
    }
    return 0;
}