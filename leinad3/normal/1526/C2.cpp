#include<bits/stdc++.h>
#define int long long
using namespace std;
int t, n, i, j, k, A[200010], seg[800010], lazy[800010], ans;
void busy(int id)
{
    seg[id*2]+=lazy[id];
    seg[id*2+1]+=lazy[id];
    lazy[id*2]+=lazy[id];
    lazy[id*2+1]+=lazy[id];
    lazy[id]=0;
}
void update(int id, int s, int e, int l, int r, int v)
{
    if(e<l||r<s)return;
    if(l<=s&&e<=r)
    {
        seg[id]+=v;
        lazy[id]+=v;
        return;
    }
    int m=s+e>>1;busy(id);
    update(id*2, s, m, l, r, v);update(id*2+1, m+1, e, l, r, v);
    seg[id]=min(seg[id*2], seg[id*2+1]);
}
int get(int id, int s, int e, int l, int r)
{
    if(e<l||r<s)return 1e18;
    if(l<=s&&e<=r)return seg[id];
    int m=s+e>>1;busy(id);
    return min(get(id*2, s, m, l, r), get(id*2+1, m+1, e, l, r));
}
main()
{
    for(scanf("%lld", &n);i++<n;)scanf("%lld", &A[i]);
    vector<pair<int, int> >v;
    for(i=0;i++<n;)
    {
        if(A[i]>=0)update(1, 1, n, i, n, A[i]),ans++;
        else v.push_back({-A[i], -i});
    }
    sort(v.begin(), v.end());
    for(i=0;i<v.size();i++)
    {
        int a=-v[i].first;int b=-v[i].second;
        if(get(1, 1, n, b, n)+a>=0)
        {
            ans++;
            update(1, 1, n, b, n, a);
        }
    }
    cout<<ans;
}