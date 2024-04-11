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

ll T, N, M, K, arr[1000005];
string s;
vector<int> v;

int transfer(char c)
{
    if (c == '<')
        return 1;
    if (c == '>')
        return -1;
    if (c == '{')
        return 2;
    if (c == '}')
        return -2;
    if (c == '[')
        return 3;
    if (c == ']')
        return -3;
    if (c == '(')
        return 4;
    if (c == ')')
        return -4;
}

signed main()
{
    fast;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (v.empty())
            v.pb(transfer(s[i]));
        else if (transfer(s[i]) < 0 && v.back() > 0)
        {
            if (transfer(s[i]) + v.back() != 0)
                N++;
            v.pop_back();
        }
        else
            v.pb(transfer(s[i]));
    }
    if (!v.empty())
        cout << "Impossible";
    else
        cout << N;
}