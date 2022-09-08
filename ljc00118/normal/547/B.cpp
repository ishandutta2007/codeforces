#pragma GCC target("avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
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

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

const int N = 2e5 + 5;

int st[N], l[N], r[N], val[N], top;
int a[N], n;

int main() {
    memset(val, -0x7f, sizeof(val));
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]);
    for(register int i = 1; i <= n; i++) {
        while(top && a[st[top]] > a[i]) {
            r[st[top]] = i - 1;
            --top;
        }
        st[++top] = i;
    }
    while(top) {
        r[st[top]] = n;
        --top;
    }
    for(register int i = n; i >= 1; i--) {
        while(top && a[st[top]] > a[i]) {
            l[st[top]] = i + 1;
            --top;
        }
        st[++top] = i;
    }
    while(top) {
        l[st[top]] = 1;
        --top;
    }
    for(register int i = 1; i <= n; i++) val[r[i] - l[i] + 1] = max(val[r[i] - l[i] + 1], a[i]);
    for(register int i = n - 1; i >= 1; i--) val[i] = max(val[i], val[i + 1]);
    for(register int i = 1; i <= n; i++) print(val[i], i == n ? '\n' : ' ');
    return 0;
}