#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

const int N = 5e5 + 1;
const long long M = 1e9 + 7;
const double eps = 1e-8;

int m, k, n, s, a[N], kol[N], kol1[N], last[N], nex[N], used[N], cur[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> k >> n >> s;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < s; i++) {
        int x;
        cin >> x;
        used[x] = 1;
        kol[x]++;
        kol1[x]++;
    }
    for (int i = 1; i < N; i++)
    {
        last[i] = -1;
        cur[i] = -1;
    }
    for (int i = m - 1; i >= 0; i--)
        nex[i] = last[a[i]], last[a[i]] = i;

    for (int i = 0; i < m; i++)
        if (used[a[i]] && kol[a[i]] == 1)
            cur[a[i]] = i, kol[a[i]]--;
        else
            kol[a[i]]--;

    int mx = 0;
    for (int i = 1; i < N; i++)
    if (used[i] && cur[i] == -1) {
        cout << "-1";
        return 0;
    }else
        mx = max(mx, cur[i]);
    for (int i = 0; i < m; i++)
    {
        if (max(mx - i + 1, k) - k + (i % k) <= m - n*k) {
            //cout << "YES\n";
            int del = max(mx - i + 1, k) - k + (i % k);
            cout << del << "\n";
            int x = i - 1;
            vector<int> ans;
            while ((x + 1)%k != 0)
                ans.pb(x), x--;
           // cout << i << ' ' << ans.size() << ' ' << mx << endl;
            for (int j = i; j <= mx; j++)
                if ((!used[a[j]] || kol1[a[j]] <= 0) && ans.size() < del)
                    ans.pb(j), kol1[a[j]]--;
                else
                    kol1[a[j]]--;
            sort(ans.begin(), ans.end());
            for  (int i = 0; i < ans.size(); i++)
                cout << ans[i]+1 << ' ';
            //cout << endl;
            return 0;
        }
        if (used[a[i]]) {
        cur[a[i]] = nex[cur[a[i]]];
        if (cur[a[i]] == -1) {
            cout << "-1";
            return 0;
        }
        mx = max(mx, cur[a[i]]);
        }
    }
    return 0;
}