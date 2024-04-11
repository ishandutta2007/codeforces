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

const int N = 105;

struct ele {
    int a, b;
    ele (int x = 0, int y = 0) : a(x), b(y) {}
    bool operator < (const ele A) const { return b - a < A.b - A.a; }
} t[N], k[N];

int a[N], b[N], vis[N], f[60005];
int n, r, tl, kl, ans, maxn;

int main() {
    read(n); read(r);
    for(register int i = 1; i <= n; i++) {
        read(a[i]); read(b[i]);
        if(b[i] >= 0) t[++tl] = ele(a[i], b[i]);
        else k[++kl] = ele(a[i], -b[i]);
    }
    for(register int i = 1; i <= tl; i++) {
        bool ok = 0;
        for(register int j = 1; j <= tl; j++) {
            if(!vis[j] && r >= t[j].a) {
                vis[j] = 1; ok = 1; ++ans; r += t[j].b;
                break;
            }
        }
        if(!ok) break;
    }
    sort(k + 1, k + kl + 1);
    memset(f, -1, sizeof(f));
    f[r] = 0;
    for(register int i = 1; i <= kl; i++) {
        for(register int j = max(k[i].a, k[i].b); j <= 60000; j++) {
            if(f[j] != -1) f[j - k[i].b] = max(f[j - k[i].b], f[j] + 1);
        }
    }
    for(register int i = 0; i <= 60000; i++) maxn = max(maxn, f[i]);
    print(ans + maxn, '\n');
    return 0;
}