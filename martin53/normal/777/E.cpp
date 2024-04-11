#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
struct pile
{
int a,b,h;
};
int n;
pile inp[nmax];
int sorted[nmax];
bool cmp(pile x,pile y)
{
if(x.b!=y.b)return x.b<y.b;
return x.a<y.a;
}
long long dp[nmax];
int take_index(int x)
{
int p=upper_bound(sorted+1,sorted+n+1,x)-sorted;
return p;
}
long long tree[4*nmax];
long long query(int node,int l,int r,int lq,int rq)
{
if(l==lq&&r==rq)return tree[node];
long long ans=0;
int av=(l+r)/2;
if(lq<=av)ans=max(ans,query(node*2,l,av,lq,min(av,rq)));
if(av<rq)ans=max(ans,query(node*2+1,av+1,r,max(av+1,lq),rq));
return ans;
}
void update(int node,int l,int r,int pos,long long value)
{
if(l==r)
{
tree[node]=max(tree[node],value);
return;
}
int av=(l+r)/2;
if(pos<=av)update(node*2,l,av,pos,value);
else update(node*2+1,av+1,r,pos,value);
tree[node]=max(tree[node*2],tree[node*2+1]);
}
int index(int x)
{
int p=lower_bound(sorted+1,sorted+n+1,x)-sorted;
return p;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>inp[i].a>>inp[i].b>>inp[i].h;
sorted[i]=inp[i].b;
}
sort(sorted+1,sorted+n+1);
sort(inp+1,inp+n+1,cmp);

//cout<<endl;for(int i=1;i<=n;i++)cout<<inp[i].a<<" "<<inp[i].b<<" "<<inp[i].h<<endl;

for(int i=1;i<=n;i++)
{
    dp[i]=inp[i].h+query(1,1,n,take_index(inp[i].a),n);
    update(1,1,n,index(inp[i].b),dp[i]);
    //cout<<i<<" -> "<<dp[n]<<endl;
}
long long ans=0;
for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
cout<<ans<<endl;
return 0;
}