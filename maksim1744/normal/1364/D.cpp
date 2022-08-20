/* Manish Pant - insider_pants */

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define endl "\n"
#define pb push_back
typedef long long ll;
typedef long double ldob;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N = 2e5 + 5;
vector<int> vis(N, 0);
set<int> one, two;
vector<int> colour(N, -1);
vector<int> parent(N, -1);
vector<int> in(N);
vector<int> level(N);
vector<vector<int>> v(N);
int n, m, k;

void dfs(int a, int par, int turn)
{    
    if(turn == 0)
        one.insert(a);
    else
        two.insert(a);

    colour[a] = turn;
    vis[a] = 1;

    for(int i: v[a])
    {
        if(i == par)
            continue;
        if(vis[i] == 1)
        {
            if(colour[i] == colour[a])
            {
                if(colour[a] == 0)
                {
                    if(one.count(a) && one.count(i))
                        one.erase(i);
                }
                else
                {
                    if(two.count(a) && two.count(i))
                        two.erase(i);
                }
            }
        }
        else
            dfs(i, a, turn ^ 1);
    }
}

void dfs2(int a, int par, int cur_level)
{
    if(vis[a] == 2)
        return;
    if(vis[a] == 1)
    {
        int length = level[par] - level[a] + 1;
        if (length > k)
            return;
        vector<int> cycle;
        cycle.pb(a);
        int t = par;
        while(t != a)
        {
            cycle.pb(t);
            t = parent[t];
        }
        if(cycle.size() > k)
            return;

        reverse(cycle.begin(), cycle.end());
        cout << 2 << endl;
        cout << cycle.size() << endl;
        for(int i: cycle)
            cout << i << ' ';
        cout << endl;
        exit(0);
    }
    level[a] = cur_level;
    vis[a] = 1;
    parent[a] = par;
    for(int i: v[a])    
    {
        if(i == par)
            continue;
        dfs2(i, a, cur_level + 1);
    }
    vis[a] = 2;
}

void solve()
{
    vector<int> temp;
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] != 0)
            continue;
        dfs(i, 0, 0);


        if(one.size() > two.size())
            for(int j: one)
                temp.pb(j);
        else
            for(int j: two)
                temp.pb(j);

        one.clear();
        two.clear();
    }


    int mid = (k + 1) >> 1;
    if(temp.size() >= mid)
    {
        cout << 1 << endl;
        for(int i = 0; i < mid; i++)
            cout << temp[i] << ' ';
        cout << endl;
        return;
    }


    vis.clear();
    vis.resize(N, 0);
    // cycle
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] != 0)
            continue;
        dfs2(i, 0, 0);
    }
    assert(false);
}

int main()
{
    fast();
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    solve();
}