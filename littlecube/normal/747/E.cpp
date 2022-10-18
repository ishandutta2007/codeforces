#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<string> v[1000001];
string s;
int ptr = 0, maxd = 0;

void dfs(int dis)
{
    maxd = max(maxd, dis);
    
    int k = 0, f = ptr;
    for (; ptr < s.length(); ptr++)
        if (s[ptr] == ',')
            break;
    string t = s.substr(f, ptr - f);
    ptr++;
    for (; ptr < s.length(); ptr++)
    {
        if (s[ptr] == ',')
            break;
        k = k * 10 + (s[ptr] - '0');
    }
    ptr++;
    v[dis].emplace_back(t);
    for (int i = 1; i <= k; i++)
        dfs(dis + 1);
}

signed main()
{
    fast;
    cin >> s;
    while (ptr < s.length())
        dfs(0);
    cout << maxd + 1 << '\n';
    for (int i = 0; !v[i].empty(); i++)
    {
        for (auto j : v[i])
            cout << j << " ";
        cout << '\n';
    }
}