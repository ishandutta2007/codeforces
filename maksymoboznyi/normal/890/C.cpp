#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ull unsigned long long
using namespace std;
const int N = 5e5+10;

int  cur = 1, last_vis[N], n, t[N], kol[N];

signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    last_vis[1] = 1;
    kol[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (kol[t[i]] > 0)
        {
            kol[t[i]]--;
            kol[i]++;
        }else
        {
            cur++;
            kol[i]++;
        }
    }
    cout << cur;
    return 0;
}