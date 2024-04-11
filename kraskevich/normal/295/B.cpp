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

#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second
#define MP make_pair

const int N = 500 + 10;
const int INF = 1000 * 1000 * 1000;
int e[N][N];
int d[N][N];
int x[N];
long long ans[N];
bool in[N];
int n;

void add(int v, int step)
{
    in[v] = true;
    for (int i = 0; i < n; ++i)
        for (int mid = 0; mid < n; ++mid)
            if (in[i] && in[mid])
                d[i][v] = min(d[i][v], d[i][mid] + e[mid][v]);
    for (int i = 0; i < n; ++i)
        for (int mid = 0; mid < n; ++mid)
            if (in[i] && in[mid])
                d[v][i] = min(d[v][i], e[v][mid] + d[mid][i]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (in[i] && in[j])
                d[i][j] = min(d[i][j], d[i][v] + d[v][j]);
    ans[step] = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (in[i] && in[j])
                ans[step] += (long long)d[i][j];
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> e[i][j];
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
        --x[i];
    }

    fill(in, in + n, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;

    for (int i = n - 1; i >= 0; --i)
        add(x[i], i);

    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}