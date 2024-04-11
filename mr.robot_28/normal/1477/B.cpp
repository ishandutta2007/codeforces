#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
int tree[4 * N];
int col[4 * N];
void push(int v, int cl, int l, int r)
{
    if(cl == -1)
    {
        return;
    }
    col[v * 2] = col[v * 2 + 1] = cl;
    int m = (r + l) / 2;
    tree[v * 2] = cl * (m - l + 1);
    tree[v * 2 + 1] = cl * (r - m);
}
void update(int v, int l, int r, int al, int ar, int cl)
{
    if(l >= al && r <= ar){
        col[v] = cl;
        tree[v] = (r - l + 1) * cl;
    }
    else if(l <= ar && r >= al)
    {
        push(v, col[v], l, r);
        update(v * 2, l, (r + l) / 2, al, ar, cl);
        update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, cl);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
        col[v] = -1;
    }
}
int ans(int v, int l, int r, int al, int ar)
{
    if(l >= al && r <= ar)
    {
        return tree[v];
    }
    else if(l <= ar && r >= al)
    {
        push(v, col[v], l, r);
        return ans(v * 2, l, (r + l) / 2, al, ar) + ans(v * 2 + 1, (r + l )/ 2 + 1, r, al, ar);
    }
    return 0;
}
int ans1(int v, int l, int r, int i)
{
    if(col[v] != -1)
    {
        return col[v];
    }
    if(i <= (r + l) / 2)
    {
        return ans1(v * 2, l, (r + l) / 2, i);
    }
    return ans1(v * 2 + 1, (r + l )/ 2 + 1, r, i);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, q;
        cin >> n >> q;
        string s, t;
        cin >> s >> t;
        for(int i = 0; i < n * 4; i++)
        {
            col[i] = -1;
            tree[i] =  0;
        }
        for(int i = 0; i < n; i++)
        {
            update(1, 0, n - 1, i, i, t[i] - '0');
        }
        vector <pair <int, int> > qur(q);
        for(int i = 0; i < q; i++)
        {
            cin >> qur[i].first >> qur[i].second;
            qur[i].first--;
            qur[i].second--;
        }
        bool flag = 1;
        for(int i = q - 1; i >= 0; i--)
        {
            int l = qur[i].first;
            int r = qur[i].second;
            int cnt = ans(1, 0, n - 1, l, r);
            if(cnt * 2 == (r - l + 1))
            {
                flag = 0;
                break;
            }
            if(cnt * 2 < (r - l + 1))
            {
                update(1, 0, n - 1, l, r, 0);
            }
            else
            {
                update(1, 0, n - 1, l, r, 1);
            }
        }
        for(int i = 0; i < n; i++)
        {
            int ch = ans1(1, 0, n - 1, i);
            if(ch != s[i] - '0')
            {
                flag = 0;
            }
        }

        if(flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}