#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int N = 4e5 + 100;
vector <vector<char>> arr;
vector <vector <int> > ind;
int nodecnt = 0;
int et = 1;
int leftmax[N];
int leftspec[N];
int am[N];
int marked[N];
vector <int> g[N], g1[N];
vector <vector <int> > comps;
vector <int> st;
int trans[N];
int up[N];
int tin[N];
int flag[N];
int in[N];
pair <int, int> dp[N];
void dfs(int v)
{
    flag[v] = 1;
    tin[v] = up[v] = et++;
    st.push_back(v);
    for(auto to : g[v])
    {
        if(!tin[to])
        {
            dfs(to);
            up[v] = min(up[v], up[to]);
        }
        else if(flag[to])
        {
            up[v] = min(up[v], tin[to]);
        }
    }
    if(tin[v] == up[v])
    {
        comps.push_back({});
        while(1)
        {
            int cur = st.back();
            st.pop_back();
            in[cur] = sz(comps) -1;
            flag[cur] = 0;
            comps.back().push_back(cur);
            if(cur == v)
            {
                break;
            }
        }
    }
}
void mark(int v)
{
    for(auto x : g1[v])
    {
        if(!marked[x])
        {
            marked[x] = 1;
            mark(x);
        }
    }
}
pair <int, int>  solve(int v)
{
    if(dp[v].X)
    {
        return dp[v];
    }
    dp[v] = {1e9, -1e9};
    for(auto x : g1[v])
    {
        if(!marked[x])
        {
            pair <int, int> te = solve(x);
            dp[v].X = min(dp[v].X, te.X);
            dp[v].Y = max(dp[v].Y, te.Y);
        }
    }
    return dp[v];
}
signed main()
{
//    ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    //cout.tie(0);
    int n, m;
    cin >> n >> m;
    arr.resize(n + 1, vector <char> (m + 1));
    ind.resize(n + 1, vector <int> (m + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> am[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j<= m; j++)
        {
            if(arr[i][j] == '#')
            {
                ind[i][j] = ++nodecnt;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(arr[i][j] == '#')
            {
                if(i - 1 >= 1 && arr[i - 1][j] == '#')
                {
                    g[ind[i][j]].push_back(ind[i - 1][j]);
                }
                for(int k = i + 1; k <= n; k++)
                {
                    if(arr[k][j] == '#')
                    {
                        g[ind[i][j]].push_back(ind[k][j]);
                        break;
                    }
                }
                bool left_done = 0, right_done = 0;
                for(int k = i; k <= n && (!left_done || !right_done) && (arr[k][j] != '#' || k == i); k++)
                {
                    if(j > 1 && !left_done && arr[k][j - 1] == '#')
                    {
                        g[ind[i][j]].push_back(ind[k][j - 1]);
                        left_done = 1;
                    }
                    if(j < m && !right_done && arr[k][j + 1] == '#')
                    {
                        g[ind[i][j]].push_back(ind[k][j + 1]);
                        right_done = 1;
                    }
                }
            }
        }
    }
    et = 1;
    comps.push_back({});
    for(int i = 1; i <= nodecnt; i++)
    {
        if(!tin[i])
        {
            dfs(i);
        }
    }
    for(int i = 1; i < sz(comps); i++)
    {
        leftspec[i] = 1e9;
        for(auto v : comps[i])
        {
            for(auto y : g[v])
            {
                if(in[y] != i)
                {
                    g1[i].push_back(in[y]);
                }
            }
        }
        sort(g1[i].begin(), g1[i].end());
        g1[i].resize(unique(g1[i].begin(), g1[i].end()) - g1[i].begin());
    }
    vector <int> spec;
    for(int i = 1; i <= m; i++)
    {
    //    cout << "A " << i << "\n";
        for(int j = n; j >= 1; j--)
        {
            if(arr[j][i] == '#')
            {
                am[i]--;
                if(am[i] == 0)
                {
                    spec.push_back(in[ind[j][i]]);
         //           cout << in[ind[i][j]] << "\n";
                    leftspec[in[ind[j][i]]] = min(leftspec[in[ind[j][i]]], i);
                }
            }
        }
    }
   // cout << "A\n";
    sort(spec.begin(), spec.end());
    spec.resize(unique(spec.begin(), spec.end()) - spec.begin());
    for(auto x : spec)
    {
        if(!marked[x])
        {
            mark(x);
        }
    }
    vector <int> compress;
    for(auto x : spec)
    {
        if(!marked[x])
        {
            compress.push_back(leftspec[x]);
        }
    }
    //cout << "A\n";
    sort(compress.begin(), compress.end());
    for(auto x : spec)
    {
        if(!marked[x])
        {
            dp[x].X = dp[x].Y = lower_bound(compress.begin(), compress.end(), leftspec[x]) - compress.begin() + 1;
        }
    }
  //  cout << "A\n";
    for(int i = 1; i < sz(comps); i++)
    {
        if(!marked[i])
        {
            pair <int, int> te = solve(i);
            if(te.X != 1e9)
            {
                trans[te.X] = max(trans[te.X], te.Y);
            }
        }
    }
   // cout << "E\n";
    for(int i = 2; i <= sz(compress); i++)
    {
        trans[i] = max(trans[i], trans[i - 1]);
    }
    int cur = 1, ans = 0;
    while(cur <= sz(compress))
    {
        ans++;
     //   cout << cur << "\n";
        cur = trans[cur] + 1;
    }
    cout << ans;
    return 0;
}