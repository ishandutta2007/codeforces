// LUOGU_RID: 90282710
#include<bits/stdc++.h>
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=100010,T=N<<3;
int n,m,cur,l[N],r[N],tr[T],fl[T],ans[N];
vector<int>e[N],g[N];
void update(int x){
	tr[x]=tr[ls(x)]+tr[rs(x)];
}
void modify(int x,int l,int r,int ql,int qr,int k){
	if(ql<=l&&r<=qr)
		return (fl[x]+=k)?void(tr[x]=r-l+1):update(x);
	int mid=(l+r)>>1;
	if(ql<=mid)
		modify(ls(x),l,mid,ql,qr,k);
	if(qr>mid)
		modify(rs(x),mid+1,r,ql,qr,k);
	if(!fl[x])
		update(x);
}
void dfs1(int x,int fa){
	l[x]=++cur;
	for(int y:e[x])
		if(y^fa)dfs1(y,x);
	r[x]=cur;
}
void dfs2(int x,int fa){
	for(int y:g[x])
		modify(1,1,n,l[x],r[x],1),modify(1,1,n,l[y],r[y],1);
	ans[x]=max(tr[1]-1,0);
	for(int y:e[x])
		if(y^fa)dfs2(y,x);
	for(int y:g[x])
		modify(1,1,n,l[x],r[x],-1),modify(1,1,n,l[y],r[y],-1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1,x,y;i<n;i++)
		cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
	for(int x,y;m--;)
		cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
	dfs1(1,0),dfs2(1,0);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<"\n";
}