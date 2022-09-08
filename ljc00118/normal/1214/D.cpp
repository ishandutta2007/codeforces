#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e6 + 5;

int a[N], f[N], g[N];
int n, m;

inline int s(int x, int y) { return (x - 1) * m + y; }

int main() {
    read(n); read(m);
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= m; j++) {
            char c = getchar();
            while(c != '.' && c != '#') c = getchar();
            if(c == '.') a[s(i, j)] = 1;
        }
    }
    f[1] = 1;
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= m; j++) {
            if(f[s(i, j)]) {
                if(i != n && a[s(i + 1, j)]) f[s(i + 1, j)] = 1;
                if(j != m && a[s(i, j + 1)]) f[s(i, j + 1)] = 1;
            }
        }
    }
    g[n * m] = 1;
    for(register int i = n; i >= 1; i--) {
        for(register int j = m; j >= 1; j--) {
            if(g[s(i, j)]) {
                if(i != 1 && a[s(i - 1, j)]) g[s(i - 1, j)] = 1;
                if(j != 1 && a[s(i, j - 1)]) g[s(i, j - 1)] = 1;
            }
        }
    }
    if(!f[n * m]) {
        print(0, '\n');
        return 0;
    }
    for(register int i = 3; i < n + m; i++) {
        int l = max(1, i - m);
        int r = min(n, i - 1);
        int cnt = 0;
        for(register int x = l; x <= r; x++) {
            int y = i - x;
            if(f[s(x, y)] && g[s(x, y)]) ++cnt;
        }
        if(cnt == 1) {
            print(1, '\n');
            return 0;
        }
    }
    print(2, '\n');
    return 0;
}