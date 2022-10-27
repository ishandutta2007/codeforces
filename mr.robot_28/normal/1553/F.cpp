#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
using namespace std;
const int N = 3e5 + 100;
int Tree_cnt[N * 4];
ll Tree_sum[4 * N], Tree_sum1[4 * N];
ll sum1(int v, int l, int r, int al, int ar)
{
    if(l >= al && r <= ar)
    {
        return Tree_sum[v];
    }
    if(l <= ar && r >= al)
    {
        return sum1(v * 2, l, (r + l) / 2, al, ar) + sum1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
    }
    return 0;
}
int cnt1(int v, int l, int r, int al, int ar)
{
    if(l >= al && r <= ar)
    {
        return Tree_cnt[v];
    }
    if(l <= ar && r >= al){
        return cnt1(v * 2, l, (r + l) / 2, al, ar) + cnt1(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
    }
    return 0;
}
ll sum2(int v, int l, int r, int al, int ar)
{
    if(l >= al && r <= ar)
    {
        return Tree_sum1[v];
    }
    if(l <= ar && r >= al)
    {
        return sum2(v * 2, l, (r + l) / 2, al, ar) + sum2(v * 2 + 1, (r + l)  /2 + 1, r, al, ar);
    }
    return 0;
}
void add_cnt(int v, int l, int r, int x)
{
    Tree_cnt[v]++;
    if(l == r)
    {
        return;
    }
    if(x <= (r + l) / 2)
    {
        add_cnt(v * 2, l, (r + l) / 2, x);
    }
    else
    {
        add_cnt(v * 2 + 1, (r + l) / 2 + 1, r, x);
    }
}
void add_sum1(int v, int l, int r, int x)
{
    Tree_sum[v] += x;
    if(l == r)
    {
        return;
    }
    if(x <= (r + l) / 2)
    {
        add_sum1(v * 2, l, (r + l) / 2, x);
    }
    else
    {
        add_sum1(v * 2 + 1, (r + l) / 2 + 1, r, x);
    }
}
void add_sum2(int v, int l, int r, int x, int add)
{
    Tree_sum1[v] += add;
    if(l == r)
    {
        return;
    }
    if(x <= (r + l) / 2)
    {
        add_sum2(v * 2, l, (r + l) / 2, x, add);
    }
    else
    {
        add_sum2(v * 2 + 1, (r + l) / 2 + 1, r, x, add);
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    fill(Tree_sum, Tree_sum + 4 * N, 0);
    fill(Tree_cnt, Tree_cnt + 4 * N, 0);
    fill(Tree_sum1, Tree_sum1 + 4 * N, 0);
    ll s = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= 3e5; j += a[i])
        {
             s += sum1(1, 0, N - 1, j, min(j + a[i], N) - 1) - 1LL * cnt1(1, 0, N - 1, j, min(j + a[i], N) - 1) * j;
        }
        s += 1LL * cnt1(1, 0, N - 1, 0, a[i]) * a[i] - sum2(1, 0, N - 1, 0, a[i]);
        s += 1LL * cnt1(1, 0, N - 1, a[i] + 1, N - 1) * a[i];
        cout << s << " ";
        add_cnt(1, 0, N - 1, a[i]);
        add_sum1(1, 0, N - 1, a[i]);
        for(int j = a[i]; j <= 3e5; j += a[i])
        {
            add_sum2(1, 0, N - 1, j, a[i]);
        }
    }
    return 0;
}