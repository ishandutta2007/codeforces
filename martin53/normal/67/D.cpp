#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,a[nmax],b[nmax];
int where_a[nmax],where_b[nmax];
pair<int/*x*/,int/*y*/> points[nmax];
bool cmp(pair<int/*x*/,int/*y*/> a,pair<int/*x*/,int/*y*/> b)
{
    return a.first<b.first;
}
int tree[4*nmax];
int dp[nmax];
int query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[node];
    int av=(l+r)/2,ans=0;
    if(lq<=av)ans=max(ans,query(node*2,l,av,lq,min(av,rq)));
    if(av<rq)ans=max(ans,query(node*2+1,av+1,r,max(av+1,lq),rq));
    return ans;
}
void update(int node,int l,int r,int pos,int value)
{
    if(l==r)
    {
        tree[node]=value;
        return;
    }
    int av=(l+r)/2;
    if(pos<=av)update(node*2,l,av,pos,value);
    else update(node*2+1,av+1,r,pos,value);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)
{
scanf("%i",&a[i]);
where_a[a[i]]=i;
}
for(int i=1;i<=n;i++)
{
scanf("%i",&b[i]);
where_b[b[i]]=i;
}
for(int i=1;i<=n;i++)points[i]={where_a[i],where_b[i]};
sort(points+1,points+n+1,cmp);
int maxi=0;
for(int i=n;i>=1;i--)
{
    dp[i]=1+query(1,1,n,1,points[i].second);
    update(1,1,n,points[i].second,dp[i]);
    maxi=max(maxi,dp[i]);
}
printf("%i\n",maxi);
return 0;
}