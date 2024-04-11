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

const int N = 1e5 + 5;

vector <int> t[N << 3];
int q[N][3];
int fa[N], l[N], r[N], L[N], R[N], pre[N << 1];
int n, big, cnt;

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void change(int u, int l, int r, int L, int R, int x) {
    if(l <= L && R <= r) {
        t[u].push_back(x);
        return;
    }
    int mid = (L + R) >> 1;
    if(mid >= l) change(u << 1, l, r, L, mid, x);
    if(mid + 1 <= r) change(u << 1 | 1, l, r, mid + 1, R, x);
}

void query(int u, int l, int r, int x, int y) {
    for(register unsigned i = 0; i < t[u].size(); i++) {
        int tmp = find(t[u][i]);
        if(tmp == y) continue;
        fa[tmp] = y;
        ::l[y] = min(::l[y], ::l[tmp]);
        ::r[y] = max(::r[y], ::r[tmp]);
    }
    t[u].clear();
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(mid >= x) query(u << 1, l, mid, x, y);
    else query(u << 1 | 1, mid + 1, r, x, y);
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) {
        for(register int j = 0; j <= 2; j++) read(q[i][j]);
        if(q[i][0] == 1) pre[++big] = q[i][1], pre[++big] = q[i][2];
    }
    sort(pre + 1, pre + big + 1);
    big = unique(pre + 1, pre + big + 1) - pre - 1;
    for(register int i = 1; i <= n; i++) {
        if(q[i][0] == 1) {
            ++cnt; fa[cnt] = cnt;
            int x = lower_bound(pre + 1, pre + big + 1, q[i][1]) - pre;
            int y = lower_bound(pre + 1, pre + big + 1, q[i][2]) - pre;
            l[cnt] = L[cnt] = x; r[cnt] = R[cnt] = y;
            query(1, 1, big, x, cnt); query(1, 1, big, y, cnt);
            if(l[cnt] + 1 <= r[cnt] - 1) change(1, l[cnt] + 1, r[cnt] - 1, 1, big, cnt);
            // if(n >= 100) printf("%d %d %d\n", cnt, l[cnt], r[cnt]);
        } else {
            int x = q[i][1], y = find(q[i][2]);
            if(find(x) == y || (l[y] < L[x] && L[x] < r[y]) || (l[y] < R[x] && R[x] < r[y])) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}