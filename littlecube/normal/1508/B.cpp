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

int t, n, k;
signed main()
{
    //fast;

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if (n <= 61 && (1LL << (n - 1)) < k)
        {
            cout << -1 << '\n';
            continue;
        }
        int m = max(0LL, n - 61);
        n = min(n, 61LL);
        for (int i = 1; i <= m; i++)
            cout << i << " ";
        int arr[64] = {0};
        for (int i = 1; i <= n; i++)
        {
            int pos = ceil(log2((1LL << (n - i)) - k + 1LL));
           // cout << "position of " << m + i << " is " << pos << " (by " << (1LL << (n - i)) - k + 1LL << '\n';
            for (int j = n;; j--)
            {
                if (arr[j] == 0)
                {
                    if (pos == 0)
                    {
                        //cout << "saved " << m + i << " into " << m + j << '\n';
                        arr[j] = m + i;
                        break;
                    }
                    pos--;
                }
            }
            if(n - i - 1 >= 0)
            if(k > (1LL << (n - i - 1)))
                k -= (1LL << (n - i - 1));
        }
        for (int i = 1; i <= n; i++)
            cout << arr[i] << " ";
        cout << '\n';
    }
}


/*
n = 1
1

n = 2
1 2
2 1

n = 3

1 2 3
1 3 2
2 1 3
3 2 1

1 2 3 4
1 2 4 3
1 3 2 4
1 4 3 2
2 1 3 4
2 1 4 3
3 2 1 4
4 3 2 1


*/