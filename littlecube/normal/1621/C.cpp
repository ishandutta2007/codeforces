/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
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
istream &operator>>(istream &is, pair<T, U> val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> val)
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

int p[10005];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        p[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == 0)
        {
            int u, v;
            cout << "? " << i << endl;
            cin >> u;
            while (p[u] == 0)
            {
                cout << "? " << i << endl;
                cin >> v;
                p[u] = v;
                u = v;
            }
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++)
    {
        cout << p[i];
        if (i != n)
            cout << " ";
        else
            cout << endl;
    }
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}

/*
p 2 3 1 5 4
q

1 2 3 4 5
2 3 1 5 4
3 1 2 4 5
1 2 3 5 4
2 3 1 4 5
3 1 2 5 4

*/