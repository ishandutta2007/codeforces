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
#define i128 __int128
#define pii pair<int, int>
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

ll N, M, K, mini, order[100005];
__int128 mindot = -10000000000000, mindis = 10000000000000000;
pair<long double, long double> arr[100005];

int dim(pair<long double, long double> p1)
{
    if (p1.F >= 0 && p1.S >= 0)
        return 1;
    if (p1.F >= 0 && p1.S < 0)
        return 2;
    if (p1.F < 0 && p1.S < 0)
        return 3;
    return 4;
}

signed main()
{
    fast;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].F >> arr[i].S;
        order[i] = i;
    }

    sort(order, order + N, [](int i1, int i2)
         {
             if (dim(arr[i1]) != dim(arr[i2]))
                 return dim(arr[i1]) < dim(arr[i2]);
             else
                 return arr[i1].S * arr[i2].F > arr[i2].S * arr[i1].F;
         });

    sort(arr, arr + N, [](pair<long double, long double> p1, pair<long double, long double> p2)
         {
             if (dim(p1) != dim(p2))
                 return dim(p1) < dim(p2);
             else
                 return p1.S * p2.F > p2.S * p1.F;
         });

    for (int i = 0; i < N; i++)
    {
        __int128 dot = (arr[i].F * arr[(i + 1) % N].F + arr[i].S * arr[(i + 1) % N].S),
                 dis = ((arr[i].F * arr[i].F + arr[i].S * arr[i].S) * (arr[(i + 1) % N].F * arr[(i + 1) % N].F + arr[(i + 1) % N].S * arr[(i + 1) % N].S));
        if (dot >= 0 && mindot <= 0)
        {
            mindot = dot;
            mindis = dis;
            mini = i;
        }

        if (dot <= 0 && mindot <= 0)
            if (dot * dot * mindis < mindot * mindot * dis)
            {
                mindot = dot;
                mindis = dis;
                mini = i;
            }
        if (dot >= 0 && mindot >= 0)
            if (dot * dot * mindis > mindot * mindot * dis)
            {
                mindot = dot;
                mindis = dis;
                mini = i;
            }
    }

    cout << order[mini] + 1 << " " << order[(mini + 1) % N] + 1 << '\n';
}

/*
16
1 0
2 1
1 1
1 2
0 1
-1 2
-1 1
-2 1
-1 0
-2 -1
-1 -1
-1 -2
0 -1
1 -2
1 -1
2 -1
*/