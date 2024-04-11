#include <algorithm>
#include <iostream>
#include <string.h>
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

#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>

const int N = 50;
int g[N][N];
bool u[N];
vector<int> c[N];
vector<vector<int> > ans;
vector<int> cur;
int n, m;
bool was[N];

void dfs(int v)
{
    u[v] = true;
    cur.push_back(v);
    for (int i = 0; i < n; ++i)
    {
        if (g[v][i] && !u[i])
            dfs(i);
    }
}

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            g[i][j] = 0;

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a][b] = g[b][a] = 1;
    }

    fill(u, u + n, false);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (u[i])
            continue;
        cur.clear();
        dfs(i);
        if (cur.size() > 3)
        {
            cout << -1;
            return;
        }
        c[cnt++] = cur;
    }
    fill(was, was + cnt, false);
    for (int i = 0; i < cnt; ++i)
    {
        if (c[i].size() == 3)
        {
            was[i] = true;
            ans.push_back(c[i]);
        }
    }
    for (int i = 0; i < cnt; ++i)
        for (int j = 0; j < cnt; ++j)
        {
            if (i == j)
                continue;
            if (c[i].size() == 2 && c[j].size() == 1 && was[i] == false && was[j] == false)
            {
                ans.push_back(c[i]);
                ans.back().push_back(c[j][0]);
                was[i] = was[j] = true;
            }
        }
    for (int i = 0; i < cnt; ++i)
        for (int j = i + 1; j < cnt; ++j)
            for (int k = j + 1; k < cnt; ++k)
            {
                if (was[i] || was[j] || was[k])
                    continue;
                if (c[i].size() != 1 || c[j].size() != 1 || c[k].size() != 1)
                    continue;
                was[i] = was[j] = was[k] = true;
                ans.push_back(c[i]);
                ans.back().push_back(c[j][0]);
                ans.back().push_back(c[k][0]);
            }
    for (int i = 0; i < cnt; ++i)
    {
        if (!was[i])
        {
            cout << -1;
            return;
        }
    }
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i][0] + 1 << " " << ans[i][1] + 1 << " " << ans[i][2] + 1 << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}