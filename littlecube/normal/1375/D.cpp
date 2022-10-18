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

int N, T, M;
signed main()
{
    fast;
    cin >> T;
    while (T--)
    {
        int a[1005] = {0}, b[1005] = {0}, cnt[1005] = {0};
        vector<int> v;
        auto mex = [&]()
        {
            for (int i = 0; i <= N; i++)
                if (cnt[i] == 0)
                    return i;
        };
        auto mexid = [&]()
        {
            for (int i = 0; i < N; i++)
                if (b[i] == 0)
                    return i;
        };

        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }

        for (int i = 0; i < N; i++)
        {
            int m = mex(), mi = mexid();
            if (m == N)
            {
                m = a[mi];
                cnt[a[mi]]--;
                a[mi] = N;
                cnt[N]++;
                v.pb(mi);
            }
            cnt[a[m]]--;
            a[m] = m;
            cnt[m]++;
            b[m] = 1;
            v.pb(m);
        }
        cout << v.size() << '\n';
        for (int i : v)
            cout << i + 1 << " ";
        cout << '\n';
    }
}

/*
8 4 7 6 1 2 3 0 5

*/