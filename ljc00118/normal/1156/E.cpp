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

set <int> rt[N];
set <int> :: iterator it;
int a[N], val[N << 2], wz[N << 2];
int n, tot, ans;

void build(int u, int l, int r) {
    if(l == r) {
        val[u] = a[l]; wz[u] = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    if(val[u << 1] > val[u << 1 | 1]) val[u] = val[u << 1], wz[u] = wz[u << 1];
    else val[u] = val[u << 1 | 1], wz[u] = wz[u << 1 | 1];
}

int query(int u, int l, int r, int L, int R) {
    if(l <= L && R <= r) return wz[u];
    int mid = (L + R) >> 1;
    if(mid >= l && mid + 1 <= r) {
        int x = query(u << 1, l, r, L, mid);
        int y = query(u << 1 | 1, l, r, mid + 1, R);
        if(a[x] > a[y]) return x;
        return y;
    } else if(mid >= l) return query(u << 1, l, r, L, mid);
    return query(u << 1 | 1, l, r, mid + 1, R);
}

int solve(int l, int r) {
    if(l > r) return 0;
    if(r - l + 1 == 1) {
        rt[++tot].insert(a[l]);
        return tot;
    }
    int maxn = query(1, l, r, 1, n);
    int x = solve(l, maxn - 1);
    int y = solve(maxn + 1, r);
    if(rt[x].size() > rt[y].size()) swap(x, y);
    for(it = rt[x].begin(); it != rt[x].end(); ++it) if(rt[y].find(a[maxn] - *it) != rt[y].end()) ++ans;
    for(it = rt[x].begin(); it != rt[x].end(); ++it) rt[y].insert(*it);
    rt[y].insert(a[maxn]);
    return y;
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]);
    build(1, 1, n); solve(1, n);
    cout << ans << endl;
    return 0;
}