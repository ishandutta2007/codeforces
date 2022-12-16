#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int tree[nmax*4][60];//node; x mod 60
int n;
int arr[nmax];
int t;
void make_node(int node,int l)
{
    for(int i=0;i<60;i++)
        if(i%arr[l]==0)tree[node][i]=2;
        else tree[node][i]=1;
}
void combine(int node)
{
    for(int i=0;i<60;i++)
        tree[node][i]=tree[node*2][i]+tree[node*2+1][(i+tree[node*2][i])%60];
}
void build(int node,int l,int r)
{
    //cout<<node<<" "<<l<<" "<<r<<endl;
    if(l==r)
    {
        make_node(node,l);
        return;
    }
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);
    combine(node);
}
void update(int node,int l,int r,int pos)
{
    if(l==r)
    {
        make_node(node,l);
        return;
    }
    int av=(l+r)/2;
    if(pos<=av)update(node*2,l,av,pos);
    else update(node*2+1,av+1,r,pos);
    combine(node);
}
void go(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)
    {
        /*
        cout<<node<<" "<<l<<" "<<r<<" "<<tree[node][t]<<endl;
        system("pause");
        */
        t=t+tree[node][t%60];
        return;
    }
    int av=(l+r)/2;
    if(lq<=av)go(node*2,l,av,lq,min(rq,av));
    if(av<rq)go(node*2+1,av+1,r,max(av+1,lq),rq);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n;
for(int i=1;i<=n;i++)cin>>arr[i];
build(1,1,n);
int q;
cin>>q;
char type;
int x,y;
for(int i=1;i<=q;i++)
{
    cin>>type>>x>>y;
    if(type=='C')
    {
        arr[x]=y;
        update(1,1,n,x);
    }
    else
    {
        t=0;
        go(1,1,n,x,y-1);
        cout<<t<<"\n";
    }
}
cout<<endl;
return 0;
}
//O(n*log(n)*60)