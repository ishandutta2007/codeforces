#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
struct robot
{
    int x,r,iq;
};
int x[nmax];
bool cmp(robot a,robot b)
{
    if(a.iq!=b.iq)return a.iq<b.iq;
    return a.x<b.x;
}
struct query
{
    int left_border,right_border;
    int border;
};
query make_query(int left_border,int right_border,int border)
{
    query q;
    q.left_border=left_border;
    q.right_border=right_border;
    q.border=border;
    return q;
}
int n,k;
robot inp[nmax];
vector<int> tree_right[4*nmax];
void build_tree_right(int node,int l,int r,int lq,int rq)
{
    if(l==r)
    {
        tree_right[node].push_back(inp[l].x+inp[l].r);
        return;
    }
    int av=(l+r)/2;
    if(lq<=av)build_tree_right(node*2,l,av,lq,min(av,rq));
    if(av<rq)build_tree_right(node*2+1,av+1,r,max(av+1,lq),rq);
    if(l==lq&&r==rq)
    {
        tree_right[node]=tree_right[node*2];
        for(auto k:tree_right[node*2+1])
            tree_right[node].push_back(k);
        sort(tree_right[node].begin(),tree_right[node].end());
    }
}
int query_right(int node,int l,int r,int lq,int rq,int lower)
{
    if(l==lq&&r==rq)
    {
        int p=lower_bound(tree_right[node].begin(),tree_right[node].end(),lower)-tree_right[node].begin();
        return tree_right[node].size()-p;
    }
    int av=(l+r)/2,ret=0;
    if(lq<=av)ret=ret+query_right(node*2,l,av,lq,min(av,rq),lower);
    if(av<rq)ret=ret+query_right(node*2+1,av+1,r,max(av+1,lq),rq,lower);
    return ret;
}








vector<int> tree_left[4*nmax];
void build_tree_left(int node,int l,int r,int lq,int rq)
{
    if(l==r)
    {
        tree_left[node].push_back(inp[l].x-inp[l].r);
        return;
    }
    int av=(l+r)/2;
    if(lq<=av)build_tree_left(node*2,l,av,lq,min(av,rq));
    if(av<rq)build_tree_left(node*2+1,av+1,r,max(av+1,lq),rq);
    if(l==lq&&r==rq)
    {
        tree_left[node]=tree_left[node*2];
        for(auto k:tree_left[node*2+1])
            tree_left[node].push_back(k);
        sort(tree_left[node].begin(),tree_left[node].end());
    }
}
int query_left(int node,int l,int r,int lq,int rq,int upper)
{
    if(l==lq&&r==rq)
    {
        int p=upper_bound(tree_left[node].begin(),tree_left[node].end(),upper)-tree_left[node].begin();
        //cout<<"query: ";for(auto k:tree_left[node])cout<<k<<" ";cout<<" with upper= "<<upper<<" and p= "<<p<<endl;
        return p;
    }
    int av=(l+r)/2,ret=0;
    if(lq<=av)ret=ret+query_left(node*2,l,av,lq,min(av,rq),upper);
    if(av<rq)ret=ret+query_left(node*2+1,av+1,r,max(av+1,lq),rq,upper);
    return ret;
}







vector<query> le,ri;

map<int,int> beg,en;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n>>k;
for(int i=1;i<=n;i++)cin>>inp[i].x>>inp[i].r>>inp[i].iq;
sort(inp+1,inp+n+1,cmp);
for(int i=1;i<=n;i++)x[i]=inp[i].x;
for(int i=1;i<=n;i++)
{
    if(beg.count(inp[i].iq)==0)beg[inp[i].iq]=i;
    en[inp[i].iq]=i;
}

for(int i=1;i<=n;i++)
{
    for(int j=-k;j<=0;j++)
    {
        int now=inp[i].iq+j;
        if(beg.count(now))
        {
            //cout<<i<<" "<<now<<endl;
            if(now!=inp[i].iq)
            {
                int p=lower_bound(x+beg[now],x+en[now]+1,inp[i].x-inp[i].r)-x;
                int q=upper_bound(x+beg[now],x+en[now]+1,inp[i].x-1)-x;q--;
                if(p<=q)ri.push_back(make_query(p,q,inp[i].x));

                p=lower_bound(x+beg[now],x+en[now]+1,inp[i].x)-x;
                q=upper_bound(x+beg[now],x+en[now]+1,inp[i].x+inp[i].r)-x;q--;
                if(p<=q)le.push_back(make_query(p,q,inp[i].x));
            }
            else//now=inp[i].iq
            {
                int p=lower_bound(x+beg[now],x+en[now]+1,inp[i].x-inp[i].r)-x;
                int q=i;q--;
                //cout<<"equal "<<p<<" "<<q<<endl;
                if(p<=q)ri.push_back(make_query(p,q,inp[i].x));
            }
            //cout<<"After: "<<le.size()<<" "<<ri.size()<<endl;
        }
    }

}
long long ans=0;
for(auto k:beg)
    build_tree_right(1,1,n,k.second,en[k.first]);
for(auto k:ri)
    ans=ans+query_right(1,1,n,k.left_border,k.right_border,k.border);


for(auto k:beg)
    build_tree_left(1,1,n,k.second,en[k.first]);
for(auto k:le)
    ans=ans+query_left(1,1,n,k.left_border,k.right_border,k.border);

cout<<ans<<endl;
return 0;
}