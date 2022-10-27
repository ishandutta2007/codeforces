#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int mod = 998244353;
const int N = 5e5 + 100;
const int T = 20;
int pref[N];
vector <int> g[N];
int h[N];
int up[T][N];
int tin[N];
int tout[N];
int dsu[N], rang[N], value[N];
int timer = 0;
void dfs(int v)
{
    tin[v] = timer++;
    for(auto to : g[v])
    {
        h[to] = h[v] + 1;
        up[0][to] = v;
        dfs(to);
    }
    tout[v] = timer - 1;
  //  cout << v << " " << tin[v] << " " << tout[v] << "\n";
}
bool pred(int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}
int lca(int a, int b)
{
    if(pred(a, b))
    {
        return a;
    }
    for(int j = T - 1; j >= 0; j--)
    {
        if(!pred(up[j][a], b))
        {
            a = up[j][a];
        }
    }
    return up[0][a];
}
int pred(int a)
{
    if(a == dsu[a])
    {
        return a;
    }
    return dsu[a] = pred(dsu[a]);
}
int Left[N], Right[N];
void unite(int a, int b, int val)
{
    a = pred(a);
    b = pred(b);
    if(rang[a] > rang[b])
    {
        swap(a, b);
    }
    dsu[a] = b;
    rang[b] += rang[a];
    value[b] = val;
    Left[b] = min(Left[b], Left[a]);
    Right[b] = max(Right[a], Right[b]);
}
ll ans[N];
void dfs1(int v)
{
    for(auto to : g[v])
    {
        ans[to] += ans[v];
        dfs1(to);
    }
}
signed main() {
  //  ios_base::sync_with_stdio(0);
 //   cin.tie(0);
   // cout.tie(0);
    int n;
    cin >> n;
    int st1;
    for(int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        p--;
        if(p == -1){
            st1 = i;
        }
        else
        {
            g[p].push_back(i);
        }
        dsu[i] = i;
        rang[i] = 1;
        value[i] = i;
     //   cout << p << " " << i << "\n";
    }
    up[0][st1] = st1;
    dfs(st1);
    
    for(int i = 0; i < n; i++)
    {
    //    cout << i << " " << tin[i] << " " << tout[i] << "\n";
    }
    for(int i = 1; i < T; i++)
    {
        for(int j = 0; j < n; j++)
        {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
    vector <pair <int, int> > vec;
    for(int i = 0; i < n; i++)
    {
        vec.push_back({h[i], i});
    }
    vector <int> cnt(n);
    sort(vec.begin(), vec.end());
    for(int i = 0; i < n; i++)
    {
        vector <pair <int, int> > vertex;
        int j = i;
        while(j + 1 < n && vec[j + 1].X == vec[i].X)
        {
            vertex.push_back({tin[vec[j].Y], vec[j].Y});
            j++;
        }
       // cout << h[vec[j].Y] << "\n";
        vertex.push_back({tin[vec[j].Y], vec[j].Y});
        int j1 = j;
        sort(vertex.begin(), vertex.end());
        vector <pair <pair <int, int>, int> > lcas;
        for(j = 0; j < sz(vertex); j++)
        {
       //     cout << vertex[j].Y << " ";
            pref[j] = 0;
            Left[vertex[j].Y] = Right[vertex[j].Y] = j;
        }
     //   cout << "\n";
        for(j = 0; j < sz(vertex) - 1; j++)
        {
            int v_lca = lca(vertex[j].Y, vertex[j + 1].Y);
            lcas.push_back({{-h[v_lca], v_lca}, j});
        }
        sort(lcas.begin(), lcas.end());
        for(j = 0; j< sz(lcas); j++)
        {
            int v_lca = lcas[j].X.Y;
            int pr = lcas[j].Y;
   //         cout << vertex[pr].Y << " " << vertex[pr + 1].Y << "\n";
            int v1 = pred(vertex[pr].Y);
            int v2 = pred(vertex[pr + 1].Y);
            int t1 = rang[v1];
            int t2 = rang[v2];
            int l1 = Left[v1];
            int r1 = Right[v1];
            int l2 = Left[v2];
            int r2 = Right[v2];
            v1 = value[v1];
            v2 = value[v2];
     //       cout << l1 << " " << r1 << " " << l2 << " " <<r2 << " " << t1 << " " << t2 << " " << v_lca << "\n";
            pref[l1] -= t1 * (h[v_lca] + 1);
            pref[r1 + 1] += t1 * (h[v_lca] + 1);
            pref[l2] -= t2 * (h[v_lca] + 1);
            pref[r2 + 1] += t2 * (h[v_lca] + 1);
            pref[min(l1, l2)] += (t1 + t2) * (h[v_lca] + 1);
            pref[max(r1, r2) + 1] -= (t1 + t2) * (h[v_lca] + 1);
 //           cout << v1 << " " << v2 << " " << t1 << " " << t2 << "\n";
            unite(vertex[pr].Y, vertex[pr + 1].Y, v_lca);
        }
        int f = 0;
        for(j = 0; j < sz(vertex); j++)
        {
            f += pref[j];
            ans[vertex[j].Y] = f;
        }
        i = j1;
    }
    dfs1(st1);
    for(int i = 0; i < n; i++)
    {
        ans[i] += 1LL * (h[i]) * (h[i] + 1) / 2;
        cout << ans[i] << " ";
    }
    return 0;
}