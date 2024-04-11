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

int t, n;
string a, b, c;

bool solve(string a, string b, char c)
{
    int i = 0, j = 0, cnt = 0;
    for (; i < 2 * n && j < 2 * n;)
    {
        if (a[i] == c && b[j] == c)
        {
            cout << c;
            i++, j++;
        }
        else if (a[i] != c)
        {
            cout << a[i];
            i++;
        }
        else if (b[j] != c)
        {
            cout << b[j];
            j++;
        }
        cnt++;
    }
    for (; i < 2 * n; i++)
    {
        cout << a[i];
        cnt++;
    }
    for (; j < 2 * n; j++)
    {
        cout << b[j];
        cnt++;
    }
    for (; cnt < 3 * n; cnt++)
        cout << 0;
    cout << '\n';
    return 0;
}

signed main()
{
    fast;

    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> a >> b >> c;
        int x = 0, y = 0, z = 0;
        for (int i = 0; i < 2 * n; i++)
            if (a[i] == '0')
                x++;
            else
                x--;
        for (int i = 0; i < 2 * n; i++)
            if (b[i] == '0')
                y++;
            else
                y--;
        for (int i = 0; i < 2 * n; i++)
            if (c[i] == '0')
                z++;
            else
                z--;
        if (x * y >= 0)
            solve(a, b, x + y >= 0 ? '0' : '1');
        else if (x * z >= 0)
            solve(a, c, x + z >= 0 ? '0' : '1');
        else
            solve(c, b, y + z >= 0 ? '0' : '1');
    }
}