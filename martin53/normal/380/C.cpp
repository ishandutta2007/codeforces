#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
struct vertex
{
int open,close,ans;
};
string s;
vertex tree[4*nmax];
vertex merge_vertex(vertex l,vertex r)
{
int x=min(l.open,r.close);
l.open=l.open-x;
r.close=r.close-x;

vertex ans;
ans.open=l.open+r.open;
ans.close=l.close+r.close;
ans.ans=l.ans+r.ans+2*x;
return ans;
}
void build(int node,int l,int r)
{
if(l==r)
{
tree[node].open=(s[l-1]=='(');
tree[node].close=(s[l-1]==')');
tree[node].ans=0;
return;
}
int av=(l+r)/2;
build(node*2,l,av);
build(node*2+1,av+1,r);
tree[node]=merge_vertex(tree[node*2],tree[node*2+1]);
}
vertex query(int node,int l,int r,int lq,int rq)
{
if(l==lq&&r==rq)return tree[node];
int av=(l+r)/2;
vertex ans;
ans.open=0;
ans.close=0;
ans.ans=0;
if(lq<=av)ans=merge_vertex(ans,query(node*2,l,av,lq,min(av,rq)));
if(av<rq)ans=merge_vertex(ans,query(node*2+1,av+1,r,max(av+1,lq),rq));
return ans;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>s;
int n=s.size();
build(1,1,n);
int m;
cin>>m;
int l,r;
for(int i=1;i<=m;i++)
{
cin>>l>>r;
vertex now=query(1,1,n,l,r);
cout<<now.ans<<endl;
}
return 0;
}