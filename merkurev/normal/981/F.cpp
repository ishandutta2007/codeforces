#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = (int) 2e5 + 100;
int a[2 * N], b[N];

const int LOG = 19;
const int LEVEL = (1 << LOG);
const int SIZE = (LEVEL << 1);
const int INF = (int) 2e9 + 100;
int n;

struct Tree
{
    int mn[SIZE], add[SIZE];

    Tree() : mn(), add() {}

    void push(int v, int x)
    {
        add[v] += x;
        mn[v] += x;
    }
    inline void push(int v)
    {
        if (add[v] == 0) return;
        push(2 * v, add[v] );
        push(2 * v + 1, add[v] );
        add[v] = 0;
    }
    inline void update(int v)
    {
        mn[v] = min(mn[2 * v], mn[2 * v + 1] );
    }
    void treeAdd(int v, int tl, int tr, int l, int r, int x)
    {
        if (r < tl || tr < l) return;
        if (l <= tl && tr <= r)
        {
            push(v, x);
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        treeAdd(2 * v, tl, tm, l, r, x);
        treeAdd(2 * v + 1, tm + 1, tr, l, r, x);
        update(v);
    }
    void treeAdd(int l, int r, int x)
    {
        if (l > r) return;
        treeAdd(1, 0, LEVEL - 1, l, r, x);
    }
    int getMin(int v, int tl, int tr, int l, int r, int x = INF)
    {
        if (r < tl || tr < l) return INF;
        if (l <= tl && tr <= r)
            return mn[v];
        if (mn[v] >= x) return mn[v];
        push(v);
        int tm = (tl + tr) / 2;
        int ans = getMin(2 * v, tl, tm, l, r, x);
        ans = min(ans, getMin(2 * v + 1, tm + 1, tr, l, r, min(ans, x)));
        return ans;
    }
    int getMin(int l, int r, int x = INF)
    {
        if (l > r) return INF;
        return getMin(1, 0, LEVEL - 1, l, r, x);
    }

    void clear()
    {
        memset(add, 0, sizeof add);
        memset(mn, 0, sizeof mn);
    }
    void fix()
    {
        for (int i = 0; i < LEVEL; i++)
            mn[LEVEL + i] += (-i - 1);
        for (int i = LEVEL - 1; i > 0; i--)
            mn[i] = min(mn[2 * i], mn[2 * i + 1] );
    }
};
Tree tree;


const int SZ = N;
int l;
pair <int, int> closed[SZ];
int closedsz;
int spos = 0;


bool good(int d)
{
//    eprintf("test %d :\n", d);
    if (2 * d >= l - 1) return true;

    closedsz = 0;
    int cnt = 0;
    tree.clear();

    for (int i = 0; i < n; i++)
    {
        int val = b[i];
        long long stll = val - d, fnll = val + d;
        if (stll < 0)
        {
            stll += l;
            fnll += l;
        }
        int st = stll;
        int fn = ((fnll > INF) ? INF : fnll);
        int x = lower_bound(a, a + 2 * n, st) - a;
        int y = upper_bound(a, a + 2 * n, fn) - a - 1;
        if (x > y) return false;
        if (x >= n)
        {
            x -= n;
            y -= n;
        }

        if (y < n)
        {
            tree.mn[LEVEL + x]++;
            closed[closedsz++] = make_pair(y + 1, x + n);
            continue;
        }
        cnt++;
        closed[closedsz++] = make_pair(y - n + 1, x);
    }
    sort(closed, closed + closedsz);
    for (int i = 0; i + 1 < LEVEL; i++)
        tree.mn[LEVEL + i + 1] += tree.mn[LEVEL + i];
    tree.fix();
#ifdef LOCAL
//    return d >= 3883412;
#endif

    int idClosed = 0;
    for (int i = 0; i < n; i++)
    {
        while (idClosed < closedsz && closed[idClosed].first == i)
        {
            tree.treeAdd(0, closed[idClosed].second - 1, -1);
            idClosed++;
        }
        if (tree.getMin(i, n + i - 1, -cnt) + cnt < 0) 
            return false;
        cnt++;
    }
    return true;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%d%d", &n, &l);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i] );
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i] );
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++)
        a[n + i] = a[i] + l;

    int bl = -1, br = l + 1;
    while (br - bl > 1)
    {
        int bm = (bl + br) / 2;
        if (good(bm) )
            br = bm;
        else
            bl = bm;
    }
    printf("%d\n", br);


	return 0;
}