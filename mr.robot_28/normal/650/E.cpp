#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
const int N = 5e5 + 100;
int n;
vector <pair <int, int> > edges[N];
int dsu[N];
int pred(int a)
{
    if(dsu[a] == a)
    {
        return a;
    }
    return dsu[a] = pred(dsu[a]);
}
void unite(int x, int y)
{
    x = pred(x);
    y = pred(y);
    if(x == y)
    {
        return;
    }
    dsu[x] = y;
    if(sz(edges[x]) > sz(edges[y]))
    {
        swap(edges[x], edges[y]);
    }
    while(sz(edges[x]) > 0)
    {
        edges[y].push_back(edges[x].back());
        edges[x].pop_back();
    }
}
pair <int, int> mass1[N], mass2[N];
bool rv1[N];
bool used[N];
vector <pair <int, int> > g[N];
void dfs(int v, int p = -1)
{
    for(auto to : g[v])
    {
        if(to.X == p)
        {
            continue;
        }
        dfs(to.X, v);
        if(!rv1[to.Y])
        {
            unite(to.X, v);
            continue;
        }
        pair <int, int> e = edges[to.X].back();
        while(used[e.Y])
        {
            edges[to.X].pop_back();
            e = edges[to.X].back();
        }
        used[e.Y] = 1;
        cout << v + 1 << " " << to.X + 1 << " " << mass2[e.Y].X + 1 << " " << mass2[e.Y].Y + 1 << "\n";
        edges[to.X].pop_back();
        unite(to.X, e.X);
    }
}
signed main()
{
//    ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    //cout.tie(0);
    int n;
    cin >> n;
    fill(used, used + n, 0);
    fill(rv1, rv1 + n, 0);
    vector <pair <pair <int, int>, int> > vec;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin>> a >> b;
        a--;
        b--;
        if(a > b)
        {
            swap(a, b);
        }
        mass1[i] = {a, b};
        g[a].push_back({b, i});
        g[b].push_back({a, i});
        vec.push_back({{a, b}, i});
    }
    int ns = 0;
    for(int i = 0; i < n- 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a > b)
        {
            swap(a, b);
        }
        vec.push_back({{a, b}, ~i});
        mass2[i] = {a, b};
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < sz(vec); i++)
    {
        if(i != sz(vec) - 1 && vec[i + 1].X == vec[i].X)
        {
            i++;
            continue;
        }
        if(vec[i].Y >= 0){
            ns++;
            rv1[vec[i].Y] = 1;
        }
        else
        {
            int ind = ~vec[i].Y;
            edges[mass2[ind].X].push_back({mass2[ind].Y, ind});
            edges[mass2[ind].Y].push_back({mass2[ind].X, ind});
        }
    }
    for(int i = 0; i < n; i++)
    {
        dsu[i]= i;
    }
    cout << ns << "\n";
    dfs(0);
    return 0;
}