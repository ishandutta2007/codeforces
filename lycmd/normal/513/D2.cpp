#include<bits/stdc++.h>
using namespace std;
int const N=2333333,INF=0x3f3f3f3f;
int n,q,cur=1,fail,ls[N],rs[N],lmn[N],rmn[N],lmx[N],rmx[N];
inline void dfs(int x,int r){
	if(lmx[x])
		dfs(ls[x]=++cur,lmx[x]);
	fail|=cur>=rmn[x];
	if(rmx[x]||cur<r)
		dfs(rs[x]=++cur,max(rmx[x],r)),fail|=cur<r;
}
inline void print(int x){
	if(ls[x])print(ls[x]);
	cout<<x<<" ";
	if(rs[x])print(rs[x]);
}
int main(){
	ios::sync_with_stdio(0);
	memset(lmn,INF,sizeof lmn);
	memset(rmn,INF,sizeof rmn);
	cin>>n>>q;
	while(q--){
		int x,y;string op;
		cin>>x>>y>>op;
		fail|=x>=y;
		if(op=="LEFT")
			lmn[x]=min(lmn[x],y),lmx[x]=max(lmx[x],y);
		else
			rmn[x]=min(rmn[x],y),rmx[x]=max(rmx[x],y);
	}
	for(int i=1;i<=n;i++)
		fail|=lmx[i]>rmn[i];
	dfs(1,n);
	if(fail)cout<<"IMPOSSIBLE\n",exit(0);
	print(1);
}