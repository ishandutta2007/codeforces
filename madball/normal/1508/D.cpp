#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <random>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

struct Point
{
    lint x, y;
    int i, j;
    Point() {}
    Point(lint x, lint y) : x(x), y(y) {}
    Point(lint x, lint y, int i, int j) : x(x), y(y), i(i), j(j) {}
    Point operator - (const Point& p) const
    {
        return Point(x - p.x, y - p.y, i, j);
    }
    lint vct(const Point& p) const
    {
        return x * p.y - y * p.x;
    }
} ar[2020];

struct Dsu
{
    int par[2020];
    Dsu()
    {
        For(i, 2020)
            par[i] = i;
    }
    int get_par(int i)
    {
        if (par[i] == i)
            return i;
        return par[i] = get_par(par[i]);
    }
    bool merge(int a, int b)
    {
        a = get_par(a);
        b = get_par(b);
        if (a == b)
            return false;
        par[a] = b;
        return true;
    }
} dsu;

void solve()
{
    int n;
    cin >> n;
    int iougig = 0;
    For(i, n)
    {
        cin >> ar[i].x >> ar[i].y >> ar[i].j;
        --ar[i].j;
        ar[i].i = iougig;
        if (ar[i].i == ar[i].j)
        {
            --i;
            --n;
        }
        ++iougig;
    }
    For(i, n)
        if (ar[i].x < ar[0].x || ar[i].x == ar[0].x && ar[i].y < ar[0].y)
            swap(ar[0], ar[i]);
    for (int i = n - 1; i >= 0; --i)
        ar[i] = ar[i] - ar[0];
    if (n)
        sort(ar + 1, ar + n, [](Point a, Point b) { return a.vct(b) > 0; });
    For(i, n)
        dsu.merge(ar[i].i, ar[i].j);
    vector<pair<int, int>> ans;
    for (int i = 1; i + 1 < n; ++i)
        if (dsu.merge(ar[i].i, ar[i + 1].i))
        {
            swap(ar[i].j, ar[i + 1].j);
            ans.emplace_back(ar[i].i, ar[i + 1].i);
        }
    For(_, n) for (int i = 1; i < n; ++i)
        if (ar[0].j == ar[i].i)
        {
            swap(ar[0].j, ar[i].j);
            ans.emplace_back(ar[0].i, ar[i].i);
        }
    cout << sz(ans) << '\n';
    for (auto e : ans)
        cout << e.first + 1 << ' ' << e.second + 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}