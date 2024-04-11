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

const int N = 1e6 + 5, INF = 0x7fffffff;

int phi[N];
int n, k;
ll ans, sum;

int main() {
    read(n); read(k);
    for(register int T = 0; T <= 1; T++) {
        for(register int i = 1; i <= n; i++) phi[i] = i;
        for(register int i = 1; i <= n; i++) {
            for(register int j = i + i; j <= n; j += i) phi[j] -= phi[i];
        }
        if(!T) {
            for(register int i = 4; i <= n; i += 2) phi[i] = INF;
        }
        sort(phi + 3, phi + n + 1);
        sum = 1 + T;
        for(register int i = 3; i <= k + 2; i++) sum += phi[i];
        if(!T) { ans = sum; } else { ans = min(ans, sum); }
    }
    print(ans, '\n');
    return 0;
}