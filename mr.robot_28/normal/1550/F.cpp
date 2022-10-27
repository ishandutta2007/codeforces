#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
//#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 3e5;
int a[N];
int n, q, s, d;
int dist[N];
set <pair <int, int> > st;
set <pair <int, int> > st1;
void add_points(int l, int r, int d1)
{
    int idx = upper_bound(a, a + n, r) - a;
    if(idx != n && dist[idx] > d1 + a[idx] - r)
    {
        st.erase({dist[idx], idx});
        dist[idx] = d1 + a[idx] - r;
        st.insert({dist[idx], idx});
    }
    idx = lower_bound(a, a + n, l) - a;
    idx--;
    if(idx >= 0 && dist[idx] > d1 + l - a[idx])
    {
        st.erase({dist[idx], idx});
        dist[idx] = d1 + l - a[idx];
        st.insert({dist[idx], idx});
    }
}
void go_to(int v, int d1)
{
    int l1 = a[v] - d - d1;
    int r1 = a[v] - d + d1;
    int l2 = a[v] + d - d1;
    int r2 = a[v] + d + d1;
    add_points(l1, r1, d1);
    add_points(l2, r2, d1);
    while(sz(st1) > 0)
    {
        auto it = st1.lower_bound(make_pair(l1, 0));
        if(it == st1.end() || it -> X > r1)
        {
            break;
        }
        int v1 = it -> Y;
        st1.erase(*it);
        if(dist[v1] > d1)
        {
            st.erase({dist[v1], v1});
            dist[v1] = d1;
            st.insert({d1, v1});
        }
    }
    while(sz(st1) > 0)
    {
        auto it = st1.lower_bound(make_pair(l2, 0));
        if(it == st1.end() || it -> X > r2)
        {
            break;
        }
        int v1 = it -> Y;
        st1.erase(*it);
        if(dist[v1] > d1)
        {
            st.erase({dist[v1], v1});
            dist[v1] = d1;
            st.insert({d1, v1});
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q >> s >> d;
    s--;
    for(int i = 0; i < n; i++)
    {
        dist[i] = 1e9;
        cin >> a[i];
        st1.insert({a[i], i});
    }
    go_to(s, 0);
    while(sz(st) != 0)
    {
        int v = st.begin() -> Y;
        st.erase(st.begin());
        go_to(v, dist[v]);
        if(v < n - 1 && dist[v + 1] > dist[v] + a[v + 1] - a[v])
        {
            st.erase({dist[v + 1], v + 1});
            dist[v + 1] = dist[v] + a[v + 1] - a[v];
            st.insert({dist[v + 1], v + 1});
        }
        if(v > 0 && dist[v - 1] > dist[v] + a[v] - a[v - 1] )
        {
            st.erase({dist[v - 1], v - 1});
            dist[v - 1] = dist[v] + a[v] - a[v - 1];
            st.insert({dist[v - 1], v - 1});
        }
    }
    while(q--)
    {
        int i, k;
        cin >> i >> k;
        i--;
        if(dist[i] <= k || i == s)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}