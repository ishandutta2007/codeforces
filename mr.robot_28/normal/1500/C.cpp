#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n][m], b[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> b[i][j];
        }
    }
    int max_up[n][m], max_up1[n][m];
    vector <int> ans;
    queue <vector <int> > q;
    for(int j = 0; j < m; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(i == 0 || b[i - 1][j] > b[i][j])
            {
                max_up[i][j] = 1;
            }
            else
            {
                max_up[i][j] = max_up[i - 1][j] + 1;
            }
            if(i == 0 || b[i - 1][j] != b[i][j])
            {
                max_up1[i][j] = 1;
            }
            else
            {
                max_up1[i][j] = max_up1[i - 1][j] + 1;
            }
        }
        if(sz(q) == 0 && max_up[n - 1][j] == n && max_up1[n - 1][j] != n)
        {
            q.push({j, 0, n - 1});
        }
    }
    vector <bitset <2000> > can(4e3), must(4e3);
    map <pair <int, int>, int> iter;
    int it = -1;
    while(sz(q) != 0)
    {
        vector <pair <int, int> > otr;
        int ind = q.front()[0];
        ans.push_back(q.front()[0]);
        while(sz(q) != 0)
        {
            int l = q.front()[1];
            int r = q.front()[2];
            q.pop();
            for(int i = l; i <= r; i++)
            {
                int j = i;
                while(j + 1 <= r && b[i][ind] == b[j + 1][ind])
                {
                    j++;
                }
                otr.push_back({i, j});
                if(!iter.count({i, j}))
                {
                    iter[{i, j}] = ++it;
                    for(int t = 0; t< m; t++)
                    {
                        can[it][t] = 1;
                        must[it][t] = 0;
                        if(max_up[j][t] < (j - i + 1))
                        {
                            can[it][t] = 0;
                        }
                        if(max_up1[j][t] < (j - i + 1) && max_up[j][t] >= j - i + 1)
                        {
                            must[it][t] = 1;
                        }
                    }
                }
                i = j;
            }
        }
            bitset <2000> can1, must1;
            for(int j = 0; j < m; j++)
            {
                can1[j] = 1;
                must1[j] = 0;
            }
            for(auto p : otr)
            {
                int ind1 = iter[p];
                can1 &= can[ind1];
                must1 |= must[ind1];
            }
            can1 &= must1;
            for(int j = 0; j < m; j++)
            {
                if(can1[j])
                {
                    for(auto p : otr)
                    {
                        q.push({j, p.X, p.Y});
                    }
                    break;
                }
            }
    }
    vector <int> pos;
    vector <int> pos1(n);
    for(int i = 0; i < n; i++)
    {
        pos.push_back(i);
    }
    reverse(ans.begin(), ans.end());
    for(auto ind : ans)
    {
        vector <pair <int, int> > mass;
        for(int j = 0; j < n; j++)
        {
            mass.push_back({a[pos[j]][ind], j});
        }
        sort(mass.begin(), mass.end());
        for(int j = 0; j < n; j++)
        {
            pos1[j] = pos[mass[j].Y];
        }
        for(int j = 0; j < n; j++)
        {
            pos[j] = pos1[j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[pos[i]][j] != b[i][j])
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << sz(ans) << "\n";
    for(auto v : ans)
    {
        cout << v + 1 << " ";
    }
    return 0;
}