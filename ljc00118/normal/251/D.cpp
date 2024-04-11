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

const int N = 1e5 + 5;

bitset <N> a[65], b[65];
int ans[N], x[65];
int n, top;

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) {
        ll x, cnt = 0; read(x);
        while(x) {
            a[cnt][i] = x & 1;
            x >>= 1; ++cnt;
        }
    }
    for(register int v = 0; v <= 1; v++) {
        for(register int i = 59; i >= 0; i--) {
            if((int)(a[i].count() % 2) == v) {
                b[++top] = a[i]; b[top][n + 1] = 1 - v;
                for(register int j = 1; j < top; j++) {
                    if(b[top][x[j]]) {
                        b[top] ^= b[j];
                    }
                }
                x[top] = 0;
                for(register int j = 1; j <= n; j++) {
                    if(b[top][j]) {
                        x[top] = j;
                        break;
                    }
                }
                if(!x[top]) { --top; continue; }
                for(register int j = 1; j < top; j++) {
                    if(b[j][x[top]]) {
                        b[j] ^= b[top];
                    }
                }
            }
        }
    }
    for(register int i = 1; i <= top; i++) ans[x[i]] = b[i][n + 1];
    for(register int i = 1; i <= n; i++) print(2 - ans[i], i == n ? '\n' : ' ');
    return 0;
}