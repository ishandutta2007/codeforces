#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long LL;
typedef long double ld;
#define MP make_pair
#define F first
#define S second

long long sqr(long long a)
{
    return a * a;
}

long long dist(pii a, pii b)
{
    return sqr(a.F - b.F) + sqr(a.S - b.S);
}


int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<pll> a;
    vector<pll> o;
    LL s = 0;
    for (int i = 1; i <= n; i++)
    {
        LL v;
        cin >> v;
        s += v;
        a.push_back(pll(i, s));
        o.push_back(pll(s, i));
    }
    long long res = dist(a[0], a[1]);
    set<pll> pt;
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        long long d = ((long long)(sqrt(res) + 1e-7)) + 1;
        while (l < i && a[i].F - a[l].F > d)
        {
            pt.erase(o[l]);
            l++;
        }
        auto lo = pt.lower_bound(pll(a[i].S - d, 0));
        auto hi = pt.upper_bound(pll(a[i].S + d, n + 1));
        while (lo != hi)
        {
            res = min(res, dist(o[i], *lo));
            lo++;
        }
        pt.insert(o[i]);
    }

    cout << res;

    return 0;
}