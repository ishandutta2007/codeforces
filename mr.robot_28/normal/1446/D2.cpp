#include<bits/stdc++.h>

using namespace std;
vector <int> upd;
vector <int> treemin, treemax;
void add(int v, int x)
{
    treemin[v] += x;
    treemax[v] += x;
    upd[v] += x;
}
void push(int v)
{
    add(v * 2, upd[v]);
    add(v * 2 + 1, upd[v]);
    upd[v] = 0;
}
void re_calc(int v)
{
    treemin[v] = min(treemin[v * 2], treemin[v * 2 + 1]);
    treemax[v] = max(treemax[v * 2], treemax[v * 2 + 1]);
}

void update(int v, int l, int r, int al, int ar, int x)
{
    if(l >= al && r <= ar)
    {
        add(v, x);
    }
    else if(l <= ar && r >= al)
    {
        push(v);
        update(v * 2, l, (r + l)/ 2, al, ar, x);
        update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, x);
        re_calc(v);
    }
}
int ans1(int v, int l, int r, int al, int ar)
{
    if(l >= al && r <= ar)
    {
        return treemax[v];
    }
    if(l <= ar && r >= al)
    {
        push(v);
        return max(ans1(v * 2, l, (r + l) / 2 , al, ar), ans1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
    }
    return -1e9;
}
int go_to_l(int v, int l, int r, int x)
{
    if(l == r)
    {
        return l;
    }
    push(v);
    if(x >= treemin[v * 2]  && x <= treemax[v * 2])
    {
        return go_to_l(v * 2, l, (r + l)/ 2 , x);
    }
    return go_to_l(v * 2 + 1, (r + l) / 2 + 1, r, x);
}
int go_to_r(int v, int l, int r, int x)
{
    if(l == r)
    {
        return l;
    }
    push(v);
    if(x >= treemin[v * 2 + 1] && x <= treemax[v * 2 + 1])
    {
        return go_to_r(v * 2 + 1, (r + l) / 2 + 1, r, x);
    }
    return go_to_r(v * 2, l, (r + l) / 2, x);
}
signed main(){
//	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
//	cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> a(n);
    treemin.resize(4 * n + 4, 0);
    treemax.resize(4 * n + 4, 0);
    upd.resize(4 * n + 4, 0);
    vector <vector <int> > index(n + 1);
    int maxcnt = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        index[a[i]].push_back(i + 1);
        maxcnt = max(maxcnt, (int)index[a[i]].size());
    }
    int cnt = 0;
    int ind;
    for(int i = 1; i <= n; i++)
    {
        if(index[i].size() == maxcnt)
        {
            ind = i;
            cnt++;
        }
    }
    if(cnt >= 2)
    {
        cout << n;
        return 0;
    }
    for(int i = 0; i < index[ind].size(); i++)
    {
        update(1, 0, n, index[ind][i], n, 1);
    }
    int ans = 0;
    for(int c = 0; c < n; c++)
    {
        if(c == ind)
        {
            continue;
        }
        for(int i = 0; i < index[c].size(); i++)
        {
            update(1, 0, n, index[c][i], n, -1);
        }
        int pred = n;
        for(int i = index[c].size() - 1; i >= 0; i--)
        {
            int t1 = ans1(1, 0, n, index[c][i], index[c][i]);
            int t2 = ans1(1, 0, n, 0, index[c][i]);
            t2 = min(t2, pred);
   //         cout << t1 << " " << t2 << " " << index[c][i] << "\n";
            if(t2 >= t1)
            {
                for(int j= t2; j >= t1; j--)
                {
                    int L = go_to_l(1, 0, n, j);
                    int R = go_to_r(1, 0, n, j);
                    ans = max(ans, R - L);
                }
                pred = t1 - 1;
            }
        }
        for(int i = 0; i < index[c].size(); i++)
        {
            update(1, 0, n, index[c][i], n, 1);
        }
    }
    cout << ans << "\n";
	return 0;
}