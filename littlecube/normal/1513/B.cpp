/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
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

int t, n, a[200005], frac[200005];
signed main()
{
    fast;
    frac[1] = 1;
    for (int i = 2; i <= 200000; i++)
        frac[i] = frac[i - 1] * i % MOD;
    cin >> t;
    while (t--)
    {
        cin >> n;
        bool cal[200005] = {0};
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if(n == 2)
        {
            if(a[1] == a[2])
                cout << 2 << '\n';
            else
                cout << 0 << '\n';
            continue;
        }

        for (int i = 0; i <= 30; i++)
        {
            bool is0 = 1, is1 = 1;
            for (int j = 1; j <= n; j++)
                if (a[j] & (1LL << i))
                    is0 = 0;
                else
                    is1 = 0;
            if (!is0 && !is1)
            {
                for (int j = 1; j <= n; j++)
                    if (a[j] & (1LL << i))
                        cal[j] = 1;
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n;i++)
            cnt += cal[i];
        
        cout << (frac[n] - (2 * cnt * frac[n - 1] % MOD) + (cnt * (cnt - 1) * frac[n - 2] % MOD) + MOD) % MOD << '\n';
    }
}

//A B O
//0 0 0
//0 1 0
//1 0 0
//1 1 1