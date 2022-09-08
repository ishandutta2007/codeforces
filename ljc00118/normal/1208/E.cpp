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

const int N = 1e6 + 5;

ll f[N];
int a[N], st[N][25], lg[N];
int n, w, l;

inline int lowbit(int x) { return x & -x; }

inline void add(int x, int y) {
    if(x == w + 1) return;
    while(x <= w) {
        f[x] += y;
        x += lowbit(x);
    }
}

inline ll query(int x) {
    ll ans = 0;
    while(x) {
        ans += f[x];
        x ^= lowbit(x);
    }
    return ans;
}

inline int query(int l, int r) {
    int k = lg[r - l + 1];
    if(a[st[l][k]] > a[st[r - (1 << k) + 1][k]]) return st[l][k];
    return st[r - (1 << k) + 1][k];
}

void solve(int l, int r, int L, int R, int len) {
    if(l > r || L > R) return;
    int mid = query(l, r);
    if(a[mid] <= 0 && len * 2 <= w) return;
    if(a[mid] <= 0) {
        L = max(L, w - len + 1);
        R = min(R, len);
    }
    if(L > R) return;
    int _l = max(L, mid), _r = min(R, mid + w - len);
    if(_l <= _r) add(_l, a[mid]), add(_r + 1, -a[mid]);
    solve(l, mid - 1, L, _l - 1, len);
    solve(mid + 1, r, _r + 1, R, len);
}

int main() {
    read(n); read(w);
    for(register int T = 1; T <= n; T++) {
        read(l);
        for(register int i = 1; i <= l; i++) read(a[i]), st[i][0] = i;
        for(register int j = 1; j <= 20; j++) {
            for(register int i = 1; i <= l - (1 << j) + 1; i++) {
                if(a[st[i][j - 1]] > a[st[i + (1 << (j - 1))][j - 1]]) st[i][j] = st[i][j - 1];
                else st[i][j] = st[i + (1 << (j - 1))][j - 1];
            }
        }
        lg[0] = -1;
        for(register int i = 1; i <= l; i++) lg[i] = lg[i >> 1] + 1;
        solve(1, l, 1, w, l);
    }
    for(register int i = 1; i <= w; i++) print(query(i), i == w ? '\n' : ' ');
    return 0;
}