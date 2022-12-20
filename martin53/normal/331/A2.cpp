#include<bits/stdc++.h>
using namespace std;
const int nmax=3e5+42;
int n,arr[nmax];
long long tree[4*nmax];
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=max(arr[l],0);
        return;
    }
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);
    tree[node]=tree[node*2]+tree[node*2+1];
}
long long query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[node];
    int av=(l+r)/2;
    long long sum=0;
    if(lq<=av)sum=sum+query(node*2,l,av,lq,min(av,rq));
    if(av<rq)sum=sum+query(node*2+1,av+1,r,max(av+1,lq),rq);
    return sum;
}
map<int,int> seen;
vector<int> output;
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)scanf("%i",&arr[i]);
build(1,1,n);
for(int i=1;i<=n;i++)
    seen[arr[i]]=i;

long long ans=-1e18;
int ind=0,l_,r_;
for(int l=1;l<=n;l++)
{
    int r=seen[arr[l]];
    if(l==r)continue;
    long long now=2*arr[l];
    if(l+1<=r-1)now=now+query(1,1,n,l+1,r-1);
    if(now>ans)
    {
        ans=now;
        ind=l;
        l_=l;
        r_=r;
    }
}
printf("%lld",ans);
for(int i=1;i<=n;i++)
    if(i<l_||i>r_||(arr[i]<0&&i!=l_&&i!=r_))output.push_back(i);
printf(" %i\n",output.size());
for(auto k:output)printf("%i ",k);printf("\n");
return 0;
}