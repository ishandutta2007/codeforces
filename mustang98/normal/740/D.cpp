#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;

const int maxl = 25, max_n = 200009;

ll m[max_n];
int p[max_n][maxl];
ll depth[max_n];
vector<pair<int, ll> > v[max_n];

void dfs(int a, ll d)
{
    depth[a] = d;
    int l = 0;
    while(p[a][l] != -1 && p[p[a][l]][l] != -1)
    {
        p[a][l + 1] = p[p[a][l]][l];
        l++;
    }
    for (int i = 0; i < v[a].size(); i++)
    {
        dfs(v[a][i].F, d + v[a][i].S);
    }
}


ll inf = 1e15+10;
ll dist(int a, int b)
{
    if (b == -1 || a == -1) return inf;
    return abs(depth[b] - depth[a]);
}

int kolst[max_n];
int kolfin[max_n];

void dfs2(int a)
{
    int cur = a;
    for (int l = maxl - 2; l > 0; l--)
    {
        ll d = dist(a, p[cur][l - 1]);
        if (d > m[a]) continue;
        else
        {
            cur = p[cur][l - 1];
        }
    }
    int st = cur;
    int fin = a;
    kolst[st]++;
    kolfin[fin]++;
    //cout << st <<' '<<fin<<endl;
    for (int i = 0; i < v[a].size(); i++)
        dfs2(v[a][i].F);
}

int ans[max_n];

void dfs3(int a)
{
    int anscur = kolfin[a];
    for(int i = 0; i < v[a].size(); i++)
    {
        dfs3(v[a][i].F);
        anscur += ans[v[a][i].F] - kolst[v[a][i].F];
    }
    ans[a] = anscur;
}

int main()
{
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < maxl; j++)
        {
            p[i][j] = -1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%I64d", m + i);
    }
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        a--;
        v[a].push_back(make_pair(i, b));
        p[i][0] = a;
    }
    dfs(0, 0);
    dfs2(0);
    /*cout << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << p[i][j]<<' ';
        }
        cout <<endl;
    }*/
    dfs3(0);
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] - 1 << ' ';
    }
    return 0;
}