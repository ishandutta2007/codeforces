#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>
#include <cctype>
#include <ctime>

using namespace std;

#define pii pair<int, int>
#define F first
#define S second

const int N = 7;
int g[N][N];
int deg[N];

void init()
{
    for (int i = 0; i < N; ++i)
    {
        fill(g[i], g[i] + N, 0);
    }
    fill(deg, deg + N, 0);
}

vector<int> ans;

void dfs(int v)
{
    cerr << v << endl;
    for (int i = 0; i < N; ++i)
    {
        if (g[i][v])
        {
            --g[i][v];
            --g[v][i];
            dfs(i);
        }
    }
    ans.push_back(v);
}

void solve()
{
    int n;
    cin >> n;

    pii d[n];

    init();

    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a][b]++;
        g[b][a]++;
        deg[a]++;
        deg[b]++;
        d[i].F = a;
        d[i].S = b;
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        if (deg[i] % 2 != 0)
            ++cnt;
    }

    if (cnt >= 3)
    {
        cout << "No solution";
        return;
    }

    int cur = 0;
    for (int i = 0; i < N; ++i)
    {
        if (deg[i] % 2 != 0)
            cur = i;
    }

    if (cur == 0 && cnt == 0)
    {
        for (int i = 0; i < N; ++i)
            if (deg[i] > 0)
                cur = i;
    }

    dfs(cur);


    if (ans.size() != n + 1)
    {
        cout << "No solution";
        return;
    }

    vector<bool> taken(n, false);
    for (int i = 1; i < ans.size(); ++i)
    {
        pii current_edge = pii(ans[i - 1], ans[i]);
        for (int j = 0; j < n; ++j)
        {
            if (taken[j])
                continue;
            if (d[j].F == current_edge.F && d[j].S == current_edge.S)
            {
                cout << j + 1 << " " << "+" << endl;
                taken[j] = true;
                break;
            }
            if (d[j].F == current_edge.S && d[j].S == current_edge.F)
            {
                cout << j + 1 << " " << "-" << endl;
                taken[j] = true;
                break;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}