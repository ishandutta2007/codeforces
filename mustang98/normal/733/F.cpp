#include <bits/stdc++.h>

#define prev AZAZA
#define x1 privet1
#define x2 privet2

using namespace std;

typedef long long ll;

const int max_n =200009;

struct str{
    int w, c, a, b, num;
    int deleted = -1;
    bool isinst = false;
};

str edge[max_n];

vector<str> ostov;

int p[max_n], sz[max_n], n, m, s;

int find_set(int a)
{
    if (a == p[a])
    {
        return a;
    }
    return p[a] = find_set(p[a]);
}

void union_set(int a, int b)
{
    int s1 = find_set(a);
    int s2 = find_set(b);
    if (sz[s1] < sz[s2])
    {
        swap(s1, s2);
    }
    sz[s1] += sz[s2];
    sz[s2] = -1;
    p[s2] = s1;
}

bool comp(str a, str b)
{
    return a.w < b.w;
}

int prev[max_n][24];
str maxx[max_n][24];

vector<str> v[max_n];
int current = 1;
int tin[max_n], tout[max_n];

void dfs(int a, int p)
{
    current++;
    int cur = 1;
    while(prev[a][cur - 1] != -1 && prev[prev[a][cur - 1]][cur - 1] != -1)
    {
        prev[a][cur] = prev[prev[a][cur - 1]][cur - 1];
        if (maxx[prev[a][cur - 1]][cur - 1].w > maxx[a][cur - 1].w)
        {
            maxx[a][cur] = maxx[prev[a][cur - 1]][cur - 1];
        }
        else
        {
            maxx[a][cur] =maxx[a][cur - 1];
        }
        cur++;
    }
    tin[a] = current;
    for(int i = 0; i < v[a].size(); i++)
    {
        str e = v[a][i];
        int b = a == e.a ? e.b : e.a;
        if (b == p) continue;
        prev[b][0] = a;
        maxx[b][0] = e;
        dfs(b, a);
    }
    current++;
    tout[a] = current;
}

bool isAnc(int a, int b)
{
    if (a == -1) return true;
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

str findMaxEdge(str e)
{
    int a = e.a, b = e.b;
    str maxedge;
    maxedge.w = -1e9 - 15;

    if (prev[a][0] == b)
    {
        return maxx[a][0];
    }

    if (prev[b][0] == a)
    {
        return maxx[b][0];
    }

    if (isAnc(a, b)) goto m1;
    for (int l = 23; l > 0; l--)
    {
        if (!isAnc(prev[a][l - 1], b))
        {
            if (maxx[a][l - 1].w > maxedge.w)
            {
                maxedge = maxx[a][l - 1];
            }
            a = prev[a][l - 1];
        }
    }
    if (maxx[a][0].w > maxedge.w)
    {
        maxedge = maxx[a][0];
    }

    m1:
    a = e.b, b = e.a;
    if (isAnc(a, b)) goto m2;
    for (int l = 23; l > 0; l--)
    {
        if (!isAnc(prev[a][l - 1], b))
        {
            if (maxx[a][l - 1].w > maxedge.w)
            {
                maxedge = maxx[a][l - 1];
            }
            a = prev[a][l - 1];
        }
    }
    if (maxx[a][0].w > maxedge.w)
    {
        maxedge = maxx[a][0];
    }
    m2:
        return maxedge;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &edge[i].w);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &edge[i].c);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &edge[i].a, &edge[i].b);
        edge[i].a--;
        edge[i].b--;
        edge[i].num = i;
    }

    scanf("%d", &s);

    sort(edge, edge + m, comp);

    // FIND MINIMUM SPANNING TREE
    for(int i = 0; i < n; i++)
    {
        sz[i] = 1;
        p[i] = i;
    }
    ll ned = 0;
    //cout << edge[0].a<<edge[0].b<<endl;
    for (int i = 0; i < m; i++)
    {
        if (find_set(edge[i].a) != find_set(edge[i].b))
        {
            ostov.push_back(edge[i]);
            edge[i].isinst = true;
            ned += (ll)edge[i].w;
            union_set(edge[i].a, edge[i].b);
        }
    }
    //cout << ostov.size();
    /*for (int i = 0; i < ostov.size(); i++)
    {
        cout << ostov[i].a +1 <<' '<<ostov[i].b + 1<<endl;
    }*/

    // TRY TO MINIMIZE PRICE OF EDGE, ALREADY IN SPANNING TREE
    str minedg;
    minedg.num = -1;
    ll minned = ned;
    for (str edg : ostov)
    {
        ll newned = ned - s / edg.c;
        if (newned < minned)
        {
            minned = newned;
            minedg = edg;
        }
    }
    // TRY TO MINIMIZE PRICE OF EDGE NOT IN THE SPANNING TREE
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < 24; j++)
        {
            prev[i][j] = -1;
        }
    }
    for (int i = 0; i < ostov.size(); i++)
    {
        str e = ostov[i];
        v[e.a].push_back(e);
        v[e.b].push_back(e);
    }
    dfs(0, -1);

    /*for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << maxx[i][j].num + 1<<' ';
        }
        cout << endl;
    }*/

    ll minned1 = ned;
    str minedg1;
    for (int i = 0; i < m; i++)
    {
        if (edge[i].isinst) continue;
        str maxedg = findMaxEdge(edge[i]);
        ll newned = ned - maxedg.w + edge[i].w - s / edge[i].c;
        //cout << edge[i].num + 1<<':'<<maxedg.num + 1<<endl;
        if (newned < minned1)
        {
            minned1 = newned;
            minedg1 = edge[i];
            minedg1.deleted = maxedg.num;
        }
    }

    if (minned <= minned1)
    {
        printf("%I64d\n", minned);
        for (int i = 0; i < ostov.size(); i++)
        {
            if (ostov[i].num == minedg.num)
            {
                printf("%d %d\n", minedg.num + 1, minedg.w - s / minedg.c);
            }
            else
            {
                printf("%d %d\n", ostov[i].num + 1, ostov[i].w);
            }
        }
    }
    else
    {
        printf("%I64d\n", minned1);
        for (int i = 0; i < ostov.size(); i++)
        {
            if (ostov[i].num == minedg1.deleted)
            {
                continue;
            }
            else
            {
                printf("%d %d\n", ostov[i].num + 1, ostov[i].w);
            }
        }
        printf("%d %d\n", minedg1.num + 1, minedg1.w - s / minedg1.c);
    }
    return 0;
}