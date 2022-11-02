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

const int N = 100 * 1000 + 10;
vector<int> g[N];
bool used[N];
int p[N];
int n, m, k;
int fin = -1;

void dfs(int v, int prev = 0, int len = 0)
{
    if (fin > 0)
        return;

    used[v] = true;
    p[v] = prev;

    if (len >= k)
    {
        for (int i = 0; i < g[v].size(); ++i)
        {
            int to = g[v][i];
            if (to == 0)
                fin = v;
        }
    }

    if (fin > 0)
        return;

    for (int i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (!used[to])
            dfs(to, v, len + 1);
    }

}

void solve()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i)
    {
       int a, b;
       cin >> a >> b;
       --a;
       --b;
       g[a].push_back(b);
       g[b].push_back(a);
    }

    fill(used, used + N, 0);
    dfs(0, 0, 0);

    vector<int> res;
    for (int v = fin; v != 0; v = p[v])
        res.push_back(v + 1);
    res.push_back(1);

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}