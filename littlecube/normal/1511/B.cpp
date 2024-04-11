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

int t, a, b, c;
signed main()
{
    fast;

    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        int pA = 1, pB = 1, A, B, C = 1;
        for (int i = 1; i < c; i++)
            C *= 10;
        if (C % 2 == 0)
            C++;
        A = B = C;
        for (int i = 1; i < a; i++)
            pA *= 10;
        for (int i = 1; i < b; i++)
            pB *= 10;
        while(B < pB)
            B *= 2;
        while(A < pA)
            A *= 3;
        cout << A << " " << B << '\n';
    }
}