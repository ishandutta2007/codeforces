#include <bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int> t[400005], pos[100005];
int n, k, q, l, r, a[100005], prevv[100005];
vector <int> mmerge(vector<int> a, vector<int> b)
{
    vector <int> c;
    c.clear();
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
        if (a[i] > b[j])
        {
            c.pb(b[j]);
            j++;
        }else
        {
            c.pb(a[i]);
            i++;
        }
    while (i < a.size())
    {
        c.pb(a[i]);
        i++;
    }
    while (j < b.size())
    {
        c.pb(b[j]);
        j++;
    }
    return c;
}

void build(int v, int vl, int vr)
{
    if (vl == vr)
    {
        t[v].pb(prevv[vl]);
        return;
    }
    int vm = (vl+vr)/ 2;
    build(2*v, vl, vm);
    build(2*v+1, vm+1, vr);
    t[v] = mmerge(t[2*v+1], t[2*v]);
    return;
}

int get(int v, int vl, int vr, int l, int r, int x)
{
    if (l > r)
        return 0;
    if (vl == l && vr == r)
    {
       return lower_bound(t[v].begin(), t[v].end(), x) - t[v].begin();
    }
    int vm = (vl+vr)/2;
    return get(2*v, vl, vm, l, min(r, vm), x) + get(2*v+1, vm+1, vr, max(vm+1, l), r, x);
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        prevv[i] = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (pos[a[i]].size() >= k)
            prevv[i] = pos[a[i]][pos[a[i]].size()-k];
        pos[a[i]].pb(i);
    }
    prevv[0] = 2000000000;
    build(1, 1, n);
    int q;
    cin >> q;
    int last = 0, x, y;
    for (int o = 0; o < q; o++)
    {
        cin >> x >> y;
        l = (x + last) % n + 1;
        r = (y + last) % n + 1;
        if (l > r)
            swap(l, r);
        last = get(1, 1, n, l, r, l);
        cout << last << endl;
    }
    return 0;
}