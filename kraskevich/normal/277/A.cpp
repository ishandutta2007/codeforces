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
#define pll pair<long long, long long>
#define F first
#define S second

void openFiles()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

const int N = 101;
bool know[N][N];
bool used[N];
int n, m;

void dfs(int v)
{
    used[v] = true;
    for (int to = 0; to < n; ++to)
    {
        if (used[to])
            continue;
        bool ok = false;
        for (int j = 0; j < m; ++j)
            if (know[v][j] && know[to][j])
                ok = true;
        if (ok)
            dfs(to);
    }
}

void solve()
{
    fill(used, used + N, 0);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            know[i][j] = false;

    bool zero = true;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        if (k > 0)
            zero = false;
        for (int j = 0; j < k; ++j)
        {
            int lang;
            cin >> lang;
            --lang;
            know[i][lang] = true;
        }
    }
    if (zero)
    {
        cout << n;
        return;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (!used[i])
        {
            dfs(i);
            ++cnt;
        }
    cout << cnt - 1;
}


int main()
{
    ios_base::sync_with_stdio(0);

    //openFiles();
    solve();

    return 0;
}