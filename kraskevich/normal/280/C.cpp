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

const int N = 100 * 1000 + 10;
vector<int> g[N];
int h[N], n;
bool used[N];

void dfs(int v, int curh)
{
    h[v] = curh;
    used[v] = true;
    for (int i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (!used[to])
            dfs(to, curh + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    fill(used, used + n, false);
    dfs(0, 0);

    double res = 0;
    for (int i = 0; i < n; ++i)
        res += 1.0 / (h[i] + 1);

    cout.setf(ios::fixed);
    cout.precision(10);

    cout << res;

    return 0;
}