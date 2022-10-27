#include<bits/stdc++.h>
using namespace std;
vector <priority_queue <int> > treecol;
vector <int> treemin, treemax;
vector <bool> erased;
vector <bool> used;
void up(int v)
{
    int maxc = max(treemax[v * 2], treemax[v * 2 + 1]);
    while(treecol[v].size() > 0 && erased[treecol[v].top()])
    {
        treecol[v].pop();
    }
    int max1 = treecol[v].empty() ? -1 : treecol[v].top();
    if(treecol[v].size() != 0 && treecol[v].top() > maxc)
    {
        if(used[treecol[v].top()] || treecol[v].top() < min(treemin[v * 2], treemin[v * 2 + 1]))
        {
            treemax[v] = -1;
        }
        else
        {
            treemax[v] = treecol[v].top();
        }
    }
    else
    {
        treemax[v] = maxc;
    }
    treemin[v] = max(max1, min(treemin[v * 2], treemin[v * 2 + 1]));
}
void update(int v, int l, int r, int al, int ar, int ind, int type)
{
    if(l >= al && r <= ar)
    {
        if(type == -1)
        {
            treecol[v].push(ind);
        }
        up(v);
    }
    else if(l <= ar && r >= al)
    {
        update(v * 2, l, (r + l) / 2, al, ar, ind, type);
        update(v * 2 + 1, (r + l) / 2 +1, r, al, ar, ind, type);
        up(v);
    }
}
signed main()
{
 //   ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
   // cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> uniq;
    erased.resize(n);
    vector <pair <pair <int, int>, pair <int, int> > > x(n);
    vector <pair <int, pair <int, int> > > events;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i].first.first >> x[i].first.second >> x[i].second.first >> x[i].second.second;
        uniq.push_back(x[i].first.second);
        uniq.push_back(x[i].second.second);
        events.push_back({x[i].first.first, {-1, i}});
        events.push_back({x[i].second.first, {1, i}});
    }
    sort(events.begin(), events.end());
    sort(uniq.begin(), uniq.end());
    int m = unique(uniq.begin(), uniq.end()) - uniq.begin();
    treemin.resize(8 * m, 0);
    treemax.resize(8 * m, -1e9);
    treecol.resize(4 * m);
    used.resize(n);
 //   cout << "A\n";
    for(int i = 0; i < events.size(); i++)
    {
        int ind = events[i].second.second;
        int type = events[i].second.first;
        if(type == 1)
        {
            erased[ind] = 1;
        }
        int l = lower_bound(uniq.begin(), uniq.begin() + m, x[ind].first.second) - uniq.begin();
        int r = lower_bound(uniq.begin(), uniq.begin() + m, x[ind].second.second) - uniq.begin();
        update(1, 0, m - 1, l, r - 1, ind, type);
        if(i != events.size() - 1 && events[i + 1].first == events[i].first)
        {
            continue;
        }
        while(treemax[1] >= treemin[1])
        {
            int ind = treemax[1];
            used[ind] = 1;
            l = lower_bound(uniq.begin(), uniq.begin() + m, x[ind].first.second) - uniq.begin();
            r = lower_bound(uniq.begin(), uniq.begin() + m, x[ind].second.second) - uniq.begin();
            update(1, 0, m - 1, l, r - 1, ind, 0);
        }
    }
    int ans = 1;
    for(int i = 0; i < n; ++i)
    {
        if(used[i])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}