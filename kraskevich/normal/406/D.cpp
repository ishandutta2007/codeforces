#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

const int N = (int)2e5;

vector<int> g[N];
int go[N][19];
vector<bool> u;
int tin[N];
int tout[N];
int timer = 0;
int n;

void dfs(int v)
{
    //cerr << v << " ";
    tin[v] = timer++;
    u[v] = true;
    for (int i = 1; i < 19; i++)
        go[v][i] = go[go[v][i - 1]][i - 1];
    for (int to : g[v])
        if (!u[to])
            dfs(to);
    tout[v] = timer++;
}

bool anc(int a, int b)
{
    return tin[a] <= tin[b] && tin[b] <= tout[a];
}

int lca(int a, int b)
{
    if (anc(a, b))
        return a;
    if (anc(b, a))
        return b;
    for (int i = 18; i >= 0; i--)
        if (!anc(go[a][i], b))
            a = go[a][i];
    return go[a][0];
}

struct Point
{
    long long x;
    long long y;

    Point() {}
    Point(long long _x, long long _y): x(_x), y(_y) {}

    Point operator - (Point p)
    {
        return Point(x - p.x, y - p.y);
    }

    long long operator * (Point p)
    {
        return x * p.y - y * p.x;
    }
};

Point p[N];
vector<int> hull;

void pop(int v)
{
    while (hull.size() >= 2)
    {
        int mid = hull.back();
        int old = hull[hull.size() - 2];
        Point a = p[old] - p[v];
        Point b = p[mid] - p[v];
        if (a * b >=  0)
            break;
        hull.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
    go[n - 1][0] = n - 1;
    hull.push_back(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        pop(i);
        go[i][0] = hull.back();
        //cerr << i << " " << go[i][0] << endl;
        hull.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        g[i].push_back(go[i][0]);
        g[go[i][0]].push_back(i);
    }
    u.assign(n, 0);
    dfs(n - 1);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        cout << lca(a, b) + 1 << "\n";
    }
    return 0;
}