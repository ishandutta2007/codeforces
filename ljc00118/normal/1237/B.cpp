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

int a[N], pre[N], b[N], f[N];
int n, ans;

inline int lowbit(int x) { return x & -x; }

inline void add(int x, int y) {
    for(register int i = x; i <= n; i += lowbit(i)) f[i] += y;
}

inline int query(int x) {
    int ans = 0;
    for(register int i = x; i; i ^= lowbit(i)) ans += f[i];
    return ans;
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]), pre[a[i]] = n - i + 1;
    for(register int i = 1; i <= n; i++) {
        read(b[i]);
        if(query(pre[b[i]]) != n - pre[b[i]]) ++ans;
        add(1, 1); add(pre[b[i]] + 1, -1);
    }
    print(ans, '\n');
    return 0;
}