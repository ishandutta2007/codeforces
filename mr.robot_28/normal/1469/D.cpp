#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n == 3)
        {
            cout << 2 << "\n";
            cout << 3 << " " << 2 << "\n";
            cout << 3 << " " << 2 << "\n";
            continue;
        }
        int n1 = n;
        vector <bool> used(n + 1);
        vector <int> mass;
        while(n1 > 2)
        {
            used[n1] = 1;
            mass.push_back(n1);
            int r1 = sqrt(n1);
            if(r1 * r1 < n1)
            {
                r1++;
            }
            n1 = r1;
        }
        if(n1 == 2)
        {
            mass.push_back(2);
        }
        used[2] = 1;
        vector <pair <int, int> > ans;
        for(int i = 2; i <= n; i++)
        {
            if(!used[i])
            {
                ans.push_back({i, n});
            }
        }
        int u = n;
        for(int i = 1; i < mass.size(); i++)
        {
            ans.push_back({n, mass[i]});
            ans.push_back({n, mass[i]});
            n = mass[i];
        }
        cout << ans.size() << "\n";
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    }
    return 0;
}