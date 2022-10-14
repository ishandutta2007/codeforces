#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010,T=N<<4,INF=0x3f3f3f3f3f3f3f3fll;
int n,ans,tot=1,a[N],trie[T][2];
inline int diff(int x,int y,int d){
	int xls=trie[x][0],yls=trie[y][0],xrs=trie[x][1],yrs=trie[y][1],res=INF;
	if(d<0)return 0;
	if(xls&&yls)res=min(res,diff(xls,yls,d-1));
	if(xrs&&yrs)res=min(res,diff(xrs,yrs,d-1));
	if(res<INF)return res;
	if(xls&&yrs)res=min(res,diff(xls,yrs,d-1)+(1ll<<d));
	if(xrs&&yls)res=min(res,diff(xrs,yls,d-1)+(1ll<<d));
	return res;
}
inline void dfs(int x,int d){
	if(d<0)return;
	int ls=trie[x][0],rs=trie[x][1];
	if(ls&&rs)ans+=diff(ls,rs,d-1)+(1ll<<d);
	if(ls)dfs(ls,d-1);
	if(rs)dfs(rs,d-1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int p=1;
		for(int j=30;j>=0;j--){
			int t=(a[i]>>j)&1;
			if(!trie[p][t])trie[p][t]=++tot;
			p=trie[p][t];
		}
	}
	dfs(1,30);
	cout<<ans<<"\n";
}