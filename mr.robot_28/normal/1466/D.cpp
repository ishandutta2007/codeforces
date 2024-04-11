#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
#define int long long
int n;
const int N = 1e5;
int w[N];
vector <int> g[N];
int sum;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> w[i];
        }
        for(int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector <pair <int, int> > qw;
        for(int i= 0; i < n; i++)
        {
            sum += g[i].size() * w[i];
            if(g[i].size() != 1)
            {
            qw.push_back({w[i], g[i].size() - 1});
            }
        }
        sort(qw.begin(), qw.end());
        vector <int> ans(n - 1);
        int j = 0;
        for(int i = n - 2; i >= 0; i--)
        {
            ans[i] = sum;
            if(i != 0)
            {
                if(qw[j].second == 0)
                {
                    j++;
                }
                qw[j].second--;
                sum -= qw[j].first;
            }
        }
        for(int i = 0; i < n; i++)
        {
            g[i].clear();
        }
        for(int i = 0; i < n - 1; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}