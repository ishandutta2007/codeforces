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

int ABS(int a)
{
    return a > 0 ? a : -a;
}

struct point
{
    int x, y;
    point() {}
    void read() { cin >> x >> y; }
};

int get_dist(point a, point b)
{
    return ABS(a.x - b.x) + ABS(a.y - b.y);
}

const int INF = 1000 * 1000 * 1000;
const int N = 111;
point p[N];
int a[N];
int dist[N];
bool was[N];
int n, d;

bool check()
{
    fill(dist, dist + n, INF);
    fill(was, was + n, false);
    dist[0] = 0;
    for (;;)
    {
        int v = -1;
        for (int i = 0; i < n; ++i)
            if (!was[i] && (v == -1 || dist[v] > dist[i]))
                v = i;
        if (v == -1 || dist[v] > 0)
            break;
        was[v] = true;
        for (int i = 0; i < n; ++i)
        {
            if (i == v)
                continue;
            int cand = dist[v] + d * get_dist(p[v], p[i]) - a[v];
            if (cand < dist[i])
                dist[i] = cand;
        }
    }
    return dist[n - 1] <= 0;
}


int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> d;
    for (int i = 1; i < n - 1; i++)
        cin >> a[i];
    a[0] = a[n - 1] = 0;
    for (int i = 0; i < n; ++i)
        p[i].read();

    int l = 0;
    int r = 100 * 1000 * 1000;
    while (l < r)
    {
        int m = (l + r) / 2;
        a[0] = m;
        if (check())
            r = m;
        else
            l = m + 1;
    }

    cout << l;

    return 0;
}