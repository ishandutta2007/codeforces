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

int N, T, M;
signed main()
{
    fast;
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        string s;
        cin >> s;
        for (int i = 1; i <= M; i++)
        {
            bool b = 0;
            string t = s;
            if (s[0] == '0' && s[1] == '1')
                t[0] = '1', b = 1;
            if (s[N - 1] == '0' && s[N - 2] == '1')
                t[N - 1] = '1', b = 1;
            
            for (int j = 1; j < N - 1;j++)
                if((s[j - 1] == '1') ^ (s[j + 1] == '1'))
                    if(s[j] == '0')
                        t[j] = '1', b = 1;
            s = t;
            if(!b)
                break;
        }
        cout << s << '\n';
    }
}