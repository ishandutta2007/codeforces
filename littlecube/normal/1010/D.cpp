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
// using namespace __gnu_pbds;

int n, val[1000006];
string s[1000006];
vector<int> E[1000006];
vector<int> add[1000006], sub[1000006];

void mg(vector<int> &v1, vector<int> &v2)
{
    if (v1.size() < v2.size())
        v1.swap(v2);
    for (int i : v2)
        v1.emplace_back(i);
}

void dfs(int u)
{
    if (s[u] == "IN")
        return;
    
    for (int v : E[u])
        dfs(v);
    if (s[u] == "NOT")
    {
        val[u] = (val[E[u][0]] ? 0 : 1);
        add[u].swap(sub[E[u][0]]);
        sub[u].swap(add[E[u][0]]);
    }
    else if (s[u] == "XOR")
    {
        val[u] = (val[E[u][0]] ? 1 : 0) ^ (val[E[u][1]] ? 1 : 0);
        mg(add[E[u][0]], add[E[u][1]]);
        mg(add[E[u][0]], sub[E[u][0]]);
        mg(add[E[u][0]], sub[E[u][1]]);
        if (val[u])
            sub[u].swap(add[E[u][0]]);
        else
            add[u].swap(add[E[u][0]]);
    }
    else
    {
        val[u] = (val[E[u][0]] ? 1 : 0) + (val[E[u][1]] ? 1 : 0);
        if (s[u] == "AND" && val[u] == 2)
        {
            mg(sub[E[u][0]], sub[E[u][1]]);
            sub[u].swap(sub[E[u][0]]);
        }
        if (s[u] == "AND" && val[u] == 1)
        {
            mg(add[E[u][0]], add[E[u][1]]);
            add[u].swap(add[E[u][0]]);
        }
        if (s[u] == "OR" && val[u] == 1)
        {
            mg(sub[E[u][0]], sub[E[u][1]]);
            sub[u].swap(sub[E[u][0]]);
        }
        if (s[u] == "OR" && val[u] == 0)
        {
            mg(add[E[u][0]], add[E[u][1]]);
            add[u].swap(add[E[u][0]]);
        }
        if(s[u] == "AND")
            val[u] /= 2;
        
    }
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        if (s[i] == "NOT")
        {
            E[i].resize(1);
            cin >> E[i][0];
        }
        else if (s[i] == "IN")
        {
            cin >> val[i];

            if (val[i] == 1)
                sub[i].emplace_back(i);
            else
                add[i].emplace_back(i);
        }
        else
        {
            E[i].resize(2);
            cin >> E[i][0] >> E[i][1];
        }
    }
    dfs(1);
    for (int i = 2; i <= n; i++)
        val[i] = (val[1] ? 1 : 0);
    for (int i : add[1])
        val[i]++;
    for (int i : sub[1])
        val[i]--;
    for (int i = 2; i <= n; i++)
        if (s[i] == "IN")
            cout << val[i];
}