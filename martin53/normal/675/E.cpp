#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,arr[nmax];
long long p[nmax],tree[4*nmax];
void update(int node,int l,int r,int pos,long long value)
{
    if(l==r)
    {
        tree[node]=value;
        return;
    }
    int av=(l+r)/2;
    if(pos<=av)update(node*2,l,av,pos,value);
    else update(node*2+1,av+1,r,pos,value);
    tree[node]=min(tree[node*2],tree[node*2+1]);
}
long long query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[node];
    int av=(l+r)/2;
    long long ans=1e18;
    if(lq<=av)ans=min(ans,query(node*2,l,av,lq,min(av,rq)));
    if(av<rq)ans=min(ans,query(node*2+1,av+1,r,max(av+1,lq),rq));
    return ans;
}
int main()
{
for(int i=0;i<4*nmax;i++)
    tree[i]=1e18;
cin>>n;
for(int i=1;i<n;i++)cin>>arr[i];
long long s=0;
for(int i=n;i>=1;i--)
{
    if(i==n||arr[i]==n)p[i]=n-i;
    else
    {
        p[i]=n-i-arr[i]+query(1,1,n,i+1,arr[i]);
    }
    update(1,1,n,i,p[i]+i);
    s=s+p[i];
    //cout<<i<<" -> "<<p[i]<<" "<<arr[i]<<endl;
}
cout<<s<<endl;
return 0;
}