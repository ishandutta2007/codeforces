/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
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
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

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

const int cyc = 34;
int sg[500] = {0, 1, 1};

int getSG(int k)
{
    if (k <= 200)
        return sg[k];
    else
        return sg[(k % cyc) + 3 * cyc];
}

signed main()
{
    fast;
    for (int i = 3; i < 500; i++)
    {
        int mex[20] = {};
        for (int j = 1; j <= i; j++)
        {
            int L = max(0, j - 2), R = max(0, i - j - 1);
            mex[sg[L] ^ sg[R]] = 1;
        }
        for (int j = 0; j < 20; j++)
            if (!mex[j])
            {
                sg[i] = j;
                break;
            }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, b = 0, r = 0;
        string s;
        cin >> n >> s;
        for (auto c : s)
            if (c == 'B')
                b++;
            else
                r++;
        if (b > r)
            cout << "Bob\n";
        else if (b < r)
            cout << "Alice\n";
        else
        {
            int nim = 0;
            int cur = 0;
            for (int i = 1; i < n; i++)
                if (s[i - 1] != s[i])
                    cur++;
                else
                {
                    nim ^= getSG(cur);
                    cur = 0;
                }
            nim ^= getSG(cur);
            if (nim)
                cout << "Alice\n";
            else
                cout << "Bob\n";
        }
    }
}

// R-B-R-B-R-B-R-B B B-RR