/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
#define MAXN 405
struct Max_Flow{
	struct edge{
		int to,flow,rev,ori;
		edge(int _to,int _flow,int _rev){to=_to;flow=_flow;ori=_flow;rev=_rev;}
	};
	vector<edge>g[MAXN];
	void clear(){
		for(int i=0;i<MAXN;i++)g[i].clear();
	}
	void reset(){
		for(int i=0;i<MAXN;i++){
			for(int j=0;j<g[i].size();j++){
				g[i][j].flow=g[i][j].ori;
			}
		}
	}
	void add_edge(int x,int y,int z){
		g[x].push_back(edge(y,z,g[y].size()));
		g[y].push_back(edge(x,0,(int)g[x].size()-1));
	}
	int q[MAXN],dist[MAXN],itr[MAXN],b,e;
	bool bfs(int s,int t){
		memset(dist,inf,sizeof dist);
		b=e=0;q[e++]=s;
		dist[s]=0;
		while(b<e){
			int x=q[b++];
			for(int i=0;i<g[x].size();i++){
				int to=g[x][i].to;
				if(dist[to]>dist[x]+1&&g[x][i].flow>0){
					dist[to]=dist[x]+1;
					q[e++]=to;
				}
			}
		}
		return dist[t]<inf;
	}
	int dfs(int x,int t,int f){
		if(x==t)return f;
		int ret=0;
		for(int &i=itr[x];i<g[x].size();i++){
			int to=g[x][i].to;
			if(dist[to]!=dist[x]+1)continue;
			if(!g[x][i].flow)continue;
			int v=dfs(to,t,min(f-ret,g[x][i].flow));
			ret+=v;
			g[x][i].flow-=v;
			g[to][g[x][i].rev].flow+=v;
			if(ret==f)break;
		}
		return ret;
	}
	int max_flow(int s,int t){
		int ret=0;
		while(bfs(s,t)){
			memset(itr,0,sizeof itr);
			ret+=dfs(s,t,INT_MAX);
		}
		return ret;
	}
}G;
int n;
int a[205];
int l[205],lsz,r[205],rsz;
vector<int>g[205];
bool used[205];
bool prime(int x){
	for(int i=2;i*i<=x;i++)if(x%i==0)return false;
	return true;
}
vector<int>vec;
void dfs(int x,int p){
	vec.push_back(x);used[x]=1;
	for(int i=0;i<g[x].size();i++){
		if(!used[g[x][i]]){
			dfs(g[x][i],x);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]&1)l[++lsz]=i;
		else r[++rsz]=i;
	}
	int S=402,T=403;
	for(int i=1;i<=lsz;i++){
		G.add_edge(S,i,2);
	}
	for(int i=1;i<=rsz;i++){
		G.add_edge(i+200,T,2);
	}
	for(int i=1;i<=lsz;i++){
		for(int j=1;j<=rsz;j++){
			if(prime(a[l[i]]+a[r[j]])){
				G.add_edge(i,j+200,1);
			}
		}
	}
	int m=G.max_flow(S,T);
	if(m<n){
		puts("Impossible");
	}else{
		for(int i=1;i<=lsz;i++){
			for(int j=0;j<G.g[i].size();j++){
				int to=G.g[i][j].to;
				if(to>=201&&to<=200+rsz&&G.g[i][j].flow==0){
					g[l[i]].push_back(r[to-200]);
					g[r[to-200]].push_back(l[i]);
				}
			}
		}
		vector<vector<int> >ans;
		for(int i=1;i<=n;i++){
			if(!used[i]){
				vec.clear();
				dfs(i,g[i][0]);
				ans.push_back(vec);
			}
		}
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++){
			cout<<ans[i].size()<<" ";
			for(int j=0;j<ans[i].size();j++)cout<<ans[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}