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

const int N = 2e5 + 5;

int a[N], st[N], l[N], r[N], dep[N];
int n, maxn, top, pos, tot, ans = N;

void add(int x) {
    while(top && x < st[top]) {
        dep[x] = max(dep[x], dep[st[top]]);
        --top;
        if(top) dep[st[top]] = max(dep[st[top]], dep[st[top + 1]] + 1);
    }
    st[++top] = x; ++dep[x]; maxn = max(maxn, dep[x] + top - 1);
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) {
        read(a[i]);
        if(a[i] == 1) pos = i;
    }
    tot = 0;
    for(register int i = pos - 1; i >= 1; i--) add(a[i]), l[++tot] = maxn;
    for(register int i = n; i > pos; i--) add(a[i]), l[++tot] = maxn;
    tot = maxn = top = 0; memset(dep, 0, sizeof(dep));
    for(register int i = pos + 1; i <= n; i++) add(a[i]), r[++tot] = maxn;
    for(register int i = 1; i < pos; i++) add(a[i]), r[++tot] = maxn;
    // for(register int i = 0; i < n; i++) {
    //     fprintf(stderr, "i : %d %d\n", l[i], r[i]);
    // }
    for(register int i = 0; i < n; i++) ans = min(ans, max(l[i], r[n - i - 1]) + 1);
    print(ans, ' ');
    tot = 0;
    for(register int i = pos - 1; i >= 0; i--) {
        if(max(l[i], r[n - i - 1]) + 1 == ans) { print(tot, '\n'); return 0; }
        ++tot;
    }
    for(register int i = n - 1; i > pos - 1; i--) {
        if(max(l[i], r[n - i - 1]) + 1 == ans) { print(tot, '\n'); return 0; }
        ++tot;
    }
    return 0;
}