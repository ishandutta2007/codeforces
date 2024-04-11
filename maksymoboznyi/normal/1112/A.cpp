#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

const int N = 5e5 + 5;
const long long M = 1e9 + 7;
const double eps = 1e-8;

int n, m, k, used[N], p[N];
vector<int> s[N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s[x].pb(i);
    }
    for (int i = 1; i <= m; i++)
    {
        int x = -1;
        for (int j = 0; j < s[i].size(); j++)
            if (x == -1 || p[x] < p[s[i][j]])
                x = s[i][j];
        used[x] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        if (!used[x])
            ans++;
    }
    cout << ans;
    return 0;
}