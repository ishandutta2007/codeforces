#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,m;
struct tree
{
int x,h,l,r;
};
tree inp[nmax];
struct mushroom
{
    int x,p;
};
mushroom mush[nmax];
double tree[4*nmax];
int values[nmax];
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=mush[l].p;
        return;
    }
    tree[node]=1;
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);
}
void update(int node,int l,int r,int lq,int rq,double prob)
{
    if(l==lq&&r==rq)
    {
        tree[node]=tree[node]*prob;
        return;
    }
    int av=(l+r)/2;
    if(lq<=av)update(node*2,l,av,lq,min(av,rq),prob);
    if(av<rq)update(node*2+1,av+1,r,max(av+1,lq),rq,prob);
}
double outp=0;

void go(int node,int l,int r)
{
    if(l==r)
    {
        outp=outp+tree[node];
        return;
    }
    int av=(l+r)/2;
    tree[node*2]=tree[node*2]*tree[node];
    tree[node*2+1]=tree[node*2+1]*tree[node];
    tree[node]=1;
    go(node*2,l,av);
    go(node*2+1,av+1,r);
}
bool cmp(mushroom a,mushroom b)
{
    return a.x<b.x;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();

cin>>n>>m;
for(int i=1;i<=n;i++)
{
    cin>>inp[i].x>>inp[i].h>>inp[i].l>>inp[i].r;
}

for(int i=1;i<=m;i++)
{
    cin>>mush[i].x>>mush[i].p;
}

sort(mush+1,mush+m+1,cmp);

for(int i=1;i<=m;i++)values[i]=mush[i].x;

build(1,1,m);

for(int i=1;i<=n;i++)
{
    //go right
    int p=upper_bound(values+1,values+m+1,inp[i].x)-values;
    int q=upper_bound(values+1,values+m+1,inp[i].x+inp[i].h)-values;
    q--;
    //cout<<p<<" "<<q<<endl;
    if(p<=q)update(1,1,m,p,q,1-inp[i].r/100.0);
    //go left
    int s=lower_bound(values+1,values+m+1,inp[i].x-inp[i].h)-values;
    int t=lower_bound(values+1,values+m+1,inp[i].x)-values;
    t--;
    //cout<<s<<" "<<t<<endl;
    if(s<=t)update(1,1,m,s,t,1-inp[i].l/100.0);
    //cout<<p<<" "<<q<<" "<<s<<" "<<t<<endl;
}
go(1,1,m);
printf("%.18f\n",outp);
return 0;
}