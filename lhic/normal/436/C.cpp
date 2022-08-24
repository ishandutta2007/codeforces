#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <bitset>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>

typedef long long ll;
typedef long double ld;

using namespace std;

const int MAX_N = 100000;

int n, m;

int w, k;


struct edge
{
    int a, b, w;
};

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int ww[1200];

int go[1200];

vector<int> res;


int col[1200];

int eds[1200][1200];
char arr[1200][11][11];

vector<edge> edges;


vector<int> eds2[1200];

bool cmp2(int a, int b)
{
    return ww[a] < ww[b];
}

int diff(int a, int b)
{
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans += arr[a][i][j]!=arr[b][i][j];
    return min(n * m, w * ans);
}



void DFS(int v, int lst, int dp)
{
    go[v] = lst;
    ww[v] = dp;

    for (int i = 0; i < eds2[v].size(); ++i)
    {
        int x = eds2[v][i];
        if (ww[x] != -1)
            continue;
        DFS(x, v, dp + 1);
    }

}



int fww(int i)
{
    if (ww[i] != -1)
        return ww[i];
    return ww[i] = fww(go[i]) + 1;
}


int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k >> w;
    for (int ij = 0; ij < k ; ++ij)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> arr[ij][i][j];
        for (int ij1 = 0; ij1 < ij; ++ij1)
            eds[ij][ij1] = eds[ij1][ij] = diff(ij, ij1);
    }

    for (int i = 0; i < k; ++i)
        col[i] = i;

    for (int i = 0; i < k; ++i)
    {
        for (int j = i + 1; j < k; ++j)
        {
            edge x;
            x.a = i;
            x.b = j;
            x.w = eds[i][j];
            edges.push_back(x);
        }
    }

    sort(edges.begin(),edges.end(),cmp);
    int ans = 0;
    for (int i = 0; i < k; ++i)
        res.push_back(i);

    for (int i = 0; i < edges.size(); ++i)
    {
        if (col[edges[i].a] == col[edges[i].b])
            continue;
        ans += edges[i].w;
        eds2[edges[i].a].push_back(edges[i].b);
        eds2[edges[i].b].push_back(edges[i].a);
        int xx=col[edges[i].b];
        for (int j = 0; j < k;++j)
            if (col[j] == xx)
                col[j] = col[edges[i].a];
    }
    cout << ans + n * m << "\n";


    for (int i = -1; i < k; ++i)
        ww[i] = -1;

    DFS(0,-1,0);

    sort(res.begin(), res.end(), cmp2);

    for (int i = 0; i < res.size(); ++i)
    {
        if (go[res[i]] == -1 || eds[res[i]][go[res[i]]] == n * m)
            cout << res[i] + 1 << " 0\n";
        else
            cout << res[i] + 1 << " " << go[res[i]] + 1 << "\n";
    }


    return 0;
}