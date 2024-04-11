#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector <int> p(n);
        for(int i = 0; i < n; i++)
        {
            cin >> p[i];
            p[i]--;
        }
        map <int, int> mp;
        for(int i = 0; i < n; i++)
        {
            int k = i - p[i];
            if(k < 0)
            {
                k += n;
            }
            mp[k]++;
        }
        vector <bool> used(n);
        vector <int> new_a(n);
        vector <int> ans;
        for(auto pt : mp)
        {
            if(pt.Y * 3 >= n)
            {
                int cnt = 0;
                int k = pt.X;
                for(int i = 0; i < n; i++)
                {
                    used[i] = 0;
                    int i1 = (i - k + n) % n;
                    new_a[i1] = p[i];
                }
                for(int i = 0; i < n; i++)
                {
                    if(used[i])
                        continue;
                    cnt++;
                    int v = i;
                    while(!used[v])
                    {
                        used[v] = 1;
                        v = new_a[v];
                    }
                }
                if(n - cnt <= m)
                {
                    ans.push_back(k);
                }
            }
        }
        cout << sz(ans) << " ";
        for(auto pt : ans)
        {
            cout << pt << " ";
        }
        cout << "\n";
    }
    return 0;
}