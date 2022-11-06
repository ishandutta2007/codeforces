#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int N = 2e5 + 5;
const long long inf = 2e18;
const long long M = 1e9 + 7;

int n, m, a[N], kol[N], sum = 0;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cur = 0;
    cin >> n >> m;
    multiset<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(0);
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        s.erase(s.find(kol[x]));
        kol[x]++;
        s.insert(kol[x]);
        if (*s.begin() - cur > 0)
            cur++, cout << 1;
        else
            cout << 0;
    }
    //cout << cur;
    return 0;
}