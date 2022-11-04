#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-12;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;


const int MAXN = 2811111;

struct Node
{
    int l, r, cl, cr, val;

    Node(int tl, int tr, int tcl, int tcr, int tval = 0) :
        l(tl), r(tr), cl(tcl), cr(tcr), val(tval)
    {
    }

    Node()
    {
    }
} tree[MAXN];

int last;

int getNode() { return last++;}

int makeNode(int left, int right, int cl, int cr, int x)
{
    tree[x] = Node(left, right, cl, cr);
    tree[x].val = tree[cl].val + tree[cr].val;
    return x;
}

int build(int left, int right, int val, int x)
{
    tree[x].l = left;
    tree[x].r = right;
    if (left == right)
    {
        tree[x].val = val;
        return x;
    }

    int mid = (left + right) >> 1;
    tree[x].cl = build(left, mid, val, getNode());
    tree[x].cr = build(mid+1, right, val, getNode());
    tree[x].val = tree[tree[x].cl].val + tree[tree[x].cr].val;

    return x;
}

int add(int pos, int val, int x)
{
    if (tree[x].l == tree[x].r)
        return build(tree[x].l, tree[x].r, tree[x].val + val, getNode());
    int mid = tree[tree[x].cl].r;
    if (pos <= mid)
        return makeNode(tree[x].l, tree[x].r, add(pos, val, tree[x].cl), tree[x].cr, getNode());
    return makeNode(tree[x].l, tree[x].r, tree[x].cl, add(pos, val, tree[x].cr), getNode());
}

int root[MAXN];
int n, m, a[MAXN], depth[MAXN];

vector<int> vals[MAXN];
vector<int> e[MAXN];
int fa[200007][20];

void dfs(int u, int father = 0, int dep = 0)
{
    int cur = root[father];
    TR(it, vals[u]) {
        cur = add(*it, 1, cur);
    }
    root[u] = cur;

    fa[u][0] = father;
    depth[u] = dep;
    for (int i = 1; i < 20; ++i)
        fa[u][i] = fa[fa[u][i-1]][i-1];
    TR(it, e[u])
        if (*it != father)
            dfs(*it, u, dep+1);
}

int getLca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    for (int i = 19; i >= 0; --i)
        if (depth[fa[u][i]] >= depth[v])
            u = fa[u][i];
    if (u == v)
        return u;
    for (int i = 19; i >= 0; --i)
        if (fa[u][i] != fa[v][i])
        {
            u = fa[u][i];
            v = fa[v][i];
        }
    return fa[u][0];
}

int val[MAXN];

int main()
{
    int q;
    scanf("%d%d%d", &n, &m, &q);
    {
        last = 0;

        int u, v;
        REP(i, n-1)
        {
            scanf("%d%d", &u, &v);
            e[u].push_back(v);
            e[v].push_back(u);
        }

        REP(i, m) {
            int at;
            scanf("%d", &at);
            vals[at].PB(i + 1);
        }

        root[0] = build(0, m, 0, getNode());
        depth[0] = -1;
        dfs(1);

        REP(i, q)
        {
            int u, v, a;
            scanf("%d%d%d", &u, &v, &a);
            int lca = getLca(u, v);
            
            int ru = root[u], rv = root[v], rrr = root[fa[lca][0]], rr = root[lca];
            int num = tree[ru].val + tree[rv].val - tree[rr].val - tree[rrr].val;
            a = min(num, a);
            // cout << "num is " << num << endl;
            printf("%d", a);
            for (int j = 1; j <= a; ++j) {
                int k = j;
                ru = root[u], rv = root[v], rrr = root[fa[lca][0]], rr = root[lca];
                while (tree[ru].l != tree[ru].r)
                {
                    int have = tree[tree[ru].cl].val + tree[tree[rv].cl].val - tree[tree[rr].cl].val - tree[tree[rrr].cl].val;
                    if (have >= k)
                    {
                        ru = tree[ru].cl;
                        rv = tree[rv].cl;
                        rr = tree[rr].cl;
                        rrr = tree[rrr].cl;
                    }
                    else
                    {
                        k -= have;
                        ru = tree[ru].cr;
                        rv = tree[rv].cr;
                        rr = tree[rr].cr;
                        rrr = tree[rrr].cr;
                    }
                }
                // cout << "k is " << k << endl;
                printf(" %d", tree[ru].l);
            }
            printf("\n");
        }

    }
    return 0;
}