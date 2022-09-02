#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i) 
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
using namespace std;
const int max0 = 4000000;
const int maxn = 100000;
const int max_abs = int(1e9) + 1;
int n;
int fa[maxn + 5], rank[maxn + 5];
int L[maxn + 5], R[maxn + 5];
struct node
{
    node *c[2];
    vector<int> all;
    int l, r;
    node() { memset(c, 0, sizeof c); }
};
node a[max0 + 5];
int cur = 0;
node *rt = NULL;
int get_root(const int &x)
{
    return fa[x] == x ? x : fa[x] = get_root(fa[x]);
}
void Union(int x, int y)
{
    x = get_root(x), y = get_root(y);
    if (rank[x] < rank[y]) swap(x, y);
    fa[y] = x;
    rank[x] += rank[x] == rank[y];
    L[x] = min(L[x], L[y]), R[x] = max(R[x], R[y]);
}
void query(node *rt, const int &x, const int &id, const int &l = -max_abs, const int &r = max_abs)
{
    if (rt == NULL) return;
    REP(i, 0, SZ(rt->all)) 
        Union(rt->all[i], id);
    rt->all.clear();
    if (r - l <= 1) return;
    int mid = (l + r) >> 1;
    if (x < mid) query(rt->c[0], x, id, l, mid);
    else query(rt->c[1], x, id, mid, r);
}
void add(node *&rt, const int &x, const int &y, const int &id, const int &l = -max_abs, const int &r = max_abs)
{
    if (rt == NULL) rt = a + (cur++);
    if (x <= l && r <= y)
    {
        rt->all.pb(id);
        return;
    }
    int mid = (l + r) >> 1;
    if (x < mid) add(rt->c[0], x, y, id, l, mid);
    if (y > mid) add(rt->c[1], x, y, id, mid, r);
}
pair<int, int> aa[maxn + 5];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &n);
    REP(i, 0, n) fa[i] = i, rank[i] = 0;
    int t = 0;
    REP(i, 0, n)
    {
        int type, x, y;
        scanf("%d%d%d", &type, &x, &y);
        if (type == 1)
        {
            L[t] = x, R[t] = y;
            aa[t] = mp(x, y);
            query(rt, x, t);
            query(rt, y, t);
            add(rt, L[get_root(t)] + 1, R[get_root(t)], get_root(t));
            ++t;
        }
        else if (type == 2)
        {
            --x, --y;
            y = get_root(y);
            printf("%s\n", (get_root(x) == y || (L[y] <= aa[x].x && aa[x].y <= R[y] && !(L[y] == aa[x].x && aa[x].y == R[y]))) ? "YES" : "NO");
        }
    }
    return 0;
}