/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
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
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
struct MinCostMaxFlow{
	#define MAXN 1005
	struct edge{
		int to;double cost;int flow;int rev;
		edge(int _to,double _cost,int _flow,int _rev){
			to=_to;cost=_cost;flow=_flow;rev=_rev;
		}
	};
	vector<edge>g[MAXN];
	void add_edge(int x,int y,int f,double c){
		g[x].push_back(edge(y,c,f,(int)g[y].size()));
		g[y].push_back(edge(x,-c,0,(int)g[x].size()-1));
	}
	//flow,cost
	int pre_v[MAXN],pre_e[MAXN];double dist[MAXN],h[MAXN];
	pair<int,double>Min_Cost_Max_Flow(int s,int t,int f=inf){
		pair<int,double>ret(0,0);
		for(int i=0;i<MAXN;i++)h[i]=0;
		while(f){
			for(int i=0;i<MAXN;i++)dist[i]=1e18;
			memset(pre_v,-1,sizeof pre_v);
			set<pair<double,int> >S;
			S.insert(make_pair(0,s));
			dist[s]=0;
			while(!S.empty()){
				int x=S.begin()->second;
				double now=S.begin()->first;
				S.erase(S.begin());
				if(fabs(dist[x]-now)>eps)continue;
				for(int i=0;i<g[x].size();i++){
					if(!g[x][i].flow)continue;
					int to=g[x][i].to;double cost=g[x][i].cost;
					if(dist[to]>now+cost+h[x]-h[to]){
						dist[to]=now+cost+h[x]-h[to];
						pre_v[to]=x;pre_e[to]=i;
						S.insert(make_pair(dist[to],to));
					}
				}
			}
			if(pre_v[t]==-1)return ret;
			for(int i=0;i<MAXN;i++)h[i]+=dist[i];
			int now=t;int cur=f;
			while(now!=s){
				cur=min(cur,g[pre_v[now]][pre_e[now]].flow);
				now=pre_v[now];
			}
			now=t;f-=cur;
			ret.first+=cur;ret.second+=cur*h[t];
			while(now!=s){
				edge &e=g[pre_v[now]][pre_e[now]];
				e.flow-=cur;
				g[e.to][e.rev].flow+=cur;
				now=pre_v[now];
			}
		}
		return ret;
	}
}G;
int n,x[405],y[405];
int s=808,t=809;
int In(int x){
	return x;
}
int Out(int x){
	return x+402;
}
double get_dist(int a,int b){
	return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
int main(){
	cin>>n;int mx=-1e9;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];mx=max(mx,y[i]);
	}
	int pos=-1;
	for(int i=1;i<=n;i++){
		if(y[i]==mx){
			if(pos==-1)pos=i;
			else{
				puts("-1");
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i!=pos)G.add_edge(Out(i),t,1,0);
		G.add_edge(s,In(i),2,0);
		for(int j=1;j<=n;j++){
			if(y[j]<y[i]){
				G.add_edge(In(i),Out(j),1,get_dist(i,j));
			}
		}
	}
	auto got=G.Min_Cost_Max_Flow(s,t);
	if(got.first<n-1){
		puts("-1");
		return 0;
	}
	printf("%.12lf\n",got.second);
	return 0;
}