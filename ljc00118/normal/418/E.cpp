#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e5 + 5, B = 310;

vector <int> pos[N * 2], big;
unordered_map <int, int> id;
int a[N], lc[N * 40], rc[N * 40], sum[N * 40], rt[N * 2], root[B + 5], tag[N * 2], rub[N * 40];
int n, m, tot, cnt_id, top;

inline int newNode() {
    if (top) {
        int u = rub[top];
        --top;
        lc[u] = rc[u] = 0;
        return u;
    }
    return ++tot;
}

void add(int &u, int l, int r, int x, int y) {
    if (!u) u = newNode();
    sum[u] += y;
    if (l == r) {
        if (!sum[u]) rub[++top] = u, u = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if (mid >= x) add(lc[u], l, mid, x, y);
    else add(rc[u], mid + 1, r, x, y);
    if (!sum[u]) rub[++top] = u, u = 0;
}

int query(int u, int l, int r, int x) {
    if (!u) return 0;
    if (r <= x) return sum[u];
    int mid = (l + r) >> 1, ans = query(lc[u], l, mid, x);
    if (mid + 1 <= x) ans += query(rc[u], mid + 1, r, x);
    return ans;
}

void add(int x, int y) {
    if (!id.count(x)) id[x] = ++cnt_id;
    x = id[x];
    add(rt[x], 1, n, y, 1);
    if (!tag[x] && (int)pos[x].size() + 1 > B) {
        for (int i = 0; i <= B; i++) add(root[i], 1, n, pos[x][i], -1);
        tag[x] = 1;
        big.push_back(x);
    }
    if (tag[x]) return;
    pos[x].push_back(y);
    int tmp = (int)pos[x].size() - 1;
    while (tmp && pos[x][tmp - 1] > pos[x][tmp]) {
        add(root[tmp - 1], 1, n, pos[x][tmp - 1], -1);
        add(root[tmp], 1, n, pos[x][tmp - 1], 1);
        swap(pos[x][tmp - 1], pos[x][tmp]);
        --tmp;
    }
    add(root[tmp], 1, n, y, 1);
}

void del(int x, int y) {
    x = id[x];
    add(rt[x], 1, n, y, -1);
    if (tag[x]) return;
    int tmp = lower_bound(pos[x].begin(), pos[x].end(), y) - pos[x].begin();
    add(root[tmp], 1, n, y, -1);
    while (tmp < (int)pos[x].size() - 1) {
        add(root[tmp + 1], 1, n, pos[x][tmp + 1], -1);
        add(root[tmp], 1, n, pos[x][tmp + 1], 1);
        swap(pos[x][tmp], pos[x][tmp + 1]);
        ++tmp;
    }
    pos[x].pop_back();
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), add(a[i], i);
    read(m);
    while (m--) {
        int opt; read(opt);
        if (opt == 1) {
            int x, y; read(y); read(x);
            del(a[x], x);
            a[x] = y;
            add(a[x], x);
        }
        if (opt == 2) {
            int x, y; read(x); read(y);
            if (x == 1) print(a[y], '\n');
            else if (x & 1) {
                int rk = query(rt[id[a[y]]], 1, n, y), ans = 0;
                if (rk <= B + 1) ans += query(root[rk - 1], 1, n, y);
                for (int i = 0; i < (int)big.size(); i++) {
                    int id = big[i];
                    ans += (query(rt[id], 1, n, y) >= rk);
                }
                print(ans, '\n');
            } else {
                print(query(rt[id[a[y]]], 1, n, y), '\n');
            }
        }
    }
    return 0;
}