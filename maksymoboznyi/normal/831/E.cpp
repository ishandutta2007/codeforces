#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool used[100005];
ll n, a[100006], t[500000];
vector<ll> pos[100006];


void build(int v, int vl, int vr)
{
    if (vl == vr)
    {

        t[v] = used[vl];
        return;
    }
    int vm = (vl+vr)/2;
    build(2*v, vl, vm);
    build(2*v+1, vm+1, vr);
    t[v] = t[2*v] + t[2*v+1];
    return;
}

void update(int v, int vl, int vr, int pos)
{
    if (vl == vr)
    {
        t[v]--;
        used[vl] = 0;
        return;
    }
    int vm = (vl+vr)/2;
    if (pos <= vm)
        update(2*v, vl, vm, pos);
    else
        update(2*v+1, vm+1, vr, pos);
    t[v] = t[2*v] + t[2*v+1];
    return;
}

ll get(int v, int vl, int vr, int l, int r)
{
    if (l > r)
        return 0;
    if (vl == l && vr == r)
        return t[v];
    int vm = (vl+vr) / 2;
    return get(2*v, vl, vm, l, min(vm, r)) + get(2*v+1, vm+1, vr, max(vm+1, l), r);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]].push_back(i);

    }
    for (int i = 1; i <= n; i++)
        used[i] = true;
    build(1, 1, n);
    int cur = 1, cpos = 1;
    ll ans = 0;
    while (cur != 100001)
    if (pos[cur].size() != 0)
    {
        if (pos[cur][0] >= cpos)
        {
            ans += get(1, 1, n, cpos, pos[cur][pos[cur].size()-1]);
            for (int i = 0; i < pos[cur].size(); i++)
                update(1, 1, n, pos[cur][i]);
            cpos = pos[cur][pos[cur].size()-1]+1;
            if (cpos == n+1)
                cpos = 1;
        }else
        {
            int i = 0;
            while (i < pos[cur].size() && pos[cur][i] < cpos)
                i++;
            i--;
            ans += get(1, 1, n, cpos, n);
            ans += get(1, 1, n, 1, pos[cur][i]);
            cpos = pos[cur][i]+1;
            for (int j = 0; j < pos[cur].size(); j++)
                update(1, 1, n, pos[cur][j]);
        }
        cur++;
    }else
        cur++;
    cout << ans << endl;
    return 0;
}