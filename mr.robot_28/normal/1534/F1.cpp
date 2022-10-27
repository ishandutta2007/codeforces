#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 4e5;
vector <int> g[N];
int tout[N];
bool used[N];
int used1[N];
int timer = 1;
void dfs(int v)
{
  //  cout << "A " << v << "\n";
    used1[v] = 1;
    for(auto to : g[v])
    {
        if(used1[to] == 0)
        {
            dfs(to);
        }
    }
    tout[v] = timer++;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> vec[m];
    vector <vector<char> > a(n, vector <char> (m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m;j++)
        {
            if(a[i][j] == '#')
            {
                used[i * m + j] = 1;
                vec[j].push_back(i);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == '#')
            {
                if(j > 0)
                {
                    int p = lower_bound(vec[j - 1].begin(), vec[j - 1].end(), i) - vec[j - 1].begin();
                    if(p != sz(vec[j - 1]))
                    {
                        g[i * m + j].push_back(vec[j - 1][p] * m + j - 1);
                    }
                }
                if(j < m - 1)
                {
                    int p = lower_bound(vec[j + 1].begin(), vec[j + 1].end(), i) - vec[j + 1].begin();
                    if(p != sz(vec[j + 1]))
                    {
                        g[i * m + j].push_back(vec[j + 1][p] * m + j + 1);
                    }
                }
                int p = upper_bound(vec[j].begin(), vec[j].end(), i) - vec[j].begin();
                if(p != sz(vec[j]))
                {
                    g[i * m + j].push_back(vec[j][p] * m + j);
                    if(vec[j][p] == i + 1)
                    {
                        g[vec[j][p] * m + j].push_back(i * m + j);
                    }
                }
            }
        }
    }
    for(int i = 0; i < n * m; i++)
    {
        if(used[i] && !used1[i])
        {
    //        cout << "P " << i << "\n";
            dfs(i);
        }
    }
    vector <pair <int, int> > mass;
    for(int i = 0; i < n * m; i++)
    {
        if(used[i])
        {
            mass.push_back({tout[i], i});
        }
    }
    fill(used1, used1 + n * m, 0);
    sort(mass.begin(), mass.end());
    reverse(mass.begin(), mass.end());
    int ans = 0;
    for(auto v : mass)
    {
        if(!used1[v.Y])
        {
       //     cout << v.Y << "\n";
            dfs(v.Y);
            ans++;
        }
    }
    cout << ans;
    return 0;
}