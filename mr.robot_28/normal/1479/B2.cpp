#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int tree[4 * N];
int upd[4 * N];
void push(int v)
{
    tree[v * 2] += upd[v];
    tree[v * 2 + 1] += upd[v];
    upd[v * 2] += upd[v];
    upd[v * 2 + 1] += upd[v];
    upd[v] = 0;
}
void update(int v, int l, int r, int al, int ar, int val)
{
    if(l >= al && r <= ar)
    {
        tree[v] += val;
        upd[v] += val;
    }
    else if(l <= ar && r >= al)
    {
        push(v);
        update(v * 2, l, (r + l) / 2, al, ar, val);
        update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
    }
}
int ans1(int v, int l, int r, int al, int ar)
{
    if(al > ar)
    {
        return 1e9;
    }
    if(l >= al && r <= ar)
    {
        return tree[v];
    }
    else if(l <= ar && r >= al)
    {
        push(v);
        return min(ans1(v * 2, l, (r + l) / 2, al, ar), ans1(v * 2 + 1, (r + l) / 2+ 1, r, al, ar));
    }
    return 1e9;
}
void update1(int v, int l, int r, int ind, int val)
{
    if(l == r)
    {
        tree[v] = val;
        return;
    }
    push(v);
    if(ind <= (r + l) / 2)
    {
        update1(v * 2, l, (r + l) / 2, ind, val);
    }
    else
    {
        update1(v * 2 + 1, (r + l) / 2 + 1, r, ind, val);
    }
    tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
   // cout << "A " << tree[v * 2] << " " << tree[v * 2 + 1] << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    fill(tree, tree + 4 * N, 1e9);
    fill(upd, upd + 4 * N, 0);
    int pr;
    cin >> pr;
    pr--;
    update1(1, 0, n, n, 1);
   // cout << tree[1] << "\n";
    for(int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        a--;
        int t = min(ans1(1, 0, n, 0, a - 1), ans1(1, 0, n, a + 1, n)) + 1;
      //  cout << t << " ";
        t = min(t, ans1(1, 0,  n, a, a));
        if(a != pr)
        {
            update(1, 0, n, 0, n, 1);
        }
        update1(1, 0, n, pr, t);
        pr = a;
    }
    cout << tree[1];
    return 0;
}