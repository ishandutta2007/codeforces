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

ll s[N];
int a[N];
int n, len;
ll ans = -1;

void solve(int x) {
    ll sum = 0;
    for(register int i = 1; i <= len; i += x) {
        int wz = i + x / 2;
        sum += s[i + x - 1] - s[wz] - 1ll * (i + x - 1 - wz) * a[wz];
        sum += 1ll * (wz - i) * a[wz] - (s[wz - 1] - s[i - 1]);
    }
    if(ans == -1) ans = sum;
    else ans = min(ans, sum);
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) {
        int x; read(x);
        if(x) a[++len] = i, s[len] = s[len - 1] + a[len];
    }
    for(register int i = 2; i <= len; i++) {
        if(len % i == 0) {
            solve(i);
        }
    }
    print(ans, '\n');
    return 0;
}