#include <algorithm>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int N = 1111;
vector<int> g[N];
vector<int> sz;
vector<bool> u(N, 0);
vector<int> deg(N, 0);
int h[N];
int comp[N];
int n;
int x;
int cnt = 0;
int tot;
vector<int> a;
bool dp[N][N];

void dfs(int v, int hh)
{
    u[v] = true;
    comp[v] = cnt;
    tot++;
    h[v] = hh;
    for (int to: g[v])
        dfs(to, hh + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> x;
    x--;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        if (v == 0)
            continue;
        v--;
        g[v].push_back(i);
        deg[i]++;
    }


    for (int i = 0; i < n; i++)
        if (!u[i] && deg[i] == 0)
        {
            tot = 0;
            dfs(i, 0);
            cnt++;
            sz.push_back(tot);
        }

    a.push_back(0);
    int bad = comp[x];
    for (int i = 0; i < cnt; i++)
        if (i != bad)
            a.push_back(sz[i]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = 0;
    dp[0][0] = 1;
    for (int i = 1; i < a.size(); i++)
        for (int s = 0; s < N; s++)
        {
            if (s + a[i] >= N)
                continue;
            dp[i][s] = (dp[i][s] || dp[i - 1][s]);
            dp[i][s + a[i]] = (dp[i][s + a[i]] || dp[i - 1][s]);
        }

    for (int s = 0; s < N; s++)
        if (dp[a.size() - 1][s])
            cout << h[x] + s + 1 << endl;

    return 0;
}