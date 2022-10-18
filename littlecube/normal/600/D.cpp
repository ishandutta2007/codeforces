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

signed main()
{
    fast;
    long double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    if(r1 > r2)
    {
        swap(x1, x2);
        swap(y1, y2);
        swap(r1, r2);
    }
    
    long double dis = sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    cout << fixed << setprecision(20);
    if (dis > r1 + r2)
        cout << 0.0 << '\n';
    else if (dis > r2 - r1)
    {
        
        long double theta1 = acosl((r1 * r1 + (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) - r2 * r2) / ((long double)2.000000 * dis * r1));
        long double theta2 = acosl((r2 * r2 + (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) - r1 * r1) / ((long double)2.000000 * dis * r2));

        cout << 0.5 * r1 * r1 * (2 * theta1 - sinl(2 * theta1)) + 0.5 * r2 * r2 * (2 * theta2 - sinl(2 * theta2))  << '\n';
    }
    else
        cout << r1 * r1 * acosl((long double)-1) << '\n';
}