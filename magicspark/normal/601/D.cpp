//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
string str;
int v[300005],ans[300005];
vector<int>g[300005];
int nxt[300005][29],sz[300005];
pair<int,int>_ans(-inf,-inf);
void upd(int x){
	if(x>_ans.first){
		_ans.first=x;
		_ans.second=1;
	}else if(x==_ans.first){
		_ans.second++;
	}
}
void merge(int x,int y){
	for(int i=0;i<26;i++){
		if(!nxt[y][i])continue;
		if(!nxt[x][i]){
			sz[x]+=sz[nxt[y][i]];
			nxt[x][i]=nxt[y][i];
		}else{
			sz[x]-=sz[nxt[x][i]];
			merge(nxt[x][i],nxt[y][i]);
			sz[x]+=sz[nxt[x][i]];
		}
	}
}
void dfs(int x,int par=0){
	bool Azis=false;
	sz[x]=1;
	for(auto to:g[x])if(to!=par){
		dfs(to,x);
		Azis=true;
	}
	if(!Azis)ans[x]=v[x]+1;
	if(!Azis)return;
	int best[27]={},pos[27]={};
	for(auto to:g[x])if(to!=par){
		if(sz[to]>best[str[to]]){
			best[str[to]]=sz[to];
			pos[str[to]]=to;
		}
	}
	for(int i=0;i<26;i++)if(pos[i])nxt[x][i]=pos[i],sz[x]+=sz[pos[i]];
	for(auto to:g[x]){
		if(pos[str[to]]==to){
			continue;
		}
		sz[x]-=sz[nxt[x][str[to]]];
		merge(nxt[x][str[to]],to);
		sz[x]+=sz[nxt[x][str[to]]];	
	}
//	cerr<<x<<" "<<sz[x]<<" "<<v[x]<<endl;
	ans[x]=sz[x]+v[x];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>v[i];
	cin>>str;str=" "+str;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;i++)str[i]-='a';
	dfs(1);
	for(int i=1;i<=n;i++)upd(ans[i]);
	cout<<_ans.first<<endl<<_ans.second<<endl;
	return 0;
}