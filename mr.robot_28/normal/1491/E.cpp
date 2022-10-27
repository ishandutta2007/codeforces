#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define sz(a) (int)a.size()
#define X first
#define Y second
const int N = 2e5 + 100;
int p[N];
set <pair <int, int> > s;
vector <int> g[N], g1[N];
int F[40];
int _sz[N];
int n;
int tin[N], tout[N];
int timer = 0;
void dfs1(int v, int p = -1)
{
    tin[v] = timer++;
    for(auto to : g[v])
    {
        if(to != p)
        {
            dfs1(to, v);
        }
    }
    tout[v] = timer++;
}
bool pred(int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}
void dfs(int v, int p = -1)
{
    _sz[v] = 1;
    tin[v] = timer++;
    for(auto to : g1[v])
    {
        if(to == p)
        {
            continue;
        }
        dfs(to, v);
        _sz[v] += _sz[to];
    }
    tout[v] = timer++;
}
bool used[N];
bool go_to(vector <int> vec, int it)
{
    if(vec.size() <= 2)
    {
        return 1;
    }
    it = 39;
    while(F[it] > (int)vec.size())
    {
        it--;
    }
    if(F[it] != (int)vec.size())
    {
        return 0;
    }
    for(auto v : vec)
    {
        used[v] = 1;
    }
    vector <pair <int, int> > mass;
    for(auto v : vec)
    {
        for(auto to : g[v])
        {
            if(used[to])
            {
                mass.push_back({v, to});
            }
        }
    }
    for(auto p : mass)
    {
        g1[p.X].push_back(p.Y);
    }
    dfs(vec[0]);
    vector <int> mass1_1, mass1_2;
    vector <int> mass2_1, mass2_2;
    vector <int> mass3_1, mass3_2;
    int i1 = -1, i2 = -1, i3 = -1;
    for(auto v : vec)
    {
        if(_sz[v] == F[it - 1])
        {
            i1 = v;
        }
        if(_sz[v] == F[it - 2])
        {
            if(i2 == -1)
            {
                i2 = v;
            }
            else{
                i3 = v;
            }
        }
    }
    for(auto v : vec)
    {
        if(i1 != -1)
        {
            if(pred(i1, v))
            {
                mass1_1.push_back(v);
            }
            else
            {
                mass1_2.push_back(v);
            }
        }
        if(i2 != -1)
        {
            if(pred(i2, v))
            {
                mass2_1.push_back(v);
            }
            else
            {
                mass2_2.push_back(v);
            }
        }
        if(i3 != -1)
        {
            if(pred(i3, v))
            {
                mass3_1.push_back(v);
            }
            else
            {
                mass3_2.push_back(v);
            }
        }
    }
    for(auto v : vec)
    {
        g1[v].clear();
        used[v] = 0;
    }
    if(i1 != -1 && go_to(mass1_1, it) && go_to(mass1_2, it))
    {
        return 1;
    }
    if(i1 == -1 && i2 != -1 && go_to(mass2_1, it) && go_to(mass2_2, it))
    {
        return 1;
    }
    return 0;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    F[0] = 0;
    F[1] = F[2] = 1;
    for(int i = 3; i < 40; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }
    int it = 0;
    while(F[it] < n)
    {
        it++;
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
    dfs1(0);
    vector <int> vec;
    for(int i = 0; i < n; i++)
    {
        vec.push_back(i);
    }
    if(go_to(vec, 39))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}