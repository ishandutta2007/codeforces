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
#pragma comment(" -Wl,--stack=1024000000")
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
struct edge{
	int to,flow,rev;
};
vector<edge>g[3333];
void add_edge(int x,int y,int v){
	g[x].push_back((edge){y,v,g[y].size()});
	g[y].push_back((edge){x,0,(int)g[x].size()-1});
}
int q[3003],dist[3003],b,e;
bool bfs(int s,int t){
	memset(dist,inf,sizeof dist);
	b=e=0;
	q[e++]=s;dist[s]=0;
	while(b<e){
		int x=q[b++];
		for(int i=0;i<g[x].size();i++){
			if(g[x][i].flow){
				int to=g[x][i].to;
				if(dist[to]>dist[x]+1){
					dist[to]=dist[x]+1;
					q[e++]=to;
				}
			}
		}
	}
	return dist[t]<inf;
}
int cur[3003];
int dfs(int x,int t,int f){
	if(x==t)return f;
	int ret=0;
	for(int i=0;i<g[x].size();i++){
		int to=g[x][i].to;
		if(dist[to]==dist[x]+1&&g[x][i].flow){
			int add=dfs(to,t,min(f,g[x][i].flow));
			g[to][g[x][i].rev].flow+=add;
			g[x][i].flow-=add;ret+=add;f-=add;
			if(!f)return ret;
		}
	}
	return ret;
}
int max_flow(int s,int t){
	int ret=0;
	while(bfs(s,t)){
		memset(cur,0,sizeof cur);
		ret+=dfs(s,t,inf);
	}
	return ret;
}
int n,m,h;
int S=3000,T=3001,rule_st=2900;
int get_id(int x,int y){
	return (x-1)*51+y;
}
int main(){
	cin>>n>>h>>m;
	for(int i=1;i<=n;i++){
		for(int j=0;j<h;j++){
			add_edge(get_id(i,j),get_id(i,j+1),h*h-j*j);
		}
		add_edge(S,get_id(i,0),inf);
	}
	for(int i=1;i<=m;i++){
		int l,r,x,c;cin>>l>>r>>x>>c;
		if(x==h)continue;
		add_edge(rule_st+i,T,c);
		for(int j=l;j<=r;j++){
			add_edge(get_id(j,x+1),rule_st+i,inf);
		}
	}
	cout<<n*h*h-max_flow(S,T)<<endl;
	return 0;
}