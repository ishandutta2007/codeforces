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
string s;
vector<string> a, b;
signed main()
{
    fast;
    cin >> s;
    s += ',';
    int lptr = 0, rptr = 0;
    while (rptr < s.size())
    {
        if (s[rptr] != ',' && s[rptr] != ';')
            rptr++;
        else
        {
            string t = s.substr(lptr, rptr - lptr);
            bool nonzero = 0, number = 1;
            for (char i : t)
            {
                if ('1' <= i && i <= '9')
                {
                    nonzero = 1;
                    continue;
                }
                else if (nonzero && i == '0')
                    continue;
                else
                    number = 0;
            }
            if ((number || t == "0") && t != "")
                a.pb(t);
            else
                b.pb(t);

            rptr++;
            lptr = rptr;
        }
    }
    if (a.empty())
        cout << "-\n";
    else
    {
        cout << "\"";
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << ",\""[i == a.size() - 1];
        cout << '\n';
    }
    if (b.empty())
        cout << "-\n";
    else
    {
        cout << "\"";
        for (int i = 0; i < b.size(); i++)
            cout << b[i] << ",\""[i == b.size() - 1];
        cout << '\n';
    }

}