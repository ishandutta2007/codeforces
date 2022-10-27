#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define sz(a) (int)a.size()
#define X first
#define Y second
const int N = 2e5 + 100;
int nxt[N];
bool used[N];
vector <vector <int> > cycles;
vector <int> cycle;
void dfs(int v)
{
    int to = nxt[v];
    cycle.push_back(v);
    used[v] = 1;
    if(!used[to])
    {
        dfs(to);
    }
}
vector <pair <int, int> > ans;
void funct(vector <pair <int, int> > vec)
{
    vector <int> ind;
    for(int i = 0; i < sz(vec); i++)
    {
        if(vec[i].Y == 0)
        {
            continue;
        }
        int j = (i + 1) % sz(vec);
        while(vec[j].Y == 0)
        {
            ans.push_back({vec[j].X, vec[i].X});
            j = (j + 1) % sz(vec);
        }
        ind.push_back(vec[i].X);
    }
    if(sz(ind) == 2)
    {
        ans.push_back({ind[0], ind[1]});
    }
    else{
        ans.push_back({ind[0], ind[1]});
        ans.push_back({ind[3], ind[0]});
        ans.push_back({ind[3], ind[2]});
    }
}
signed main()
{
    int n;
    cin >> n;
    vector <int> p(n);
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
        nxt[i] = p[i];
    }
    for(int i = 0; i < n; i++)
    {
        if(!used[i])
        {
            dfs(i);
            if(sz(cycle) != 1)
            {
                cycles.push_back(cycle);
            }
            cycle.clear();
        }
    }
    for(int i = sz(cycles) % 2; i < sz(cycles); i += 2)
    {
        int t1 = cycles[i].back();
        int t2 = cycles[i + 1].back();
        ans.push_back({t1, t2});
        vector <pair <int, int> > vec;
        for(int j = 0; j < sz(cycles[i]) - 1; j++)
        {
            vec.push_back({cycles[i][j], 0});
        }
        vec.push_back({cycles[i].back(), 1});
        for(int j = 0; j < sz(cycles[i + 1]) - 1; j++)
        {
            vec.push_back({cycles[i + 1][j], 0});
        }
        vec.push_back({cycles[i + 1].back(), 1});
        funct(vec);
    }
    if(sz(cycles) % 2 == 1)
    {
        vector <int> vec1 = cycles[0];
        if(sz(vec1) == 2)
        {
            int t;
            if(0 != vec1[0] && 0 != vec1[1])
            {
                t = 0;
            }
            else if(1 != vec1[0] && 1 != vec1[1])
            {
                t = 1;
            }
            else
            {
                t = 2;
            }
            ans.push_back({t, vec1[0]});
            ans.push_back({t, vec1[1]});
            ans.push_back({vec1[0], t});
        }
        else if(sz(vec1) == 3)
        {
            ans.push_back({vec1[0], vec1[1]});
            ans.push_back({vec1[1], vec1[2]});
            ans.push_back({vec1[0], vec1[2]});
            ans.push_back({vec1[0], vec1[1]});
        }
        else
        {
            vector <pair <int, int> > vec2;
            ans.push_back({vec1[0], vec1[2]});
            ans.push_back({vec1[1], vec1[3]});
            vec2.push_back({vec1[0], 1});
            vec2.push_back({vec1[3], 1});
            vec2.push_back({vec1[2], 1});
            vec2.push_back({vec1[1], 1});
            for(int j = 4; j < sz(vec1); j++)
            {
                vec2.push_back({vec1[j], 0});
            }
            funct(vec2);
        }
    }
    cout << sz(ans) << "\n";
    for(int i = 0; i < sz(ans); i++)
    {
        cout << ans[i].X + 1 << " " << ans[i].Y + 1 << "\n";
    }
    return 0;
}