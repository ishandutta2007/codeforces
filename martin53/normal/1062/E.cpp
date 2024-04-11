#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,q;
vector<int> adj[nmax];
int index[nmax],id=0;
int inv[nmax];
void dfs(int node,int parent)
{
    id++;
    index[node]=id;
    inv[id]=node;
    for(auto k:adj[node])
        if(k!=parent)
        dfs(k,node);
}
int depth[nmax];
int up[nmax][20];
void dfs_tree(int node,int parent,int h)
{
    depth[node]=h;
    up[node][0]=parent;
    for(auto k:adj[node])
        if(k!=parent)
        dfs_tree(k,node,h+1);
}
int lca(int a,int b)
{
    if(depth[a]<depth[b])swap(a,b);
    for(int i=19;i>=0;i--)
        if(depth[a]-(1<<i)>=depth[b])a=up[a][i];
    if(a==b)return a;
    for(int i=19;i>=0;i--)
        if(up[a][i]!=up[b][i])a=up[a][i],b=up[b][i];
    return up[a][0];
}
struct info
{
    int mx,second_mx;
    int mn,second_mn;
};
void print(info a)
{
    cout<<a.mn<<" "<<a.second_mn<<" "<<a.second_mx<<" "<<a.mx<<endl;
}
bool cmp(int a,int b)
{
    return index[a]>index[b];
}
bool cmp2(int a,int b)
{
    return index[a]<index[b];
}
info my_merge(info a,info b)
{
    info ret;ret.mn=0;ret.second_mn=0;ret.second_mx=0;ret.mx=0;
    int arr[4],id=0;
    if(a.mx)arr[id++]=a.mx;
    if(a.second_mx)arr[id++]=a.second_mx;
    if(b.mx)arr[id++]=b.mx;
    if(b.second_mx)arr[id++]=b.second_mx;
    sort(arr,arr+id,cmp);
    if(id>=1)ret.mx=arr[0];
    if(id>=2)ret.second_mx=arr[1];
    //cout<<"id= "<<id<<endl;

    id=0;
    if(a.mn)arr[id++]=a.mn;
    if(a.second_mn)arr[id++]=a.second_mn;
    if(b.mx)arr[id++]=b.mn;
    if(b.second_mx)arr[id++]=b.second_mn;
    sort(arr,arr+id,cmp2);
    if(id>=1)ret.mn=arr[0];
    if(id>=2)ret.second_mn=arr[1];
    //cout<<"id= "<<id<<endl;

    return ret;
}
info tree[4*nmax];
void build(int node,int l,int r)
{
    //cout<<node<<" "<<l<<" "<<r<<endl;
    if(l==r)
    {
        tree[node].mx=l;
        tree[node].mn=r;
        return;
    }
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);
    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
    //cout<<l<<" "<<r<<" -> ";print(tree[node]);
}
info query(int node,int l,int r,int lq,int rq)
{
    //cout<<node<<" "<<l<<" "<<r<<" "<<lq<<" "<<rq<<endl;
    if(l==lq&&r==rq)return tree[node];
    int av=(l+r)/2;
    info ret;ret.mn=0;ret.second_mn=0;ret.mx=0;ret.second_mx=0;
    if(lq<=av)ret=my_merge(ret,query(node*2,l,av,lq,min(av,rq)));
    if(av<rq)ret=my_merge(ret,query(node*2+1,av+1,r,max(av+1,lq),rq));
    //cout<<"returning "<<lq<<" "<<rq<<" -> ";print(ret);
    return ret;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n>>q;
int l,r;
for(int i=2;i<=n;i++)
{
    cin>>l;
    adj[i].push_back(l);
    adj[l].push_back(i);
}
dfs(1,1);
dfs_tree(1,1,0);
for(int j=1;j<20;j++)
    for(int i=1;i<=n;i++)
    up[i][j]=up[up[i][j-1]][j-1];
build(1,1,n);
for(int i=1;i<=q;i++)
{
    cin>>l>>r;
    info now=query(1,1,n,l,r);
    //cout<<"query ";print(now);
    int p=lca(now.second_mn,now.mx);
    int q=lca(now.mn,now.second_mx);
    //cout<<"ans= ";
    if(depth[p]<depth[q])cout<<now.mx<<" "<<depth[q]<<'\n';
    else cout<<now.mn<<" "<<depth[p]<<'\n';
    //system("pause");
}
return 0;
}