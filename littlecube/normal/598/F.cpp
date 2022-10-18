/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using namespace __gnu_pbds;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll N, M, K;
pdd point[100005];

struct line
{
    //ax + by = c
    double a, b, c;
    line() : a(0), b(0), c(0){};
    line(double a, double b, double c) : a(a), b(b), c(c){};
};

line twoDots(pdd p1, pdd p2)
{
    return line(p1.S - p2.S, p2.F - p1.F, -p1.F * (p2.S - p1.S) + -p1.S * (p1.F - p2.F));
}

pdd twoLine(line l1, line l2)
{
    return make_pair(double(l1.c * l2.b - l2.c * l1.b) / double(l2.b * l1.a - l1.b * l2.a), double(l1.c * l2.a - l2.c * l1.a) / double(l2.a * l1.b - l1.a * l2.b));
}

int onLine(line l, pdd p)
{
    if (abs(l.a * p.F + l.b * p.S - l.c) <= 1e-6)
        return 0;
    if (l.a * p.F + l.b * p.S > l.c)
        return 1;
    if (l.a * p.F + l.b * p.S < l.c)
        return -1;
}

signed main()
{
    fast;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> point[i].F >> point[i].S;

    while (M--)
    {
        pdd d1, d2;
        double ans = 0;

        cin >> d1.F >> d1.S >> d2.F >> d2.S;

        line l = twoDots(d1, d2);

        vector<pair<pdd, int>> v;

        for (int i = 0; i < N; i++)
        {
            line pl = twoDots(point[i], point[(i + 1) % N]);
            pdd p = twoLine(l, pl);

            if (onLine(l, point[(i + 1) % N]) == 0 && onLine(l, point[i]) * onLine(l, point[(i + 2) % N]) != 1)
            {
                int sgn = 0;
                if (onLine(l, point[(i + 2) % N]) == 1 || onLine(l, point[i % N]) == 1)
                    sgn ^= 2;
                if (onLine(l, point[(i + 2) % N]) == -1 || onLine(l, point[i % N]) == -1)
                    sgn ^= 1;
                v.emplace_back(make_pair(point[(i + 1) % N], sgn));
            }
            else if (onLine(l, point[i]) * onLine(l, point[(i + 1) % N]) == -1)
            {
                if (min(point[i].F, point[(i + 1) % N].F) - 1e-6 <= p.F && p.F <= max(point[i].F, point[(i + 1) % N].F) + 1e-6 &&
                    min(point[i].S, point[(i + 1) % N].S) - 1e-6 <= p.S && p.S <= max(point[i].S, point[(i + 1) % N].S) + 1e-6)
                    v.emplace_back(make_pair(p, 3));
            }
        }

        sort(v.begin(), v.end());

        for (int i = 0, j = 0; i < (int)v.size() - 1; i++)
        {
            j ^= v[i].S;
            if (j)
                ans += sqrt((v[i].F.F - v[i + 1].F.F) * (v[i].F.F - v[i + 1].F.F) + (v[i].F.S - v[i + 1].F.S) * (v[i].F.S - v[i + 1].F.S));
        }

        cout << fixed << setprecision(18) << ans << '\n';
    }
}

/*
6 1
0 0
0 2
2 2
2 0
1 0.5
1 0
0 0.5 1 0.5
*/