#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> edge;
int const N=233333;
int n,m,k,ans,sz[N],mx[N],vis[N],cnt[N],tr[N];
vector<edge>e[N],dep;
void add(int x,int y){
	for(x+=2;x<N;x+=x&-x)tr[x]+=y;
}
int ask(int x){
	int res=0;
	for(x+=2;x;x&=x-1)res+=tr[x];
	return res;
}
int getcore(int x,int fa,int tot){
	mx[x]=0,sz[x]=1;
	int r=0;
	for(auto i:e[x]){
		int y=i.first;
		if(y==fa||vis[y])continue;
		int p=getcore(y,x,tot);
		if(!r||mx[r]>mx[p])r=p;
		sz[x]+=sz[y],mx[x]=max(mx[x],sz[y]);
	}
	mx[x]=max(mx[x],tot-sz[x]);
	if(!r||mx[r]>mx[x])r=x;
	return r;
}
void dfs(int x,int fa,int d1,int d2){
	if(d1>m||d2>k)return;
	dep.push_back({d2,d1});
	for(auto i:e[x]){
		int y=i.first,w=i.second;
		if(y==fa||vis[y])continue;
		dfs(y,x,d1+1,d2+w);
	}
}
int calc(int x,int d1,int d2){
	dep.clear();
	int res=0,l,r;
	dfs(x,0,d1,d2);
	sort(dep.begin(),dep.end());
	if(dep.empty())return 0;
	for(auto i:dep)add(i.second,1);
	for(l=0,r=dep.size()-1;l<r;){
		if(dep[l].first+dep[r].first<=k)
			add(dep[l].second,-1),res+=ask(m-dep[l++].second);
		else
			add(dep[r--].second,-1);
	}
	add(dep[l].second,-1);
	return res;
}
void solve(int x){
	vis[x]=1,ans+=calc(x,0,0);
	for(auto i:e[x]){
		int y=i.first,k=i.second;
		if(vis[y])continue;
		ans-=calc(y,1,k);
		solve(getcore(y,x,sz[y]));
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++){
		int b,c;cin>>b>>c;
		e[i].push_back({b,c});
		e[b].push_back({i,c});
	}
	solve(getcore(1,0,n));
	cout<<ans<<"\n";
}