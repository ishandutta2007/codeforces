#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,BIT=20;
int n,m;
int a[nmax];
struct vertex
{
int zeros,ones;
bool reversed;
};
vertex tree[BIT][4*nmax];

vertex actual(vertex x)
{
if(x.reversed)swap(x.zeros,x.ones);
x.reversed=0;
return x;
}

vertex my_merge(vertex a,vertex b)
{
a=actual(a);
b=actual(b);

a.ones=a.ones+b.ones;
a.zeros=a.zeros+b.zeros;
return a;
}

void update_node(int bit,int node)
{
if(tree[bit][node].reversed)
{
tree[bit][node*2].reversed=!tree[bit][node*2].reversed;
tree[bit][node*2+1].reversed=!tree[bit][node*2+1].reversed;
}
tree[bit][node].reversed=0;
}

void build(int bit,int node,int l,int r)
{
if(l==r)
{
tree[bit][node].ones=(a[l]>>bit)&1;
tree[bit][node].zeros=1-tree[bit][node].ones;
//cout<<bit<<" "<<node<<" "<<tree[bit][node].ones<<" "<<tree[bit][node].zeros<<endl;
return;
}
int av=(l+r)/2;
build(bit,node*2,l,av);
build(bit,node*2+1,av+1,r);
tree[bit][node]=my_merge(tree[bit][node*2],tree[bit][node*2+1]);
}

int query(int bit,int node,int l,int r,int lq,int rq)
{
if(l==lq&&r==rq)return actual(tree[bit][node]).ones;
update_node(bit,node);
int av=(l+r)/2;
int ans=0;
if(lq<=av)ans=ans+query(bit,node*2,l,av,lq,min(av,rq));
if(av<rq)ans=ans+query(bit,node*2+1,av+1,r,max(av+1,lq),rq);
tree[bit][node]=my_merge(tree[bit][node*2],tree[bit][node*2+1]);
return ans;
}

void update(int bit,int node,int l,int r,int lq,int rq)
{
if(l==lq&&r==rq)
{
tree[bit][node].reversed=!tree[bit][node].reversed;
return;
}
update_node(bit,node);
int av=(l+r)/2;
if(lq<=av)update(bit,node*2,l,av,lq,min(av,rq));
if(av<rq)update(bit,node*2+1,av+1,r,max(av+1,lq),rq);
tree[bit][node]=my_merge(tree[bit][node*2],tree[bit][node*2+1]);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
cin>>m;
for(int i=0;i<BIT;i++)
    {
    build(i,1,1,n);
    //cout<<endl;
    //system("pause");
    }
int t,l,r,x;
for(int i=1;i<=m;i++)
{
cin>>t>>l>>r;
    if(t==1)
    {
    long long sum=0;
        for(int j=0;j<BIT;j++)
            sum=sum+(1LL<<j)*query(j,1,1,n,l,r);
    cout<<sum<<endl;
    }
    else
    {
    cin>>x;
        for(int j=0;j<BIT;j++)
            if((x&(1<<j)))
                update(j,1,1,n,l,r);
    }
}
return 0;
}