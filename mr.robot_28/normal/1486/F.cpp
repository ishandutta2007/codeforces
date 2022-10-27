#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ld long double
#define int long long
#define sz(s) (int)s.size()
const int N = 3e5;
const int T = 20;
int n, m;
vector <int> g[N];
int pref[N];
int h[N];
int tin[N], tout[N];
int pred[N][T];
bool pr(int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}
int lca(int a, int b)
{
    int v = a;
    for(int j = T- 1; j >= 0; j--)
    {
        if(!pr(pred[v][j], b))
        {
            v = pred[v][j];
        }
    }
    if(pr(v, b))
    {
        return v;
    }
    return pred[v][0];
}
int timer = 0;
void dfs(int v, int p = -1)
{
    tin[v] = timer++;
    for(auto to : g[v])
    {
        if(to == p)
        {
            continue;
        }
        h[to] = h[v] + 1;
        pred[to][0] = v;
        dfs(to, v);
    }
    tout[v] = timer++;
}
int go_up(int v, int dh)
{
    for(int j = T - 1; j >= 0; j--)
    {
        if((1 << j) <= dh)
        {
            dh -= (1 << j);
            v = pred[v][j];
        }
    }
    return v;
}
void update(int v, int dh)
{
    if(dh < 0)
    {
        return;
    }
    pref[v]++;
    for(int j = T - 1; j >= 0; j--)
    {
        if((1 << j) <= dh)
        {
            dh -= (1 << j);
            v = pred[v][j];
        }
    }
    pref[v]--;
}
vector <vector <int> > adds[N];
int adds1[N];
int adds2[N];
int adds3[N];
int pref1[N];
int ans = 0;
int cnt1[N];
void go_to(int v, int p = -1)
{
    pref1[0] = 0;
    sort(g[v].begin(), g[v].end());
    for(int i = 0; i < sz(g[v]); i++)
    {
        if(g[v][i] != p)
        {
            go_to(g[v][i], v);
        }
    }
    int s1 = 0;
    for(int i = 0; i < sz(g[v]); i++)
    {
        pref1[i + 1] = pref1[i];
        if(g[v][i] == p)
        {
            continue;
        }
        ans += 1LL * cnt1[g[v][i]] * pref1[i];
        ans += 1LL * pref[g[v][i]] * s1;
        s1 += cnt1[g[v][i]];
        pref1[i + 1] += pref[g[v][i]] + cnt1[g[v][i]];
        pref[v] += pref[g[v][i]];
    }
    ans += 1LL * (adds1[v]) * (adds2[v] + adds3[v]);
    ans += 1LL * adds2[v] * (pref1[sz(g[v])]);
    ans += 1LL * (adds2[v] - 1) * adds2[v] / 2;
  //  cout << adds1[v] << " " << adds2[v] << " " << adds3[v] << " ";
    //cout << v << " " << pref1[sz(g[v])] << "\n";
    map <pair <int, int>, int> mp1;
    map <int,int> mp;
  //  cout << pref1[sz(g[v])] << " ";
    //cout << v << " " << ans << "\n";
    for(auto p : adds[v])
    {
        ans += adds2[v] + adds1[v];
        int l1 = lower_bound(g[v].begin(), g[v].end(), p[2]) - g[v].begin();
        int l2 = lower_bound(g[v].begin(), g[v].end(), p[3]) - g[v].begin();
        if(l1 > l2)
        {
            swap(l1, l2);
        }
            ans -= mp[l1];
            ans -= mp[l2];
            ans += mp1[{l1, l2}];
        mp[l1]++;
        mp[l2]++;
        mp1[{l1, l2}]++;
        ans += pref1[l1] + (pref1[l2] - pref1[l1 + 1]) + (pref1[sz(g[v])] - pref1[l2 + 1]);
    }
    ans += sz(adds[v]) * (sz(adds[v]) - 1) / 2;
   // cout << v << " " << ans << "\n";
}
void update1(int v, int dh)
{
    for(int j = T - 1; j >= 0; j--)
    {
        if((1 << j) <= dh)
        {
            dh -= (1 << j);
            v = pred[v][j];
        }
    }
    cnt1[v]++;
}
signed main()
{
//ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    //cout.tie(0);
    cin >> n ;
    fill(adds3, adds3 + N, 0);
    fill(adds1, adds1 + N, 0);
    fill(adds2, adds2 + N, 0);
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    for(int i =1 ; i < T; i++)
    {
        for(int j = 0; j < n; j++)
        {
            pred[j][i] = pred[pred[j][i - 1]][i - 1];
        }
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int v = lca(a, b);
        update(a, h[a] - h[v] -1);
        update(b, h[b] - h[v] - 1);
        if(v != a && v != b)
        {
            int a1 = go_up(a, h[a] - h[v] - 1);
            int b1 = go_up(b, h[b] - h[v] - 1);
            adds[v].push_back({a, b, a1, b1});
        }
        else if(a != b)
        {
            adds3[v]++;
        }
        if(v == a && v != b)
        {
            update1(b, h[b] - h[v] - 1);
        }
        if(v == b && v != a)
        {
            update1(a, h[a] - h[v] - 1);
        }
        if(a == b)
        {
            adds2[a]++;
        }
        else
        {
            if(v != a)
            {
                adds1[a]++;
            }
            if(v != b)
            {
                adds1[b]++;
            }
        }
    }
    go_to(0);
    cout << ans;
    return 0;
}