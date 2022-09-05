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

const int N = 4e5 + 5, INF = 1e9;

struct atom {
    int val, id;
    atom (int a = 0, int b = 0) : val(a), id(b) {}
};

bool operator < (const atom a, const atom b) { return a.val < b.val; }

struct node_t { int l, r; atom mx, mn; } p[N << 2];

queue <int> q;
int a[N], b[N], col[N], rev[N];
int n, ans;

void update(int u) {
    p[u].mx = max(p[u << 1].mx, p[u << 1 | 1].mx);
    p[u].mn = min(p[u << 1].mn, p[u << 1 | 1].mn);
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if (l == r) {
        p[u].mx = atom(-INF, 0);
        p[u].mn = atom(INF, 0);
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    update(u);
}

void modify(int u, int x, atom y) {
    if (p[u].l == p[u].r) {
        if (y.val == 0) {
            p[u].mx = atom(-INF, 0);
            p[u].mn = atom(INF, 0);
        } else {
            p[u].mx = p[u].mn = y;
        }
        return;
    }
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= x) modify(u << 1, x, y);
    else modify(u << 1 | 1, x, y);
    update(u);
}

atom qmn(int u, int l, int r) {
    if (l <= p[u].l && p[u].r <= r) return p[u].mn;
    int mid = (p[u].l + p[u].r) >> 1; atom ans = atom(INF, 0);
    if (mid >= l) ans = min(ans, qmn(u << 1, l, r));
    if (mid + 1 <= r) ans = min(ans, qmn(u << 1 | 1, l, r));
    return ans;
}

atom qmx(int u, int l, int r) {
    if (l <= p[u].l && p[u].r <= r) return p[u].mx;
    int mid = (p[u].l + p[u].r) >> 1; atom ans = atom(-INF, 0);
    if (mid >= l) ans = max(ans, qmx(u << 1, l, r));
    if (mid + 1 <= r) ans = max(ans, qmx(u << 1 | 1, l, r));
    return ans;
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i]); read(b[i]);
        if ((a[i] > n) + (b[i] > n) != 1) {
            printf("-1\n");
            return 0;
        }
        if (a[i] > b[i]) swap(a[i], b[i]), rev[i] = 1;
    }
    build(1, 1, n);
    for (int i = 1; i <= n; i++) modify(1, a[i], atom(b[i], i));
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1 || a[i] == n) continue;
        atom tem = qmn(1, 1, a[i] - 1);
        if (tem.id && tem.val < b[i]) {
            tem = qmx(1, a[i] + 1, n);
            if (tem.id && tem.val > b[i]) {
                printf("-1\n");
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        atom tem = qmx(1, a[i], a[i]);
        if (tem.id == 0) continue;
        // fprintf(stderr, "i = %d\n", i);
        modify(1, a[i], atom(0, 0));
        q.push(i);
        int cnt[2] = {0, 0};
        while (!q.empty()) {
            int u = q.front(); q.pop(); ++cnt[col[u] ^ rev[u]];
            while (1) {
                atom tem = qmn(1, 1, a[u]);
                if (tem.id && tem.val < b[u]) {
                    q.push(tem.id);
                    col[tem.id] = col[u] ^ 1;
                    modify(1, a[tem.id], atom(0, 0));
                } else break;
            }
            while (1) {
                atom tem = qmx(1, a[u], n);
                // cout << u << " " << tem.val << " " << tem.id << endl;
                if (tem.id && tem.val > b[u]) {
                    q.push(tem.id);
                    col[tem.id] = col[u] ^ 1;
                    modify(1, a[tem.id], atom(0, 0));
                } else break;
            }
        }
        ans += min(cnt[0], cnt[1]);
    }
    // for (int i = 1; i <= n; i++) fprintf(stderr, "col[%d] = %d\n", i, col[i]);
    print(ans, '\n');
    return 0;
}