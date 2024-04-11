#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
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

bitset <7005> f[7005], g[7005], a[N];
int mu[7005], n, m;

int main() {
    read(n); read(m); mu[1] = 1;
    for(register int i = 1; i <= 7000; i++) for(register int j = i * 2; j <= 7000; j += i) mu[j] -= mu[i];
    for(register int i = 1; i <= 7000; i++) {
        for(register int j = i; j <= 7000; j += i) {
            if(mu[j / i]) g[i][j] = 1;
            f[j][i] = 1;
        }
    }
    while(m--) {
        int opt; read(opt);
        if(opt == 1) {
            int x, y; read(x); read(y);
            a[x] = f[y];
        }
        if(opt == 2) {
            int x, y, z;
            read(x); read(y); read(z);
            a[x] = a[y] ^ a[z];
        }
        if(opt == 3) {
            int x, y, z;
            read(x); read(y); read(z);
            a[x] = a[y] & a[z];
        }
        if(opt == 4) {
            int x, y; read(x); read(y);
            int ans = (a[x] & g[y]).count() & 1;
            putchar(ans + '0');
        }
    }
    return 0;
} // qwqqaqqwq