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

const int INF = 2 * 1000 * 1000 * 1000 + 10;
const int N = 100 * 1000 + 10;
long long pref_min[N];
long long pref_max[N];
long long suf_min[N];
long long suf_max[N];
int n;

struct point
{
    long long x, y;
    point() {}
    point(long long _x, long long _y): x(_x), y(_y) {}
};

point p[N];

bool cmp(point a, point b)
{
    return a.x < b.x;
}

bool check(double w)
{
    w *= 2;
    for (int l = 0, r = 0; l < n; l++)
    {
        while (r + 1 < n && p[r + 1].x - p[l].x <= w)
            r++;
        long long mn = INF;
        long long mx = -INF;
        if (l)
        {
            mn = pref_min[l - 1];
            mx = pref_max[l - 1];
        }
        if (r + 1 < n)
        {
            mn = min(mn, suf_min[r + 1]);
            mx = max(mx, suf_max[r + 1]);
        }
        if (mx - mn <= w)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        p[i] = point(x + y, x - y);
    }

    sort(p, p + n, cmp);
    for (int i = 0; i < n; i++)
    {
        pref_min[i] = p[i].y;
        pref_max[i] = p[i].y;
        if (i)
        {
            pref_min[i] = min(pref_min[i], pref_min[i - 1]);
            pref_max[i] = max(pref_max[i], pref_max[i - 1]);
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        suf_min[i] = p[i].y;
        suf_max[i] = p[i].y;
        if (i < n - 1)
        {
            suf_min[i] = min(suf_min[i], suf_min[i + 1]);
            suf_max[i] = max(suf_max[i], suf_max[i + 1]);
        }
    }

    double l = 0;
    double r = 2e9;
    for (int it = 0; it < 150; it++)
    {
        double m = (l + r) / 2;
        if (check(m))
            r = m;
        else
            l = m;
    }

    cout.setf(ios::fixed);
    cout.precision(10);
    cout << r;

    return 0;
}