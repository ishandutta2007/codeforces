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

const int N = 7005;

struct ele {
    ll a, b; int cnt;
    bool operator < (const ele A) const { return a < A.a; }
} a[N], b[N];

ll sum[N];
ll ans = 0;
int n, m;

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i].a);
    for(register int i = 1; i <= n; i++) read(a[i].b), a[i].cnt = 1;
    sort(a + 1, a + n + 1); m = 1; b[1] = a[1];
    for(register int i = 2; i <= n; i++) {
        if(a[i].a == b[m].a) {
            ++b[m].cnt;
            b[m].b += a[i].b;
        } else b[++m] = a[i];
    }
    for(register int i = 1; i <= m; i++) {
        if(b[i].cnt >= 2) ans += b[i].b;
        else {
            for(register int j = 1; j <= m; j++) {
                if(b[j].cnt >= 2 && (b[i].a & b[j].a) == b[i].a) {
                    ans += b[i].b;
                    break;
                }
            }
        }
    }
    print(ans, '\n');
    return 0;
}