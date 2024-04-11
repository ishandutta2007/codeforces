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
#define int long long
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
//using namespace __gnu_pbds;

#define LOCAL

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> &val)
{
    for (T &iter : val)
        is >> iter;
    return is;
}

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

ll N, dp[1000005], ans;

struct line
{
    ll a, b;
    line(ll a, ll b) : a(a), b(b){};
    line() : a(0), b(0){};
    ll val(ll x)
    {
        return a * x + b;
    }
};

ll point(line l1, line l2)
{
    assert(l2.a - l1.a != 0);
    return (l1.b - l2.b) / (l2.a - l1.a);
}

bool intPoint(line l1, line l2)
{
    assert(l2.a - l1.a != 0);
    return ((l1.b - l2.b) % (l2.a - l1.a)) ? 1 : 0;
}

line dq[1000005];
int ldx = 0, rdx = 0;

signed main()
{
    dq[0] = line(0, 0);
    fast;
    cin >> N;
    vector<pair<pll, ll>> v(N);
    cin >> v;
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
    {
        //cout << v[i].F.F << '\n';

        if (rdx < ldx)
            dp[i] = v[i].F.F * v[i].F.S - v[i].S;
        else
        {
            while (rdx - ldx >= 1 && point(dq[ldx], dq[ldx + 1]) >= v[i].F.S)
            {
                //cout << point(dq[ldx], dq[ldx + 1]) << '\n';
                //cout << "pop front\n";
                ldx++;
            }
            dp[i] = dq[ldx].val(v[i].F.S) + v[i].F.F * v[i].F.S - v[i].S;
        }
        line l = line(-v[i].F.F, dp[i]);
        while (rdx - ldx >= 1 && point(dq[rdx - 1], dq[rdx]) - point(dq[rdx], l) <= 0)
        {
            //cout << point(dq[rdx - 1], dq[rdx]) - point(dq[rdx], l);
            //cout << "pop back\n";
            rdx--;
        }
        //cout << "push back\n";
        dq[++rdx] = l;
    }
    for (int i = 0; i < N; i++)
    {
        //cout << dp[i] << " ";
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}

/*
5
10 4 5
9 5 12
6 7 10
3 8 6
2 9 9
*/