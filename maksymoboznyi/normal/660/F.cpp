#include <bits/stdc++.h>
#define pb push_back
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define int long long
using namespace std;

const int N = 5e5 + 5;

struct Line
{
    long long k, b;
};

struct Point
{
    long double x, y;
};

vector<Line> v;
int n;
long long a[N], pref[N], sum[N];
long double x[N];

Point inter(Line a, Line b)
{
    Point res;
    res.y = 0;
    res.x = a.b - b.b;
    int del = b.k - a.k;
    res.x /= del;
    return res;
}

long double f(long double x, Line l)
{
    return l.k * x + l.b;
}

void add(Line l)
{
    while (!v.empty() && f(-x[v.size() - 1], v.back()) <= f(-x[v.size() - 1], l))
    {
        x[v.size() - 1] = -1000000000000000;
        v.pop_back();
    }

    if (v.empty())
    {
        x[0] = -1000000000000000;
        v.pb(l);
        return;
    }
    Point p = inter(v.back(), l);
    v.pb(l);
    x[v.size() - 1] = -p.x;
    return;
}

long long get(long long xp)
{
    int pos = upper_bound(x, x + v.size(), -xp) - x - 1;
    if (pos == -1)
    {
        pos = 0;
    }
    return v[pos].k * xp + v[pos].b;//f(xp, v[pos]);
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        sum[i] = sum[i - 1] + a[i] * i;
    }
    long long ans = 0;
    ans = max(ans, sum[1]);
    add({0, 0});
    for (int i = 1; i <= n; i++) {
       /* for (int j = 0; j < v.size(); j++)
            cout << x[j] << ' ' << v[j].k << ' ' << v[j].b << endl;
        cout << endl;
        */ans = max(ans, get(pref[i]) + sum[i]);
        add({-i, -sum[i] + pref[i] * (i)});
    }
    cout << ans;
    return 0;
}