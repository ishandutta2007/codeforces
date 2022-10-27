#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5;
vector <int> vec[N + 1];
int cnt[N + 1];
int n;
void relax(int &a, int &b, int &c, int &d, int x)
{
    if(x < a)
    {
        swap(x, a);
    }
    if(x < b)
    {
        swap(x, b);
    }
    if(x > d && x != 1e9)
    {
        swap(x, d);
    }
    if(x > c && x != 1e9)
    {
        swap(x, c);
    }
}
int Tree[4 * N];
int upd[4 * N];
void push(int v, int l, int r)
{
    if(upd[v] == 0)
    {
        return;
    }
    int m = (r + l) / 2;
    Tree[v * 2] = (m - l + 1) * upd[v];
    Tree[v * 2 + 1] = (r - m) * upd[v];
    upd[v * 2] = upd[v * 2 + 1] = upd[v];
    upd[v] = 0;
}
void update(int v, int l, int r, int al, int ar, int x)
{
    if(l >= al && r <= ar)
    {
        upd[v] = x;
        Tree[v] = (r - l + 1) * x;
    }
    else if(l <= ar && r >= al)
    {
        push(v, l, r);
        update(v * 2, l, (r + l) / 2, al, ar, x);
        update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, x);
        Tree[v] = Tree[v * 2] + Tree[v * 2 + 1];
    }
}
int getnum(int v, int l, int r, int x)
{
    if(l == r)
    {
        return upd[v];
    }
    int m = (r + l) / 2;
    push(v, l, r);
    if(x <= m)
    {
        return getnum(v * 2, l, m, x);
    } 
    else
    {
        return getnum(v * 2 + 1, m + 1, r, x);
    }
}
int getsum(int v, int l, int r, int al, int ar)
{
    if(l >= al && r <= ar)
    {
        return Tree[v];
    }
    else if(l <= ar && r >= al)
    {
        push(v, l, r);
        return getsum(v * 2, l, (r + l) / 2, al, ar) + getsum(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
    }
    return 0;
}
int add(int l, int r, int val)
{
    if(l > r)
    {
        return 0;
    }
    int l1 = l - 1, r1 = r + 1;
    while(r1 - l1 > 1)
    {
        int midd = (l1 + r1) / 2;
        if(getnum(1, 0, n - 1, midd) <= val)
        {
            l1 = midd;
        }
        else
        {
            r1 = midd;
        }
    }
    int s1 = 0;
    if(l1 >= l)
    {
        s1 = (l1 - l + 1) * val - getsum(1, 0, n - 1, l, l1);
        update(1, 0, n - 1, l, l1, val);
    }
    return s1;
}
signed main()
{
//  ios_base::sync_with_stdio(0);
//  cin.tie(0);
//  cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        update(1, 0, n - 1, i, i, i - 1);
    }
    vector <int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        vec[a[i]].push_back(i);
    }
    int ans = 0;
    for(int i = N; i >= 1; i--)
    {
        int min1 = 1e9, min2 = 1e9;
        int max1 = -1, max2 = -1;
        for(int j = i; j <= N; j += i)
        {
            for(int k = 0; k < min(sz(vec[j]), 2LL); k++)
            {
                relax(min1, min2, max1, max2, vec[j][k]);
            }
            if(sz(vec[j]) > 2)
            {
                for(int k = sz(vec[j]) - 1; k >= max(2LL, sz(vec[j]) - 2); k--)
                {
                    relax(min1, min2, max1, max2, vec[j][k]);
                }
            }
        }
        if(min2 == 1e9)
        {
            cnt[i] = 0;
        }
        else if(max2 == -1)
        {
            int idx1 = min1;
            int idx2 = min2;
            cnt[i] = add(0, idx1 - 1, idx1 - 1) + add(idx1 + 1, idx2 - 1, idx2 - 1) + add(idx2 + 1, n - 1, n - 1);
        }
        else if(max1 == -1)
        {
            int idx1 = min1;
            int idx2 = min2;
            int idx3 = max2;
            cnt[i] = add(0, idx1, idx2 - 1) + add(idx1 + 1, idx2, idx3 - 1) + add(idx2 + 1, n - 1, n - 1);
        }
        else
        {
            int idx1 = min1;
            int idx2 = min2;
            int idx3 = max1;
            int idx4 = max2;
            cnt[i] = add(0, idx1, idx3 - 1) + add(idx1 + 1, idx2, idx4 - 1) + add(idx2 + 1, n - 1, n - 1);
        }
       /* if(min1 != 1e9)
        {
            cout << i << " " << cnt[i] << " " << min1 << " " << min2 << " " << max1 << " " << max2 << "\n";
            for(int i = 0; i < n; i++)
            {
                cout << getnum(1, 0, n - 1, i) << " ";
            }
            cout << "\n";
        }*/
        ans += cnt[i] * i;
    }
    cout << ans;
    return 0;
}