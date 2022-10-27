#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <int> tree;
vector <int> upd;
void push(int v, int l, int r)
{
    if(l == r)
    {
        return;
    }
    upd[v * 2] += upd[v];
    upd[v * 2 + 1] += upd[v];
    tree[v * 2] += upd[v];
    tree[v * 2 + 1] += upd[v];
    upd[v] = 0;
}
void update(int v, int l, int r, int al, int ar, int a)
{
    if(l >= al && r <= ar)
    {
        tree[v] += a;
        upd[v] += a;
    }
    else if(l <= ar && r >= al)
    {
        push(v, l, r);
        update(v * 2, l, (r + l) / 2 , al, ar, a);
        update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, a);
        tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
    }
}
int ans(int v, int l, int r, int al, int ar)
{
    push(v, l, r);
    if(l >= al && r <= ar)
    {
        return tree[v];
    }
    else if(l <= ar && r >= al)
    {
        return max(ans(v * 2, l, (r + l) / 2, al, ar), ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
    }
    else
    {
        return -1e16;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, p;
    cin >> n >> m >> p;
    vector <pair <int, int> > a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    vector <pair <int, int> > b(m);
    vector <int> y;
    for(int i = 0; i < m; i++)
    {
        cin >> b[i].first >> b[i].second;
        y.push_back(b[i].first);
    }
    sort(y.begin(), y.end());
    int sz = unique(y.begin(), y.end()) - y.begin();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector <pair <pair <int, int>, int> > monster(p);
    for(int i = 0; i < p; i++)
    {
        cin >> monster[i].first.first >> monster[i].first.second >> monster[i].second;
    }
    sort(monster.begin(), monster.end());
    int j = 0;
    tree.resize(4 * sz, 0);
    upd.resize(4 * sz);
    for(int i = 0; i < m; i++)
    {
        if(i != 0 && b[i].first == b[i - 1].first)
        {
            continue;
        }
        int ind = lower_bound(y.begin(), y.begin() + sz, b[i].first) - y.begin();
        update(1, 0, sz - 1, ind, ind, -b[i].second);
    }
    int sum = -1e15;
    for(int i = 0; i < n; i++)
    {
        while(j < p && monster[j].first.first < a[i].first)
        {
            int ind = upper_bound(y.begin(), y.begin() + sz, monster[j].first.second) - y.begin();
            if(ind < sz)
            {
                update(1, 0, sz - 1, ind, sz - 1, monster[j].second);
            }
            j++;
        }
        sum = max(sum, ans(1, 0, sz - 1, 0, sz - 1) - a[i].second);
    }
    cout << sum;
    return 0;
}