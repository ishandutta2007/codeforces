#include <bits/stdc++.h>
using namespace std;
int v[100005];
vector<int>pz[100005];
struct ura
{
    int x,y;
};
vector<ura>q;
bool cmp (ura a, ura b)
{
    return a.y<b.y;
}
int aint[400005];
void update (int nod, int st, int dr, int pz, int val)
{
    if(st==dr)
    {
        aint[nod]=val;
        return;
    }
    int mid=(st+dr)/2;
    if(pz<=mid)
        update(nod*2,st,mid,pz,val);
    else
        update(nod*2+1,mid+1,dr,pz,val);
    aint[nod]=min(aint[nod*2],aint[nod*2+1]);
}
int query (int nod, int st, int dr, int l)
{
    if(st==dr)
        return st;
    int mid=(st+dr)/2;
    if(aint[nod*2]<l)
        return query(nod*2,st,mid,l);
    else
        return query(nod*2+1,mid+1,dr,l);
}
int fv[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int s=0,n,i,t,j;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        pz[v[i]].push_back(i);
    }
    q.push_back({1,n});
    for(i=1;i<=n;++i)
    {
        int prec=0;
        for(j=0;j<pz[i].size();++j)
        {
            if(prec+1<=pz[i][j]-1)
                q.push_back({prec+1,pz[i][j]-1});
            prec=pz[i][j];
        }
        if(prec!=0 && prec+1<=n)
            q.push_back({prec+1,n});
    }
    sort(q.begin(),q.end(),cmp);
    j=0;
    for(i=1;i<=n;++i)
    {
        update(1,1,n+1,v[i],i);
        while(j<q.size() && q[j].y==i)
        {
            ++fv[query(1,1,n+1,q[j].x)];
            ++j;
        }
    }
    for(i=1;i<=n+2;++i)
        if(!fv[i])
        {
            cout<<i;
            break;
        }
    return 0;
}