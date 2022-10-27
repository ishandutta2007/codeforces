#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
#define int long long

int32_t main() {
 //   ios::sync_with_stdio(0);
   // cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> p(n), c(n);
    vector <vector <pair <int, int> > > mass(m);
    vector <pair <int, int> > mass1;
    for(int i = 0; i < n; i++)
    {
        cin >> p[i] >> c[i];
        p[i]--;
        mass1.push_back({c[i], i});
        mass[p[i]].push_back({c[i], i});
    }
    sort(mass1.begin(), mass1.end());
    for(int i = 0; i < m; i++)
    {
        sort(mass[i].begin(), mass[i].end());
    }
    int ans = 1e18;
    vector <bool> used(n);
    for(int i = 1; i <= n; i++)
    {
        int cnt = mass[0].size();
        int sum = 0;
        for(int j = 1; j < m; j++)
        {
            if(mass[j].size() >= i)
            {
            for(int t = 0; t <= mass[j].size() - i; t++)
            {
                cnt++;
                sum += mass[j][t].first;
                used[mass[j][t].second] = 1;
            }
            }
        }
        for(int j = 0; j < n; j++)
        {
            if(cnt >= i || used[mass1[j].second] || p[mass1[j].second] == 0)
            {
                continue;
            }
            used[mass1[j].second] = 1;
            cnt++;
            sum += mass1[j].first;
        }
        for(int j = 0; j < n; j++)
        {
            used[j] = 0;
        }
        if(cnt >= i)
        {
            ans = min(ans, sum);
        }
    }
    cout << ans;
    return 0;
}