#include<bits/stdc++.h>
using namespace std;
const int nmax=3e5+42;
int n,a;
pair<int/*difficulty*/,int/*cost*/> inp[nmax];
int order[nmax];
bool cmp(int a,int b)
{
    return inp[a+1].first-inp[a].first<inp[b+1].first-inp[b].first;
}
int parent[nmax],le[nmax],ri[nmax];
int root(int node)
{
    if(parent[node]==node)return node;
    parent[node]=root(parent[node]);
    return parent[node];
}
long long prefix[nmax];
pair<long long/*max*/,long long/*min*/> tree[4*nmax];
pair<long long/*max*/,long long/*min*/> my_merge(pair<long long/*max*/,long long/*min*/> a,pair<long long/*max*/,long long/*min*/> b)
{
    return {max(a.first,b.first),min(a.second,b.second)};
}
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]={prefix[l],prefix[r]};
        return;
    }
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);
    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}
pair<long long/*max*/,long long/*min*/> query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[node];
    int av=(l+r)/2;
    pair<long long/*max*/,long long/*min*/> ret={-1e18,1e18};
    if(lq<=av)ret=my_merge(ret,query(node*2,l,av,lq,min(av,rq)));
    if(av<rq)ret=my_merge(ret,query(node*2+1,av+1,r,max(av+1,lq),rq));
    return ret;
}
int main()
{
cin>>n>>a;
for(int i=1;i<=n;i++)cin>>inp[i].first>>inp[i].second;

for(int i=1;i<n;i++)order[i]=i;
sort(order+1,order+n,cmp);

for(int i=1;i<=n;i++)prefix[i]=prefix[i-1]+a-inp[i].second;
build(1,1,n);

long long ans=0;
for(int i=1;i<=n;i++)ans=max(ans,1LL*a-inp[i].second);
build(1,0,n);

for(int i=1;i<=n;i++)
{
    parent[i]=i;
    le[i]=i;
    ri[i]=i;
}

for(int t=1;t<n;t++)
{
    int i=order[t];
    int p=root(i),q=root(i+1);
    ri[p]=max(ri[p],ri[q]);
    le[p]=min(le[p],le[q]);
    parent[q]=p;

    long long now=a-inp[i].second+a-inp[i+1].second-1LL*(inp[i].first-inp[i+1].first)*(inp[i].first-inp[i+1].first);

    now=now+prefix[i-1]-query(1,0,n,le[p]-1,i-1).second;
    now=now+query(1,0,n,i+1,ri[p]).first-prefix[i+1];

    ans=max(ans,now);
}
cout<<ans<<endl;
return 0;
}