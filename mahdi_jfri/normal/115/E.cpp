#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
ll l[maxn] , p[maxn] , dp[maxn] , mx[maxn * 4] , lazy[maxn * 4] , ps[maxn] , a[maxn];
vector<int> v[maxn];

void shift(int s , int e , int v)
{
    if(e - s >= 2)
    {
        lazy[2 * v] += lazy[v];
        mx[2 * v] += lazy[v];
        lazy[2 * v + 1] += lazy[v];
        mx[2 * v + 1] += lazy[v];
    }
    lazy[v] = 0;
}

void add(int l , int r , ll val , int s , int e , int v)
{
    if(r <= l)
        return;
    if(l <= s && e <= r)
    {
        lazy[v] += val;
        mx[v] += val;
        return;
    }
    if(r <= s || e <= l)
        return;
    shift(s , e , v);
    int m = (s + e) / 2;
    add(l , r , val , s , m , 2 * v);
    add(l , r , val , m , e , 2 * v + 1);
    mx[v] = max(mx[2 * v] , mx[2 * v + 1]);
}

ll get(int l , int r , int s , int e , int v)
{
    if(r <= l)
        return -1e16;
    if(l <= s && e <= r)
        return mx[v];
    if(r <= s || e <= l)
        return -1e16;
    shift(s , e , v);
    int m = (s + e) / 2;
    return max(get(l , r , s , m , 2 * v) , get(l , r , m , e , 2 * v + 1));
}

int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i] , ps[i] = ps[i - 1] + a[i];
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> l[i] >> x >> p[i];
        v[x].pb(i);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < (int)v[i].size(); j++)
        {
            int e = v[i][j];
            add(0 , l[e] , p[e] , 0 , n + 1 , 1);
        }
        dp[i] = max(dp[i - 1] , get(0 , i + 1 , 0 , n + 1 , 1) - ps[i]);
        add(i , i + 1 , dp[i] + ps[i] , 0 , n + 1 , 1);
    }
    cout << dp[n] << endl;
}