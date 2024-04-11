#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
#define ld long double
const int N = 1e5;
deque <pair <int, int> > lines[N];
int it = 0;
int dp[N];
int st_idx = 0;
pair <int, int> Li_Chao[4 * N];
int Flag[N * 4];
int it_left[N * 4], it_right[N * 4];
int cur;
void build(int l, int r)
{
    it++;
    Flag[it] = 0;
    Li_Chao[it] = {1e9, 1e9};
    if(l >= r)
    {
        return ;
    }
    int it_cur = it;
    it_left[it] = it + 1;
    int midd = (r + l) / 2;
    build(l, midd - 1);
    it_right[it] = it + 1;
    build(midd + 1, r);
}
int ans(int v, int l, int r, int idx)
{
    if(!Flag[v])
    {
        return 1e18;
    }
    //cout << "A " << l << " " << r << "\n";
    //cout << Li_Chao[v].X << " " << Li_Chao[v].Y << "\n";
    int m = (r + l) / 2;
    if(m == idx)
    {
        return Li_Chao[v].X * idx + Li_Chao[v].Y;
    }
    int ns = Li_Chao[v].X * idx + Li_Chao[v].Y;
    if(idx <= (r + l) / 2)
    {
        return min(ns, ans(it_left[v],  l, m - 1, idx));
    }
    return min(ns, ans(it_right[v], m + 1, r, idx));
}
void update(int v, int l, int r, int k, int b)
{
    if(l > r)
    {
        return;
    }
    it++;
    int m = (r + l) / 2;
    if(!Flag[v])
    {
        Flag[it] = 1;
        Li_Chao[it] = {k, b};
        it_left[it] = it_left[v];
        it_right[it] = it_right[v];
        return;
    }
    Li_Chao[it] = Li_Chao[v];
    Flag[it] = 1;
    pair <int, int> t = {k, b};
    bool fl1 = (k * m + b) < (Li_Chao[v].X * m + Li_Chao[v].Y);
    bool fl2 = (k * l + b) < (Li_Chao[v].X * l + Li_Chao[v].Y);
    if(fl1)
    {
        swap(Li_Chao[it], t);
    }
    if(fl1 ^ fl2)
    {
        it_left[it] = it + 1;
        it_right[it] = it_right[v];
        update(it_left[v], l, m - 1, t.X, t.Y);
    }
    else
    {
        it_right[it] = it + 1;
        it_left[it] = it_left[v];
        update(it_right[v], m + 1, r, t.X, t.Y);
    }
}
ld inter(pair <int, int> a, pair <int, int> b)
{
    ld dk = a.X - b.X;
    ld db = b.Y  - a.Y;
    return db / dk;
}
void unite(int a, int b)
{
    bool fl = 0;
    if(sz(lines[b]) > sz(lines[a]))
    {
        swap(lines[a], lines[b]);
        fl = 1;
    }
    if(fl)
    {
        for(int i = 0; i < sz(lines[b]); i++)
        {
            while(sz(lines[a]) > 1 && inter(lines[a][sz(lines[a]) - 1], lines[a][sz(lines[a]) - 2]) >=
                  inter(lines[a][sz(lines[a]) - 2], lines[b][i]))
            {
                lines[a].pop_back();
            }
            lines[a].push_back(lines[b][i]);
        }
    }
    else
    {
        for(int i = sz(lines[b]) - 1; i >= 0; i--)
        {
            while(sz(lines[a]) > 1 && inter(lines[a][0], lines[a][1]) <= inter(lines[b][i], lines[a][1]))
            {
                lines[a].pop_front();
            }
            lines[a].push_front(lines[b][i]);
        }
    }
}
int min_funct(int idx, int x)
{
    int l = -1, r = sz(lines[idx]) - 1;
    while(r - l > 1)
    {
        int midd = (r + l) / 2;
        if(inter(lines[idx][midd], lines[idx][midd + 1]) <= x)
        {
            l = midd;
        }
        else
        {
            r = midd;
        }
    }
    l++;
    return lines[idx][l].X * x + lines[idx][l].Y;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    build(0, n - 1);
    vector <int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector <int> dp(n + 1, 1e18);
    vector <int> dp1(n + 1, 1e18);
    dp[0] = 0;
    for(int j = 0; j < k; j++)
    {
        it = 0;
        cur = it + 1;
        build(0, n - 1);
        dp1[0] = 0;
        stack <pair <int, pair <int, int> > > st;
        st.push({1e10, {cur, -1}});
        st_idx = 0;
        for(int i =1 ;  i <= n; i++)
        {
            lines[i].clear();
        }
        for(int i = 0; i < n; i++)
        {
            st_idx++;
            lines[st_idx].push_back({-(i - 1), dp[i]});
            while(st.top().X <= a[i])
            {
                unite(st_idx, st.top().Y.Y);
                st.pop();
            }
            int f = min_funct(st_idx, a[i]);
            int st_it = st.top().Y.X;
            cur = it + 1;
            update(st_it, 0, n - 1, a[i], f);
            st.push({a[i], {cur, st_idx}});
            int val = ans(cur, 0, n - 1, i);
            dp1[i + 1] = val;
        }
        for(int i = 0; i<= n; i++)
        {
            dp[i] = dp1[i];
        }
    }
    cout << dp[n];
    return 0;
}