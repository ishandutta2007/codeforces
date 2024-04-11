#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
int tim[N], a[N];
int ind[N];
int ind1[N];
int treesum[N * 4];
int treecnt[N * 4];
bool cmp(int a, int b)
{
    return tim[a] < tim[b];
}
bool cmp1(int x1, int x2)
{
    return a[x1] < a[x2];
}
void update(int v, int l, int r, int ind, int val)
{
    if(l == r)
    {
        treesum[v] = val;
        treecnt[v] = 1;
        return;
    }
    if(ind <= (r + l) / 2)
    {
        update(v * 2, l, (r + l) / 2, ind ,val);
    }
    else
    {
        update(v * 2 + 1, (r + l) / 2 + 1, r, ind, val);
    }
    treesum[v] += val;
    treecnt[v]++;
}
int ans(int v, int l, int r, int val)
{
    if(l == r)
    {
        if(treesum[v] > val)
        {
            return 0;
        }
        return treecnt[v];
    }
    if(treesum[v * 2] <= val)
    {
        return treecnt[v * 2] + ans(v * 2 + 1, (r + l) / 2 + 1, r, val - treesum[v * 2]);
    }
    else
    {
        return ans(v * 2, l, (r + l) / 2, val);
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, T;
    cin >> n >> T;
    for(int i = 0; i < N * 4; i++)
    {
        treesum[i] = treecnt[i] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        ind[i] = ind1[i] = i;
        cin >> a[i] >> tim[i];
    }
    sort(ind, ind + n, cmp);
    sort(ind1, ind1 + n, cmp1);
    int index[N];
    bool used[N];
    for(int i = 0; i < n; i++)
    {
        used[i] = 0;
        index[ind[i]] = i;
    }
    int global_ans = 0;
    for(int i = n - 1; i >= 0; --i)
    {
        int j = ind1[i];
        update(1, 0, n - 1, index[j], tim[j]);
        global_ans= max(global_ans, min(ans(1, 0, n - 1, T), a[j]));
    }
    cout << global_ans << "\n";
    for(int i = 0; i < N * 4; i++)
    {
        treesum[i] = treecnt[i] = 0;
    }
    cout << global_ans << "\n";
    for(int i = n - 1; i >= 0; i--)
    {
        int j = ind1[i];
        used[j] = 1;
        update(1, 0, n - 1, index[j], tim[j]);
        if(global_ans == min(ans(1, 0, n - 1, T), a[j]))
        {
            for(int k = 0; k < n; k++)
            {
                if(global_ans == 0)
                {
                    break;
                }
                if(used[ind[k]])
                {
                    cout << ind[k] + 1 << " ";
                    global_ans--;
                }
            }
            return 0;
        }
    }
    return 0;
}