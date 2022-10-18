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

ll n, m, t[100005], sum[100005], k[100005];

// 0 => -1, 1 => 0, 2 => 1
int can[100005][3];

vector<ll> s[100005], order, revorder;

void solve()
{
    cin >> n >> m;
    for (int i = 0; i <= n + 2; i++)
        t[i] = 0;
    for (int i = 0; i <= m + 2; i++)
    {
        sum[i] = k[i] = can[i][0] = can[i][1] = can[i][2] = 0;
        s[i].clear();
    }
    order.clear();
    revorder.clear();

    for (int i = 1; i <= n; i++)
        cin >> t[i];
    sort(t + 1, t + 1 + n);
    //for (int i = 1; i <= n; i++)
    //    cout << t[i] << " \n"[i == n];
    for (int i = 1; i <= m; i++)
    {
        cin >> k[i];
        s[i].resize(k[i]);
        for (int j = 0; j < k[i]; j++)
        {
            cin >> s[i][j];
            sum[i] += s[i][j];
        }
    }
    order.resize(m + 1);
    revorder.resize(m + 1);
    for (int i = 1; i <= m; i++)
        order[i] = i;
    sort(order.begin() + 1, order.end(), [&](int i1, int i2)
         { return sum[i1] * k[i2] < sum[i2] * k[i1]; });

    for (int i = 1; i <= m; i++)
        revorder[order[i]] = i;

    for (int o = -1; o <= 1; o++)
        for (int i = 1; i <= m; i++)
        {
            int tdx = i - m + n + o;
            if (k[order[i]] * t[tdx] >= sum[order[i]])
                can[i][o + 1] = 1;
            else
                can[i][o + 1] = 0;
        }
    //for (int i = 1; i <= m; i++)
    //    cout << order[i] << " \n"[i == m];
    //for (int o = -1; o <= 1; o++)
    //    for (int i = 1; i <= m; i++)
    //        cout << can[i][o + 1] << " \n"[i == m];
    for (int o = -1; o <= 1; o++)
        for (int i = 1; i <= m; i++)
            can[i][o + 1] += can[i - 1][o + 1];
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < k[i]; j++)
        {
            k[m + 1] = k[i] - 1;
            sum[m + 1] = sum[i] - s[i][j];
            //cout << "k " << k[m + 1] << " sum " << sum[m + 1] << " ";
            int low = lower_bound(order.begin() + 1, order.end(), m + 1, [&](int i1, int i2)
                                  { return sum[i1] * k[i2] < sum[i2] * k[i1]; }) -
                      order.begin(),
                cur = revorder[i];
            //cout << i << " " << j << " low " << low << " cur " << cur << '\n';
            if (low > cur + 1)
            {
                low--;
                int tdx = low - m + n;
                if (can[m][1] - can[low][1] + can[low][0] - can[cur][0] + (int)(k[m + 1] * t[tdx] >= sum[m + 1]) + can[cur - 1][1] - can[0][1] == m)
                    cout << '1';
                else
                    cout << '0';
            }
            else if (low == cur || low == cur + 1)
            {
                int tdx = cur - m + n;
                //cout << "low == cur " << can[m][1] - can[cur][1] << " " << (int)(k[m + 1] * t[tdx] >= sum[m + 1]) << " "
                //      << can[cur - 1][1] - can[0][1] << '\n';
                if (can[m][1] - can[cur][1] + (int)(k[m + 1] * t[tdx] >= sum[m + 1]) + can[cur - 1][1] - can[0][1] == m)
                    cout << '1';
                else
                    cout << '0';
            }
            else
            {
                int tdx = low - m + n;
                //cout << can[m][1] - can[cur][1] << " " << can[cur][2] - can[low][2] << " " << (int)(k[m + 1] * t[tdx] >= sum[m + 1]) << " " << can[low - 1][1] - can[0][1] << '\n';
                if (can[m][1] - can[cur][1] + (int)(k[m + 1] * t[tdx] >= sum[m + 1]) + can[cur - 1][2] - can[low - 1][2] + can[low - 1][1] - can[0][1] == m)
                    cout << '1';
                else
                    cout << '0';
            }
        }
    cout << '\n';
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
1
3 3
4 3 5
3 1 4 3
2 3 5
3 3 6 6



*/