#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 4e5+5;
bool used[N];
int n, a[N], t[4*N], p[4*N], b[N];
vector<int> g[N], vec, pos[N];
void build(int v, int vl, int vr)
{
    p[v] = 1;
    if (vl == vr)
    {
        t[v] = a[vl];
        return;
    }
    int vm = (vl+vr)/2;
    build(2*v, vl, vm);
    build(2*v+1, vm+1, vr);
    t[v] = t[2*v] + t[2*v+1];
    return;
}

int get(int v, int vl, int vr, int l, int r)
{
    //cout << vl << ' ' << vr << ' '<< l << ' '<< r<<endl;
    if (l > r)
        return 0;
    if (vl == l && vr == r)
        return t[v];
    int vm = (vl+vr)/2;
    if (p[v] == -1)
    {
        p[2*v] *= -1;
        p[2*v+1] *= -1;
        p[v] = 1;
        t[2*v] = vm-vl+1 - t[2*v];
        t[2*v+1] = vr - vm - t[2*v+1];
    }
    //cout << vl << ' ' << vr << endl;
    return get(2*v, vl, vm, l, min(r, vm)) + get(2*v+1, vm+1, vr, max(l, vm+1), r);
}

void update(int v, int vl, int vr, int l, int r)
{
    if (l > r)
        return;
    if (vl == l && vr == r)
    {
        p[v] = -1*p[v];
        t[v] = vr-vl+1-t[v];
        return;
    }
    int vm = (vl+vr)/2;
    if (p[v] == -1)
    {
        p[2*v] *= -1;
        p[2*v+1] *= -1;
        p[v] = 1;
        t[2*v] = vm-vl+1 - t[2*v];
        t[2*v+1] = vr - vm - t[2*v+1];
    }
    update(2*v, vl, vm, l, min(r, vm));
    update(2*v+1, vm+1, vr, max(vm+1, l), r);
    t[v] = t[2*v] + t[2*v + 1];
    return;
}

void dfs(int v)
{
    used[v] = true;
    vec.pb(v);
    for (int i = 0; i < g[v].size(); i++)
        if (!used[g[v][i]])
            dfs(g[v][i]);
    vec.pb(v);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        g[x].pb(i+2);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 0; i < vec.size(); i++)
        a[i+1] =  b[vec[i]];
    for (int i = 0; i < vec.size(); i++)
        pos[vec[i]].pb(i+1);
    int q;
    build(1, 1, 2*n);
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        string s;
        cin >> s;
        int v;
        cin >> v;
        if (s == "pow")
        {
            update(1, 1, 2*n, pos[v][0], pos[v][1]);
        }else
         {
             //cout << pos[v].size() << endl;
            int q = get(1, 1, 2*n, pos[v][0], pos[v][1])/2;
            cout << q << endl;
         }
    }
    return 0;
}