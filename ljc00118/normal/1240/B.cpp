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

const int N = 3e5 + 5;

int a[N], b[N], l[N], r[N];
int T, n, big, maxn;

inline bool check(int x) { return r[x] < l[x + 1]; }

int main() {
    read(T);
    while(T--) {
        read(n); maxn = 0;
        for(register int i = 1; i <= n; i++) {
            read(a[i]); b[i] = a[i];
            l[i] = r[i] = 0;
        }
        sort(b + 1, b + n + 1); big = unique(b + 1, b + n + 1) - b - 1;
        for(register int i = 1; i <= n; i++) {
            a[i] = lower_bound(b + 1, b + big + 1, a[i]) - b;
            if(!l[a[i]]) l[a[i]] = i;
            r[a[i]] = i;
        }
        for(register int i = 1; i < big; ) {
            if(!check(i)) { i++; continue; }
            int j = i;
            while(j + 1 < big && check(j + 1)) ++j;
            maxn = max(maxn, j - i + 1);
            i = j + 1;
        }
        print(big - 1 - maxn, '\n');
    }
    return 0;
}