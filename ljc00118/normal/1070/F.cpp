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

const int N = 4e5 + 5;

int a[N], b[N], c[N], s[N];
int al, bl, cl, sl, n, cnt, ans, maxn;

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) {
        int x, y;
        read(x); read(y);
        if(x == 0) a[++al] = y;
        if(x == 1) b[++bl] = y;
        if(x == 10) c[++cl] = y;
        if(x == 11) ++cnt, ans += y;
    }
    sort(a + 1, a + al + 1); reverse(a + 1, a + al + 1);
    sort(b + 1, b + bl + 1); reverse(b + 1, b + bl + 1);
    sort(c + 1, c + cl + 1); reverse(c + 1, c + cl + 1);
    if(bl <= cl) {
        for(register int i = 1; i <= bl; i++) ans += b[i] + c[i];
        for(register int i = bl + 1; i <= cl; i++) s[++sl] = c[i];
    } else {
        for(register int i = 1; i <= cl; i++) ans += b[i] + c[i];
        for(register int i = cl + 1; i <= bl; i++) s[++sl] = b[i];
    }
    for(register int i = 1; i <= al; i++) a[i] += a[i - 1];
    for(register int i = 1; i <= sl; i++) s[i] += s[i - 1];
    for(register int i = 0; i <= al; i++) {
        if(i > cnt) break;
        maxn = max(maxn, a[i] + s[min(sl, cnt - i)]);
    }
    print(ans + maxn, '\n');
    return 0;
}