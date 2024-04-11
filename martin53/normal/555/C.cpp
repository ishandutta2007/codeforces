#include<bits/stdc++.h>
using namespace std;
const int qmax=2e5+42;
int n,q;
struct query
{
    int x,y;
    char type;
};
query inp[qmax];
int u_n=0,u_values[qmax],u_tree[4*qmax];
int l_n=0,l_values[qmax],l_tree[4*qmax];
set<int> u_,l_;
int ROT(int q)
{
return n+1-q;
}
int where_l(int val,bool up)
{
    if(up==0)
    {
        int p=upper_bound(l_values+1,l_values+1+l_n,val)-l_values;
        return p-1;
    }
        int p=lower_bound(l_values+1,l_values+1+l_n,val)-l_values;
        return p;
}
int where_u(int val,bool up)
{
    if(up==0)
    {
        int p=upper_bound(u_values+1,u_values+1+u_n,val)-u_values;
        return p-1;
    }
        int p=lower_bound(u_values+1,u_values+1+u_n,val)-u_values;
        return p;
}
int query_u(int node,int l,int r,int pos)
{
    if(l==r)return u_tree[node];
    int av=(l+r)/2,ans=u_tree[node];
    if(pos<=av)ans=max(ans,query_u(node*2,l,av,pos));
    else ans=max(ans,query_u(node*2+1,av+1,r,pos));
    return ans;
}
int query_l(int node,int l,int r,int pos)
{
    if(l==r)return l_tree[node];
    int av=(l+r)/2,ans=l_tree[node];
    if(pos<=av)ans=max(ans,query_l(node*2,l,av,pos));
    else ans=max(ans,query_l(node*2+1,av+1,r,pos));
    return ans;
}
void u_update(int node)
{
    u_tree[node*2]=max(u_tree[node*2],u_tree[node]);
    u_tree[node*2+1]=max(u_tree[node*2+1],u_tree[node]);
    u_tree[node]=0;
}
void update_u(int node,int l,int r,int lq,int rq,int val)
{
    //cout<<node<<" "<<l<<" "<<r<<" "<<lq<<" "<<rq<<" "<<val<<endl;
    if(lq>rq)return;
    if(l==lq&&r==rq)
    {
        u_tree[node]=max(u_tree[node],val);
        return;
    }
    u_update(node);
    int av=(l+r)/2;
    if(lq<=av)update_u(node*2,l,av,lq,min(av,rq),val);
    if(av<rq)update_u(node*2+1,av+1,r,max(av+1,lq),rq,val);
}

void l_update(int node)
{
    l_tree[node*2]=max(l_tree[node*2],l_tree[node]);
    l_tree[node*2+1]=max(l_tree[node*2+1],l_tree[node]);
    l_tree[node]=0;
}
void update_l(int node,int l,int r,int lq,int rq,int val)
{
    //cout<<node<<" "<<l<<" "<<r<<" "<<lq<<" "<<rq<<" "<<val<<endl;
    if(lq>rq)return;
    if(l==lq&&r==rq)
    {
        l_tree[node]=max(l_tree[node],val);
        return;
    }
    l_update(node);
    int av=(l+r)/2;
    if(lq<=av)update_l(node*2,l,av,lq,min(av,rq),val);
    if(av<rq)update_l(node*2+1,av+1,r,max(av+1,lq),rq,val);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>n>>q;
for(int i=1;i<=q;i++)
{
cin>>inp[i].x>>inp[i].y>>inp[i].type;
swap(inp[i].x,inp[i].y);
}

for(int i=1;i<=q;i++)
    {
    u_.insert(inp[i].x);
    l_.insert(inp[i].y);
    }
for(auto k:u_)
{
    u_n++;
    u_values[u_n]=k;
}

for(auto k:l_)
{
    l_n++;
    l_values[l_n]=k;
}

for(int i=1;i<=q;i++)
{
    if(inp[i].type=='U')
    {
        int ans=inp[i].x-query_u(1,1,u_n,where_u(inp[i].x,0));
        cout<<ans<<endl;
        if(ans)
        {
        if(l_n)update_l(1,1,l_n,where_l(ROT(inp[i].x),1),where_l(ROT(inp[i].x-(ans-1)),0),inp[i].y);
        if(u_n)update_u(1,1,u_n,where_u(inp[i].x,0),where_u(inp[i].x,0),inp[i].x);
        }
    }
    else
    {
        int ans=inp[i].y-query_l(1,1,l_n,where_l(inp[i].y,0));
        cout<<ans<<endl;
        if(ans)
        {
        if(u_n)update_u(1,1,u_n,where_u(ROT(inp[i].y),1),where_u(ROT(inp[i].y-(ans-1)),0),inp[i].x);
        if(l_n)update_l(1,1,l_n,where_l(inp[i].y,0),where_l(inp[i].y,0),inp[i].y);
        }
    }
}
return 0;
}