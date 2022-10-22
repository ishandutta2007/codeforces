#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <stdio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const double pi = acos(-1.0);

using namespace std;

int n, m;
vec<int> par, in, out, q, Q;
vec< vec<int> > g;
vec<bool> used;

struct zz
{
    int type;
    int x1, y;
    int x2, i;
    int x3;

    zz()
    {
        type = x1 = x2 = x3 = y = i = -1;
    }

    zz(int T, int X, int Y = -1)
    {
        type = x1 = x2 = x3 = y = i = -1;
        type = T;
        if(T == 1) x1 = X, y = Y;
        else if(T == 2) x2 = X;
        else x3 = X, i = Y;
    }
};

vec<zz> z; 

int find(int x)
{
    return (x == par[x]?x : par[x] = find(par[x]));
}

void _union(int a, int b)
{
    int p, q;
    p = find(a);
    q = find(b);
    par[p] = q;
}

int time = 1;

void dfs(int v)
{
    in[v] = time;
    for(int i(0);i < (int)g[v].size();i++)
    {
        int to = g[v][i];
        dfs(to);
    }
    out[v] = time++;
}

bool solve()
{
    cin >> n >> m;

    g.resize(n);
    used.assign(n, false);

    par.resize(n);

    for(int i(0);i < n;i++) par[i] = i;

    for(int type, x, y, i(0);i < m;i++)
    {
        cin >> type;
        x = y = 0;

        if(type != 2) cin >> x >> y;
        else cin >> x;
        x--, y--;
        z.push_back(zz(type, x, y));
    }

    for(int x, y, i(0);i < m;i++)
    {
        if(z[i].type == 1)
        {
            x = z[i].x1, y = z[i].y;
            g[y].push_back(x);
            used[x] = 1;
        }
    }

    in.resize(n, 0);
    out.resize(n, 0);

    for(int i(0);i < n;i++) if(!used[i]) dfs(i);

    for(int i(0);i < m;i++)
    {
        if(z[i].type == 1)
        {
            int x, y;
            x = z[i].x1, y = z[i].y;
            _union(x, y);
        }else if(z[i].type == 2)
        {
            q.push_back(i);
            Q.push_back(find(z[i].x2));
        }else if(z[i].type == 3)
        {   
            int x, y, root;
            x = y = 0;
            x = z[i].x3, y = z[q[z[i].i]].x2;
            root = Q[z[i].i];
            if(find(x) != find(y)) {cout << "NO\n";continue;}

            if(in[root] <= in[x] && out[root] >= out[x] && in[x] <= in[y] && out[x] >= out[y]) 
                cout << "YES\n";
            else 
                cout << "NO\n";
        }
    }

    return true;
}

int main()
{
    //while(solve());
    solve();    

    return 0;
}