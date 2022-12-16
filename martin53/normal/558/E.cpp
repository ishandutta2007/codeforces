#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,q;
char inp[nmax];
int tree[26][4*nmax];
void build(int letter,int node,int l,int r)
{
if(l==r)
{
tree[letter][node]=(inp[l]=='a'+letter);
return;
}
int av=(l+r)/2;
build(letter,node*2,l,av);
build(letter,node*2+1,av+1,r);
tree[letter][node]=tree[letter][node*2]+tree[letter][node*2+1];
}
int lazy[26][4*nmax];
int update_node(int letter,int node)
{
    if(lazy[letter][node])
    {
    lazy[letter][node*2]=lazy[letter][node];
    lazy[letter][node*2+1]=lazy[letter][node];
    lazy[letter][node]=0;
    }
}
int info(int letter,int node,int l,int r)
{
if(lazy[letter][node]==0)return tree[letter][node];
if(lazy[letter][node]==1)return r-l+1;
return 0;
}
int query(int letter,int node,int l,int r,int lq,int rq)
{
if(l==lq&&r==rq)return info(letter,node,l,r);
update_node(letter,node);
int av=(l+r)/2,ans=0;
if(lq<=av)ans=ans+query(letter,node*2,l,av,lq,min(av,rq));
if(av<rq)ans=ans+query(letter,node*2+1,av+1,r,max(av+1,lq),rq);
return ans;
}

int my_merge(int letter,int node,int l,int r)
{
    int av=(l+r)/2,ans=0;
    if(lazy[letter][node*2]==0)ans=ans+tree[letter][node*2];
    if(lazy[letter][node*2]==1)ans=ans+(av-l+1);

    if(lazy[letter][node*2+1]==0)ans=ans+tree[letter][node*2+1];
    if(lazy[letter][node*2+1]==1)ans=ans+(r-av-1+1);
    return ans;
}
void update(int letter,int node,int l,int r,int lq,int rq,int now)
{
if(l==lq&&r==rq)
{
lazy[letter][node]=now;
return;
}
update_node(letter,node);
int av=(l+r)/2;
if(lq<=av)update(letter,node*2,l,av,lq,min(av,rq),now);
if(av<rq)update(letter,node*2+1,av+1,r,max(av+1,lq),rq,now);
tree[letter][node]=my_merge(letter,node,l,r);
}
void go_down(int letter,int node,int l,int r)
{
if(lazy[letter][node]==-1)return;
if(lazy[letter][node]==1)
{
    for(int j=l;j<=r;j++)
        inp[j]=char(letter+'a');
    return;
}
if(l==r)
{
if(tree[letter][node])inp[l]=char(letter+'a');
return;
}
update_node(letter,node);
int av=(l+r)/2;
go_down(letter,node*2,l,av);
go_down(letter,node*2+1,av+1,r);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();

cin>>n>>q;
for(int i=1;i<=n;i++)cin>>inp[i];
for(int i=0;i<26;i++)
    build(i,1,1,n);
int l,r,k;
for(int i=1;i<=q;i++)
{
cin>>l>>r>>k;
    if(k==1)
    {
        int pos_l=l;
        for(int j=0;j<26;j++)
        {
            int sum=query(j,1,1,n,l,r);
            update(j,1,1,n,l,r,-1);
            if(sum)update(j,1,1,n,pos_l,pos_l+sum-1,1);
            pos_l=pos_l+sum;
        }
    }
    else
    {
        int pos_l=l;
        for(int j=25;j>=0;j--)
        {
            int sum=query(j,1,1,n,l,r);
            //cout<<j<<" -> "<<sum<<endl;
            update(j,1,1,n,l,r,-1);
            if(sum)update(j,1,1,n,pos_l,pos_l+sum-1,1);
            pos_l=pos_l+sum;
        }
    }
/*
for(int j=0;j<26;j++)
    go_down(j,1,1,n);

for(int j=1;j<=n;j++)cout<<inp[j];cout<<endl;
*/
}
for(int j=0;j<26;j++)
    go_down(j,1,1,n);

for(int i=1;i<=n;i++)cout<<inp[i];cout<<endl;
return 0;
}