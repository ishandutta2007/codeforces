#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(i) for(int i=0;i<n;i++)
const int N=200200;
LL ans[N]={0},sz[N]={0},tr[N]={0},fa[N]={0};
LL cc[2]={0};
bool vis[N]={false};
vector<int> es[N];
inline LL sqr(LL x){
	return x*x;
}
LL dfs(int x,int c){
	cc[c]++;
	vis[x]=true;
	int l=es[x].size();
	sz[x]=1;
	ans[x]=0;
	tr[x]=0;
	for(int i=0;i<l;i++){
		int nxt=es[x][i];
		if(!vis[nxt]){
			fa[nxt]=x;
			dfs(nxt,c^1);
			sz[x]+=sz[nxt];
			ans[x]+=ans[nxt];
			tr[x]+=tr[nxt]+sz[nxt];
		}
	}
	// LL tmp=sqr(tr[x]);
	for(int i=0;i<l;i++){
		int nxt=es[x][i];
		if(fa[x]!=nxt){
			// tmp-=sqr(tr[nxt]+sz[nxt]);
			ans[x]+=(sz[x]-sz[nxt])*(tr[nxt]+sz[nxt]);
			// ans[x]+=tr[nxt]+sz[nxt];
		}
	}
	// tmp/=2;
	// ans[x]+=tmp;
}
void ae(int u,int v){
	es[u].push_back(v);
	es[v].push_back(u);
}
int main(){
	int n;
	cin>>n;
	F(i)if(i){
		int u,v;
		cin>>u>>v;
		ae(u,v);
	}
	fa[1]=-1;
	dfs(1,0);
	LL k=cc[0]*cc[1];
	LL res=(ans[1]+k)/2;
	// for(int i=1;i<=n;i++){
	// 	cout<<i<<":"<<tr[i]<<" "<<ans[i]<<endl;
	// }
	cout<<res<<endl;
	return 0;
}