#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
struct domino
{
int x,h,ind;
};
int n;
domino inp[nmax];
bool cmp(domino a,domino b)
{
return a.x<b.x;
}
int x[nmax];
int tree[4*nmax];
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
        tree[node]=max(tree[node],value);
        return;
    }
    int av=(l+r)/2;
    if(pos<=av)update(node*2,l,av,pos,value);
    else update(node*2+1,av+1,r,pos,value);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}
int where[nmax],outp[nmax];
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();

cin>>n;
for(int i=1;i<=n;i++)
{
cin>>inp[i].x>>inp[i].h;
inp[i].ind=i;
}
sort(inp+1,inp+n+1,cmp);
for(int i=1;i<=n;i++)x[i]=inp[i].x;
for(int i=n;i>=1;i--)
{
    int p=upper_bound(x+1,x+n+1,inp[i].x)-x;
    int q=lower_bound(x+1,x+n+1,inp[i].x+inp[i].h)-x-1;
    if(p>q)where[i]=i;
    else where[i]=query(1,1,n,p,q);
    update(1,1,n,i,where[i]);
    outp[inp[i].ind]=where[i]-i+1;
}
for(int i=1;i<=n;i++)cout<<outp[i]<<" ";cout<<endl;
return 0;
}