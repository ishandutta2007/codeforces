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

const int N = 20005;

int a[N], vis[N], n, sum;

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) {
        read(a[i]);
        if(a[i] % 2 == 0) {
            a[i] >>= 1;
            sum += a[i];
            vis[i] = 1;
        } else {
            int d = a[i] / 2;
            if(a[i] < 0) d--;
            a[i] = d; sum += d;
        }
    }
    for(register int i = 1; i <= n; i++) {
        if(sum == 0) break;
        if(!vis[i]) {
            ++sum;
            ++a[i];
        }
    }
    for(register int i = 1; i <= n; i++) print(a[i], '\n');
    return 0;
}