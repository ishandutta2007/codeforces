#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;

signed main()
{
   // ifstream cin("rt.txt.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector <int> x(n);
        vector <pair <int, int> > f;
        for(int i = 0; i < n; i++)
        {
            cin >> x[i];
            f.push_back({x[i], i});
        }
        sort(f.begin(), f.end());
        vector <char> type(n);
        for(int i = 0; i < n; i++)
        {
            cin >> type[i];
        }
        vector <int> ans(n, -1);
        stack <pair <int, int> > q1, q2;
        for(int j = n - 1; j >= 0; j--)
        {
            int i = f[j].Y;
            if(x[i] % 2 == 0)
            {
                if(type[i] == 'R')
                {
                    if(sz(q1) == 0)
                    {
                        q1.push({m * 2 - x[i], i});
                    }
                    else
                    {
                        int t = q1.top().Y;
                        int v = q1.top().X;
                        q1.pop();
                        ans[t] = ans[i] = (v - x[i]) / 2;
                    }
                }
                else
                {
                    q1.push({x[i], i});
                }
            }
            else
            {
                if(type[i] == 'R')
                {
                    if(sz(q2) == 0)
                    {
                        q2.push({m * 2 - x[i], i});
                    }
                    else
                    {
                        int t = q2.top().Y;
                        int v = q2.top().X;
                        q2.pop();
                        ans[t] = ans[i] = (v - x[i]) / 2;
                    }
                }
                else
                {
                    q2.push({x[i], i});
                }
            }
        }
        while(sz(q1) > 1)
        {
            int v1 = q1.top().Y;
            int x1 = q1.top().X;
            q1.pop();
            int v2 = q1.top().Y;
            int x2 = q1.top().X;
            q1.pop();
            ans[v1] = ans[v2] = (x2 - x1) / 2 + x1;
        }
        while(sz(q2) > 1)
        {
            int v1 = q2.top().Y;
            int x1 = q2.top().X;
            q2.pop();
            int v2 = q2.top().Y;
            int x2 = q2.top().X;
            q2.pop();
            ans[v1] = ans[v2] = (x2 - x1) / 2 + x1;
        }
        for(int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}