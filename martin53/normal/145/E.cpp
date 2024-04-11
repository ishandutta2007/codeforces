#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;

struct node
{
int four,seven;
int best_inc;
int best_decr;
bool rev;
};

node tree[4*nmax];
int n;
char inp[nmax];

node actual(node now)
{
    if(now.rev==1)
    {
        swap(now.four,now.seven);
        swap(now.best_decr,now.best_inc);
    }
    return now;
}
node my_merge(node l,node r,bool rev)
{
    l=actual(l);
    r=actual(r);
    node ret;
    ret.rev=rev;
    ret.four=l.four+r.four;
    ret.seven=l.seven+r.seven;

    ret.best_inc=l.best_inc+r.seven;
    ret.best_inc=max(ret.best_inc,l.four+r.best_inc);

    ret.best_decr=l.best_decr+r.four;
    ret.best_decr=max(ret.best_decr,l.seven+r.best_decr);
    return ret;
}
void build(int node,int l,int r)
{
    if(l==r)
    {
        if(inp[l]=='4')tree[node].four++;
        else tree[node].seven++;
        tree[node].best_inc=1;
        tree[node].best_decr=1;
        return;
    }
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);
    tree[node]=my_merge(tree[node*2],tree[node*2+1],0);
}
void update(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)
    {
        tree[node].rev=!tree[node].rev;
        return;
    }
    tree[node*2].rev=tree[node*2].rev^tree[node].rev;
    tree[node*2+1].rev=tree[node*2+1].rev^tree[node].rev;
    tree[node].rev=0;
    int av=(l+r)/2;
    if(lq<=av)update(node*2,l,av,lq,min(rq,av));
    if(av<rq)update(node*2+1,av+1,r,max(lq,av+1),rq);
    tree[node]=my_merge(tree[node*2],tree[node*2+1],tree[node].rev);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
int m;
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>inp[i];
build(1,1,n);
string type;
int l,r;
for(int i=1;i<=m;i++)
{
    cin>>type;
    if(type=="count")
    {
        cout<<actual(tree[1]).best_inc<<endl;
    }
    else
    {
        cin>>l>>r;
        update(1,1,n,l,r);
    }
}
return 0;
}