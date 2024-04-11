#include<bits/stdc++.h>
using namespace std;
const int nmax=1<<24;

int tree_l[nmax];
short tree_type[nmax];
int tree_sum[nmax];

int n,q;
int pos=1;
int type;
void update_node(int &node)
{
    assert(pos<nmax);
    if(tree_l[node]==-1)
    {
        tree_l[node]=++pos;
        ++pos;
    }
    tree_type[tree_l[node]]=tree_type[node];

    tree_type[tree_l[node]+1]=tree_type[node];

    tree_type[node]=0;
}
int take(int node,int d)
{
    if(node==-1)return 0;
    if(tree_type[node]==0)return tree_sum[node];
    if(tree_type[node]==1)return d;
    return 0;
}
void update(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)
    {
        tree_type[node]=type;
        if(type==2)tree_sum[node]=0;
        else tree_sum[node]=r-l+1;
        return;
    }
    if(tree_type[node])update_node(node);
    int av=(l+r)/2;
    if(lq<=av)
    {
        update(tree_l[node],l,av,lq,min(av,rq));
    }
    if(av<rq)
    {
        update(tree_l[node]+1,av+1,r,max(av+1,lq),rq);
    }
    tree_sum[node]=take(tree_l[node],av-l+1)+take(tree_l[node]+1,r-av);
    //cout<<node<<" "<<l<<" "<<r<<" -> "<<tree[node].sum<<" "<<tree[tree[node].l].type<<" "<<tree[tree[node].r].type<<endl;
}
int main()
{
scanf("%i%i",&n,&q);
memset(tree_l,-1,sizeof(tree_l));
for(int i=0;i<nmax;i++)
    tree_type[i]=2;
//memset(tree_type,2,sizeof(tree_type));
int l,r;
for(int i=1;i<=q;i++)
{
    scanf("%i%i%i",&l,&r,&type);
    update(1,1,n,l,r);
    printf("%i\n",n-tree_sum[1]);
}
return 0;
}