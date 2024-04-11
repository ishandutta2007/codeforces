#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 200005;
const int Maxm = 1048576;

struct pos {
    int x, y, c;
    pos(): x(0), y(0), c(0) {}
};

int n, q;
int p[Maxn];
pos st[Maxm];
set <int> S;
int cur;

pos Union(pos a, pos b)
{
    pos c;
    c.x = (ll(a.x) + ll(a.y) * b.x) % mod;
    c.y = ll(a.y) * b.y % mod;
    c.c = (ll(a.c) + ll(a.y) * b.c) % mod;
    return c;
}

void Create(int v, int l, int r)
{
    if (l == r) {
        st[v].x = (1 - p[l] + mod) % mod;
        st[v].y = p[l];
        st[v].c = 1;
    } else {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

pos Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[v];
    else {
        int m = l + r >> 1;
        if (b <= m) return Get(2 * v, l, m, a, b);
        if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
        return Union(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
    }
}

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

int Solve(int l, int r)
{
    pos ans = Get(1, 1, n, l, r);
    int mult = (1 - ans.x + mod) % mod;
    return ll(ans.c) * Inv(mult) % mod;
}

int main()
{
    int inv100 = Inv(100);
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        p[i] = ll(p[i]) * inv100 % mod;
    }
    Create(1, 1, n);
    S.insert(1); S.insert(n + 1);
    cur = Solve(1, n);
    for (int i = 0; i < q; i++) {
        int x; scanf("%d", &x);
        set <int>::iterator it2 = S.lower_bound(x);
        set <int>::iterator it = it2;
        it--;
        if (*it2 == x) {
            S.erase(it2++);
            cur = (cur - Solve(x, *it2 - 1) + mod) % mod;
            cur = (cur - Solve(*it, x - 1) + mod) % mod;
            cur = (cur + Solve(*it, *it2 - 1)) % mod;
        } else {
            cur = (cur - Solve(*it, *it2 - 1) + mod) % mod;
            cur = (cur + Solve(*it, x - 1)) % mod;
            cur = (cur + Solve(x, *it2 - 1)) % mod;
            S.insert(x);
        }
        printf("%d\n", cur);
    }
    return 0;
}