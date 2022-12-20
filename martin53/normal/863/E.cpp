#include<bits/stdc++.h>
using namespace std;
const int nmax=4e5+42;
int n;
pair<int,int> inp[nmax];
int tree[4*2*nmax];
int p=0;
void compress()
{
    set<int> seen={};
    for(int i=1;i<=n;i++)
    {
        seen.insert(inp[i].first);
        seen.insert(inp[i].second);
        seen.insert(inp[i].first-1);
        seen.insert(inp[i].second+1);
    }
    map<int,int> c={};
    for(auto k:seen)
    {
        c[k]=++p;
    }
    for(int i=1;i<=n;i++)
    {
        inp[i].first=c[inp[i].first];
        inp[i].second=c[inp[i].second];
    }
    //for(int i=1;i<=n;i++)cout<<inp[i].first<<" "<<inp[i].second<<endl;
}
void update_node(int node)
{
    tree[node*2]+=tree[node];
    tree[node*2+1]+=tree[node];
    tree[node]=0;
}
void update(int node,int l,int r,int lq,int rq)
{
    //cout<<node<<" "<<l<<" "<<r<<" "<<lq<<" "<<rq<<endl;
    if(l==lq&&r==rq)
    {
        tree[node]++;
        return;
    }
    update_node(node);
    int av=(l+r)/2;
    if(lq<=av)update(node*2,l,av,lq,min(av,rq));
    if(av<rq)update(node*2+1,av+1,r,max(av+1,lq),rq);
}
int min_tree[4*2*nmax];
int val[2*nmax];

void build(int node,int l,int r)
{
    if(l==r)
    {
        min_tree[node]=val[l];
        return;
    }
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);
    min_tree[node]=min(min_tree[node*2],min_tree[node*2+1]);
}
void go_down(int node,int l,int r)
{
    if(l==r)
    {
        val[l]=tree[node];
        return;
    }
    update_node(node);
    int av=(l+r)/2;
    go_down(node*2,l,av);
    go_down(node*2+1,av+1,r);
}
int query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return min_tree[node];
    int av=(l+r)/2,mini=1e9;
    if(lq<=av)mini=min(mini,query(node*2,l,av,lq,min(av,rq)));
    if(av<rq)mini=min(mini,query(node*2+1,av+1,r,max(av+1,lq),rq));
    return mini;
}
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)
    scanf("%i%i",&inp[i].first,&inp[i].second);
compress();
for(int i=1;i<=n;i++)
    {
    update(1,1,p,inp[i].first,inp[i].second);
    }
go_down(1,1,p);
build(1,1,p);
for(int i=1;i<=n;i++)
{
    if(query(1,1,p,inp[i].first,inp[i].second)>=2)
    {
        printf("%i\n",i);
        return 0;
    }
}
printf("-1\n");
return 0;
}