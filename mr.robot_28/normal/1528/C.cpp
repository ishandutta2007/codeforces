#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
const int N = 3e5 + 100;
int Tree[4 * N];
vector <int> g1[N], g2[N];
int tin[N], tout[N];
set <pair <int, int> > st;
int timer = 0;
void update(int v, int l, int r, int x, int up)
{
    Tree[v] += up;
    if(l == r)
    {
        return;
    }
    if(x <= (r + l) / 2)
    {
        update(v * 2, l, (r + l) / 2, x, up);
    }
    else
    {
        update(v * 2 + 1, (r + l) / 2 + 1, r, x, up);
    }
}
int get(int v, int l, int r, int al, int ar)
{
    if(l >= al && r <= ar)
    {
        return Tree[v];
    }
    if(l <= ar && r >= al)
    {
        return get(v * 2, l, (r + l) / 2, al, ar) + get(v * 2 + 1, (r + l )/ 2 + 1, r, al, ar);
    }
    return 0;
}
int total;
int ans;
int n;
void dfs(int v, int p = -1)
{
    int fl = 0;
    if(get(1, 0, n - 1, tin[v], tout[v]) == 0)
    {
        set <pair <int, int> > :: iterator it;
        it = st.lower_bound({tin[v], 0});
        if(sz(st) == 0 || it == st.begin())
        {
            fl = 1;
            total++;
        }
        else{
            it--;
            if(it -> second < tin[v])
            {
                fl = 1;
                total++;
            }
            else if(get(1, 0, n - 1, it -> first + 1, it -> second) != 0)
            {
                fl = 1;
                total++;
            }
        }
    }
    st.insert({tin[v], tout[v]});
    update(1, 0, n - 1, tin[v], 1);
    ans = max(ans, total);
  //  cout << "A " << v << " " << total << "\n";
    for(auto to : g1[v])
    {
        if(to == p)
        {
            continue;
        }
        dfs(to, v);
    }
    total -= fl;
    st.erase({tin[v], tout[v]});
    update(1, 0, n - 1, tin[v], -1);
}
void dfs2(int v, int p = -1)
{
    tin[v] = timer++;
    for(auto to : g2[v])
    {
        if(to == p)
        {
            continue;
        }
        dfs2(to, v);
    }
    tout[v] = timer - 1;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    fill(Tree, Tree + 4 * N, 0);
    while(t--)
    {
        timer = 0;
        cin >> n;
        total = ans = 0;
        for(int i = 0; i < n; i++)
        {
            g1[i].clear();
            g2[i].clear();
        }
        for(int i = 1; i < n; i++)
        {
            int a;
            cin >> a;
            a--;
            g1[a].push_back(i);
        }
        for(int i = 1; i < n; i++)
        {
            int a;
            cin >> a;
            a--;
            g2[a].push_back(i);
        }
        dfs2(0);
        dfs(0);
        cout << ans << "\n";
    }
    return 0;
}