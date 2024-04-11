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

int n, nxt[100005], arr[100005], oldsize;
set<int, greater<int>> st;

signed main()
{
    //fast;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        nxt[i] = i + 1;
        st.insert(i);
    }
    cin >> arr[n];
    for (int j = 1; j < n; j++)
        if (arr[j] < arr[nxt[j]])
            st.erase(j);
    for (int i = 0;; i++)
    {
        //for (int j : st)
        //    cout << j << " ";
        //cout << '\n';
        vector<int> v;
        for (int j : st)
            if (arr[j] < arr[nxt[j]])
                v.pb(j);
        for (int j : v)
            st.erase(j);
        v.clear();
        if (st.size() == 0)
        {
            cout << i;
            return 0;
        }
        for (int j : st)
        {
            if (arr[j] < arr[nxt[j]])
                v.pb(j);
            if (arr[j] > arr[nxt[j]])
            {
                v.pb(nxt[j]);
                nxt[j] = nxt[nxt[j]];
                if (nxt[j] == 0)
                    v.pb(j);
            }
        }
        for (int j : v)
            st.erase(j);
    }
}