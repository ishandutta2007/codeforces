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
signed main()
{
    fast;
    cin >> t;
    while (t--)
    {

        string s;
        vector<int> a, b;
        int A = 0, B = 0, onecnt = 0;
        bool pos = 1;

        cin >> n >> s;
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
                onecnt++;
        if (onecnt % 2)
        {
            cout << "NO\n";
            continue;
        }
        onecnt /= 2;
        int i = 0;
        for (; onecnt > 0; i++)
        {
            if (s[i] == '1')
            {
                onecnt--;
                a.pb(1);
                b.pb(1);
                A++;
                B++;
            }
            else
            {
                if (A == B)
                {
                    a.pb(1);
                    b.pb(-1);
                    A++;
                    B--;
                }
                else if (B > A)
                {
                    a.pb(1);
                    b.pb(-1);
                    A++;
                    B--;
                }
                else
                {
                    a.pb(-1);
                    b.pb(1);
                    A--;
                    B++;
                }
            }
            if (A < 0 || B < 0)
                pos = 0;
        }
        for (; i < n; i++)
        {
            if (s[i] == '1')
            {
                a.pb(-1);
                b.pb(-1);
                A--;
                B--;
            }
            else
            {
                if (A == B)
                {
                    a.pb(1);
                    b.pb(-1);
                    A++;
                    B--;
                }
                else if (B > A)
                {
                    a.pb(1);
                    b.pb(-1);
                    A++;
                    B--;
                }
                else
                {
                    a.pb(-1);
                    b.pb(1);
                    A--;
                    B++;
                }
            }
            if (A < 0 || B < 0)
                pos = 0;
        }
        if (pos && A == 0 && B == 0)
        {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
                if (a[i] == 1)
                    cout << "(";
                else
                    cout << ")";
            cout << '\n';
            for (int i = 0; i < n; i++)
                if (b[i] == 1)
                    cout << "(";
                else
                    cout << ")";
            cout << '\n';
        }
        else
            cout << "NO\n";
    }
}
//1111110100001010101111101010101111100111
//(((((()(()()((()((((())))()))()))))))))(