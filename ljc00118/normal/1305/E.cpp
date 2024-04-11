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

const int N = 5005, INF = 1e9;

int n, m, mx;

int main() {
    read(n); read(m);
    for (int i = 1; i <= n; i++) mx += (i - 1) / 2;
    if (mx < m) {
        print(-1, '\n');
        return 0;
    }
    if (mx == m) {
        for (int i = 1; i <= n; i++) print(i, i == n ? '\n' : ' ');
        return 0;
    }
    for (int i = n; i >= 1; i--) {
        if (mx - (i - 1) / 2 <= m) {
            for (int j = 1; j < i; j++) print(j, ' ');
            print(i + (mx - m) * 2, ' ');
            for (int j = i + 1; j <= n; j++) print(INF - (n - j) * 10000, ' ');
            return 0;
        }
        mx -= (i - 1) / 2;
    }
    return 0;
}