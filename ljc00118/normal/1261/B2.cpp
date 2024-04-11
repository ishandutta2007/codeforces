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

struct ele {
    int v, pos;
    ele (int a = 0, int b = 0) : v(a), pos(b) {}
    bool operator < (const ele A) const {
        if(v != A.v) return v > A.v;
        return pos < A.pos;
    }
} a[N];

vector <pii> q[N];
int val[N << 2], v[N], ans[N];
int n, m;

void change(int u, int l, int r, int x) {
    if(l == r) {
        val[u] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if(mid >= x) change(u << 1, l, mid, x);
    else change(u << 1 | 1, mid + 1, r, x);
    val[u] = val[u << 1] + val[u << 1 | 1];
}

int query(int u, int l, int r, int x) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(x <= val[u << 1]) return query(u << 1, l, mid, x);
    return query(u << 1 | 1, mid + 1, r, x - val[u << 1]);
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(v[i]), a[i] = ele(v[i], i);
    sort(a + 1, a + n + 1);
    read(m);
    for(register int i = 1; i <= m; i++) {
        int a, b;
        read(a); read(b);
        q[a].push_back(make_pair(b, i));
    }
    for(register int i = 1; i <= n; i++) {
        change(1, 1, n, a[i].pos);
        for(register int j = 0; j < (int)q[i].size(); j++) {
            ans[q[i][j].second] = v[query(1, 1, n, q[i][j].first)];
        }
    }
    for(register int i = 1; i <= m; i++) print(ans[i], '\n');
    return 0;
}