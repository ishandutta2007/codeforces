#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
#define endl '\n'

using namespace std;

int it[2000005][2];
int lazy[2000005][2];
int n, p, q, r;
pair<int, pair<int, int> > a[500005];
int maxb[500005], maxc[500006];

void down(int id, int l, int r, int type)
{
    int mid=(l+r)/2;
    it[id*2][type]=lazy[id][type]*(mid-l+1);
    it[id*2+1][type]=lazy[id][type]*(r-mid);
    lazy[id*2][type]=lazy[id][type];
    lazy[id*2+1][type]=lazy[id][type];
    lazy[id][type]=-1;
}

void update(int id, int l, int r, int u, int v, int val, int type)
{
    if(l>v||r<u)
    {
        return;
    }
    if(l>=u&&r<=v)
    {
        it[id][type]=val*(r-l+1);
        lazy[id][type]=val;
        return;
    }
    if(lazy[id][type]!=-1)
    {
        down(id, l, r, type);
    }
    int mid=(l+r)/2;
    update(id*2, l, mid, u, v, val, type);
    update(id*2+1, mid+1, r, u, v, val, type);
    it[id][type]=it[id*2][type]+it[id*2+1][type];
}

int get(int id, int l, int r, int u, int v, int type)
{
    if(l>v||r<u)
    {
        return 0;
    }
    if(l>=u&&r<=v)
    {
        return it[id][type];
    }
    if(lazy[id][type]!=-1)
    {
        down(id, l, r, type);
    }
    int mid=(l+r)/2;
    return get(id*2, l, mid, u, v, type) + get(id*2+1, mid+1, r, u, v, type);
}

void updatee(int it)
{
    int lol=get(1, 0, r, a[it].second.second, a[it].second.second, 1);
    if(lol>=a[it].second.first) return;
    update(1, 1, q, lol+1, a[it].second.first, a[it].second.second, 0);
    int yo=get(1, 1, q, a[it].second.first+1, a[it].second.first+1, 0);
    update(1, 0, r, yo+1, a[it].second.second, a[it].second.first, 1);    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(lazy, -1, sizeof(lazy));
    cin>>n>>p>>q>>r;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i].first>>a[i].second.first>>a[i].second.second;
    }
    sort(a+1, a+n+1);
    a[n+1]={p+1, {0, 0}};
    for(int i=n; i>=1; i--)
    {
        maxb[i]=max(maxb[i+1], a[i].second.first);
        maxc[i]=max(maxc[i+1], a[i].second.second);
    }
    update(1, 0, r, 0, 0, q, 1);
    int it=1, ans=0;
    for(int i=1; i<=p; i++)
    {
        while(a[it].first<i)
        {
            updatee(it);
            it++;
        }
        int pos=get(1, 0, r, maxc[it], maxc[it], 1);
        if(pos<maxb[it]) pos=maxb[it];
        ans+=r*(q-maxb[it]);
        // cout<<ans<<endl;
        ans-=get(1, 1, q, maxb[it]+1, pos, 0)+(q-pos)*maxc[it];
        // cout<<ans<<endl;
    }
    cout<<ans;
}