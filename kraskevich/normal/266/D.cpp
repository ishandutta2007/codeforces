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
#define pdi pair<double, int>

const int N = 222;
const int inf = 1000 * 1000 * 1000;
const double eps = 1e-9;
pii edge[200 * 200];
int w[200 * 200];
int d[N][N];
int n, m;

void init()
{
    for (int i = 0; i < N; ++i)
        fill(d[i], d[i] + N, inf);
    for (int i = 0; i < N; ++i)
        d[i][i] = 0;
}

void calc_dist()
{
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

double res = 1e9;
double x[N];
pdi e[N];

double get_y(double a, double b, double bod)
{
    double x = (b - a) / 2;
    double y = x + a;
    if (x < 0 || x > bod)
        y = 1e9;
    return y;
}

void solve()
{
    for (int i = 0; i < m; ++i)
    {
        int l = -1, r = -1, mid = -1;
        int from = edge[i].F;
        int to = edge[i].S;

        for (int v = 0; v < n; ++v)
        {
            double left = d[from][v];
            double right = d[to][v];
            double curw = w[i];
            x[v] = (-left + right + curw) / 2.0;
            x[v] = min(x[v], curw);
            x[v] = max(x[v], 0.0);
        }

        for (int v = 0; v < n; ++v)
            if (l == -1 || d[l][from] < d[v][from])
                l = v;
        double cur = d[l][from];

        for (int v = 0; v < n; ++v)
            if (r == -1 || d[r][to] < d[v][to])
                r = v;
        cur = min(cur, (double)d[r][to]);

        multiset<int> up, down;
        for (int v = 0; v < n; ++v)
            if (x[v] > 1e-9)
                up.insert(-d[v][from]);
        for (int v = 0; v < n; ++v)
            if (x[v] < 1e-9)
                down.insert(-d[v][to] - w[i]);

        for (int v = 0; v < n; ++v)
            e[v] = pdi(x[v], v);
        sort(e, e + n);

        for (int v = 0; v < n; ++v)
        {
            if (up.size() && down.size())
                cur = min(cur, get_y(-(*up.begin()), -(*down.begin()), 0.0 + w[i]));
            int curv = e[v].S;
            if (x[curv] > eps)
            {
                up.erase(up.find(-d[curv][from]));
                down.insert(-d[curv][to] - w[i]);
            }
        }
        if (up.size() && down.size())
            cur = min(cur, get_y(-(*up.begin()), -(*down.begin()), 0.0 + w[i]));

        res = min(res, cur);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    init();

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b, curw;
        cin >> a >> b >> curw;
        --a;
        --b;
        edge[i] = pii(a, b);
        d[a][b] = d[b][a] = curw;
        w[i] = curw;
    }

    calc_dist();
    solve();

    cout.setf(ios::fixed);
    cout.precision(10);
    cout << res;

    return 0;
}