#include<bits/stdc++.h>
using namespace std;
const int nmax=3e5+42;
int n,m;
pair<int,int> inp[nmax];
bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first!=b.first)return a.first<b.first;
    return a.second<b.second;
}
vector<int> tree[1<<20];
int l[nmax],r[nmax];
void build(int node,int l_,int r_)
{
    if(l_==r_)
    {
        tree[node].push_back(r[r_]);
        return;
    }
    int av=(l_+r_)/2;
    build(node*2,l_,av);
    build(node*2+1,av+1,r_);
    tree[node]=tree[node*2];
    for(auto k:tree[node*2+1])tree[node].push_back(k);
    sort(tree[node].begin(),tree[node].end());
}
int pos,p[nmax];
int BORDER;
int query(int node,int l_,int r_,int lq,int rq)
{
    if(l_==lq&&r_==rq)
    {
        int q=upper_bound(tree[node].begin(),tree[node].end(),BORDER)-tree[node].begin();
        return q;
    }
    int av=(l_+r_)/2,ans=0;
    if(lq<=av)ans=ans+query(node*2,l_,av,lq,min(av,rq));
    if(av<rq)ans=ans+query(node*2+1,av+1,r_,max(av+1,lq),rq);
    return ans;
}
int q(int l_,int r_)
{

    if(l_>r_)return 0;
    int s=lower_bound(l+1,l+n+1,l_)-l;
    int t=upper_bound(l+1,l+n+1,r_)-l-1;
    if(s>t)return 0;
    BORDER=r_;
    int v=query(1,1,n,s,t);
    //cout<<l_<<" "<<r_<<" -> "<<v<<endl;
    return v;

    /*
    int ans=0;
    for(int i=1;i<=n;i++)
        if(l_<=l[i]&&r[i]<=r_)ans++;
    return ans;
    */
}
int main()
{
scanf("%i%i",&n,&m);
for(int i=1;i<=n;i++)scanf("%i%i",&inp[i].first,&inp[i].second);
sort(inp+1,inp+n+1,cmp);
for(int i=1;i<=n;i++)l[i]=inp[i].first,r[i]=inp[i].second;
build(1,1,n);
for(int i=1;i<=m;i++)
{
    scanf("%i",&pos);
    for(int j=1;j<=pos;j++)scanf("%i",&p[j]);
    sort(p+1,p+pos+1);
    int ans=n-q(-42,p[1]-1)-q(p[pos]+1,1e6+42);
    for(int j=2;j<=pos;j++)
        ans=ans-q(p[j-1]+1,p[j]-1);
    printf("%i\n",ans);
}
return 0;
}