#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
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

#define pii pair<int, int>
#define F first
#define S second

const int N = 500 * 1000 + 10;
int col[N];
vector<int> g[N];
vector<int> od;
bool good = true;

void dfs(int v)
{
    col[v] = 1;
    for (int i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (col[to] == 1)
            good = false;
        if (col[to] == 0)
            dfs(to);
    }
    col[v] = 2;
    od.push_back(v);
}

void solve()
{
    fill(col, col + N, 0);

    int n, m;
    scanf("%d%d", & n, & m);

    int curr = m - 1;
    for (int i = 0; i < n; ++i)
    {
        curr += 2;
        vector< pii > v(m);
        for (int j = 0; j < m; ++j)
        {
            scanf("%d", & v[j].F);
            v[j].S = j;
        }
        sort(v.begin(), v.end());
        for (int j = 0; j < m; ++j)
        {
            if (v[j].F == -1)
                continue;
            if (j > 0 && v[j].F != v[j - 1].F && v[j - 1].F != -1)
                ++curr;
            int highP = upper_bound(v.begin(), v.end(), pii(v[j].F, 1000 * 1000)) - v.begin();
            int lowP = lower_bound(v.begin(), v.end(), pii(v[j].F, -1)) - v.begin();
            g[v[j].S].push_back(curr - 1);
            g[curr].push_back(v[j].S);
        }
    }

    for (int i = 0; i < curr + 1; ++i)
        if (col[i] == 0)
            dfs(i);

    if (!good)
    {
        puts("-1");
    }
    else
    {
        for (int i = 0; i < od.size(); ++i)
            if (od[i] < m)
                printf("%d ", od[i] + 1);
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