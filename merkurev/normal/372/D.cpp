#include <iostream>
#include <vector>
#include <set>
using namespace std;


vector <int> g[100500];

int lc[100500][20];
int lev[100500];

int verts[200500];
int fstpos[100500];
int curpos = 1;

void dfs(int v, int par = -1, int level = 1)
{
    if (fstpos[v] == 0)
        fstpos[v] = curpos;
    verts[curpos++] = v;

    lev[v] = level;
    lc[v][0] = par;
    for (int i = 1; i < 20; i++)
        lc[v][i] = lc[lc[v][i - 1] ][i - 1];
    for (int i = 0; i < g[v].size(); i++)
    {
        int nv = g[v][i];
        if (nv == par)
            continue;
        dfs(nv, v, level + 1);
        verts[curpos++] = v;
    }
}
int bit(int m, int i)
{
    return ( (m >> i) & 1);
}
int goUp(int v, int cnt)
{
    for (int i = 0; i < 20; i++)
        if (bit(cnt, i) )
        {
            v = lc[v][i];
        }
    return v;
}
int lca(int x, int y)
{
    if (lev[x] > lev[y] )
        swap(x, y);
    y = goUp(y, lev[y] - lev[x] );

    if (x == y)
        return x;

    for (int i = 18; i >= 0; i--)
    {
        if (lc[x][i] != lc[y][i] )
        {
            x = lc[x][i];
            y = lc[y][i];
        }
    }
    return lc[x][0];
}


set <int> fstposes;

const int inf = 1e9;

int add(int v)
{
    int ans = inf;
    int pos = fstpos[v];


    int prevlca = 0;
    if (fstposes.size() )
    {
        prevlca = lev[lca(verts[*fstposes.begin() ], verts[*fstposes.rbegin() ] ) ];
    }

    fstposes.insert(pos);

    set <int>::iterator it = fstposes.find(pos), ii;
    if (it != fstposes.begin() )
    {
        ii = it;
        ii--;
        int w = verts[*ii];
        int xl = lev[lca(v, w) ];
        int curans = lev[v] - xl;
        if (xl < prevlca)
            curans += prevlca - xl;
    
        ans = min(ans, curans);
    }
    ii = it;
    ii++;
    if (ii != fstposes.end() )
    {
        int w = verts[*ii];
        int xl = lev[lca(v, w) ];
        int curans = lev[v] - xl;
        if (xl < prevlca)
            curans += prevlca - xl;

        ans = min(ans, curans);
    }
    if (ans == inf)
        ans = 0;

    fstposes.erase(pos);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    k--;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    int curK = 0;
    int curfst = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        curK += add(i);
        fstposes.insert(fstpos[i] );
        while (curK > k)
        {
            fstposes.erase(fstpos[curfst] );
            curK -= add(curfst);
            curfst++;
        }
        ans = max(ans, i - curfst + 1);
    }
    printf("%d", ans);



    return 0;
}