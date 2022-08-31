#include <bits/stdc++.h>

#define F first
#define S second
#define prev privet1

using namespace std;
typedef long long ll;

const int max_n = 200009;

vector<int> v[max_n], v1[max_n];
int col[max_n];
vector<pair<int, int> > edges;

int col1[max_n];
bool vis[max_n];

void dfs(int a, int curcol, int pr)
{
    vis[a] = 1;
    col1[a] = curcol;
    for(int i = 0; i < v[a].size(); i++)
    {
        if (pr == v[a][i]) continue;
        if (col[v[a][i]] == col[a])
        {
            dfs(v[a][i], curcol, a);
        }
    }
}

set<pair<int, int> > sete;

int maxd = -1, w;

int dfs1(int a, int d)
{
    vis[a] = 1;
    if (d > maxd)
    {
        maxd = d;
        w = a;
    }
    for (int i = 0; i < v1[a].size(); i++)
    {
        if (!vis[v1[a][i]])
        {
            dfs1(v1[a][i], d + 1);
        }
    }
}



int main()
{
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &col[i]);
    }

    for(int i = 0; i < n - 1; i++)
    {
        scanf("%d %d", &a, &b);
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
        edges.push_back(make_pair(a, b));
    }

    int curcol = 0;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i]) dfs(i, curcol, -1);
        curcol++;
    }

    for (int i = 0; i < edges.size(); i++)
    {
        a = edges[i].F;
        b = edges[i].S;
        //cout << a << ':' << b << endl;
        int a1 = col1[a];
        int b1 = col1[b];
        if (a > b) swap(a, b);
        if (a1 != b1 && sete.count(make_pair(a1, b1)) == 0)
        {
            sete.insert(make_pair(a1, b1));
            v1[a1].push_back(b1);
            v1[b1].push_back(a1);
        }
    }

    n = curcol;
    for (int i = 0; i < n; i++)
    {
        vis[i] = false;
    }

    dfs1(0, 1);
    int ver1 = w;
    maxd = -1;
    for (int i = 0; i < n; i++)
    {
        vis[i] = false;
    }

    dfs1(ver1, 1);
    cout << maxd / 2;
    return 0;

}