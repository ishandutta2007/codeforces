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
int n=10000,m;
vector<int>g[10005],gg[10005];
bool hv[10005];
int par[10005];
int find(int x){
	return x==par[x]?x:par[x]=find(par[x]);
}
vector<pair<int,int> >E;
namespace Euler{
#define N 10005
int h[N],nxt[N<<2],to[N<<2],ban[N<<2],tp=1;
void ae(int u,int v){nxt[++tp]=h[u];to[h[u]=tp]=v;}
int n,m,type;
int ind[N],out[N];
int st[N<<1],top;
void dfs(int u){
	while(h[u]){
		if(!ban[h[u]]){
			int t=h[u];h[u]=nxt[h[u]];
			if(type==1) ban[t]=ban[t^1]=1;
			dfs(to[t]);
			if(type==2) st[++top]=t-1;
			else if(t&1) st[++top]=-t/2;
			else st[++top]=t/2;
		}
		else h[u]=nxt[h[u]];
	}
}
vector<int> get(int c){
	type=1;n=10000;m=0;top=0;tp=1;
	memset(h,0,sizeof h);
	memset(nxt,0,sizeof nxt);
	memset(to,0,sizeof to);
	memset(ban,0,sizeof ban);
	memset(out,0,sizeof out);
	for(auto p:E){
		int u=p.first,v=p.second;
		out[u]++;out[v]++;m++;
		ae(u,v);ae(v,u);
	}
	int pos=1;
	while(find(pos)!=c)pos++;
	int v1=-1,v2=-1;
	for(int i=1;i<=n;i++){
		if(out[i]&1)if(find(i)==c){
			if(v1==-1)v1=i;
			else v2=i;
		}
	}
	if(v1!=-1)ae(v1,v2),ae(v2,v1);
	if(v1!=-1)pos=v1;
	dfs(pos);
	vector<int>ret;
	for(int i=top;i;i--)if(abs(st[i])<=m)ret.push_back(st[i]);
	return ret;
}
};
vector<int>v[10005];
int deg[10005];
bool check(int x){
	int cnt=0;
	for(int i=1;i<=n;i++)if(find(i)==x){
		if(deg[i]&1)cnt++;
	}
	return cnt==0||cnt==2;
}
map<pair<int,int>,vector<int> >id,tid;
vector<int>solve(int c){
	tid=id;
	vector<int>p=Euler::get(c);
	vector<int>ret;
	for(auto &pp:p){
		pp=abs(pp);
		ret.push_back(pp);
	}
	return ret;
}
int main(){
	#ifndef LOCAL
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	for(int i=1;i<=n;i++)par[i]=i;
	cin>>m;
	if(m==1){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=m;i++){
		int a,b;cin>>a>>b;
		E.push_back(make_pair(a,b));
		g[a].push_back(b);
		g[b].push_back(a);
		hv[a]=hv[b]=1;
		par[find(a)]=find(b);
		deg[a]++;deg[b]++;
		id[make_pair(min(a,b),max(a,b))].push_back(i);
	}
	set<int>col;
	for(int i=1;i<=n;i++)if(hv[i])v[find(i)].push_back(i),col.insert(find(i));
	if(col.size()>2){
		puts("-1");
		return 0;
	}
	if(col.size()==2){
		if(!check(*col.begin())||!check(*col.rbegin())){
			puts("-1");
			return 0;
		}
		auto v1=solve(*col.begin());
		auto v2=solve(*col.rbegin());
		cout<<v1.size()<<endl;
		for(auto v:v1)cout<<v<<" ";cout<<endl;
		cout<<v2.size()<<endl;
		for(auto v:v2)cout<<v<<" ";cout<<endl;
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(deg[i]&1)if(hv[i])cnt++;
	}
	if(cnt==0||cnt==2){
		auto v=solve(*col.begin());
		cout<<1<<endl;
		cout<<v[0]<<endl;
		cout<<v.size()-1<<endl;
		for(int i=1;i<v.size();i++)cout<<v[i]<<" ";
		cout<<endl;
	}
	if(cnt==4){
		//case work
		vector<int>vv;
		for(int i=1;i<=n;i++)if(hv[i])if(deg[i]&1)vv.push_back(i);
		g[vv[0]].push_back(vv[1]);
		g[vv[1]].push_back(vv[0]);
		E.push_back(make_pair(vv[0],vv[1]));
		auto v=solve(*col.begin());
		vector<int>v1,v2;
		bool occ=0;
		for(int i=0;i<v.size();i++){
			if(v[i]==E.size()){
				occ=1;
				continue;
			}
			if(!occ)v1.push_back(v[i]);
			else v2.push_back(v[i]);
		}
		cout<<v1.size()<<endl;
		for(auto va:v1)cout<<va<<" ";cout<<endl;
		cout<<v2.size()<<endl;
		for(auto va:v2)cout<<va<<" ";cout<<endl;
	}
	return 0;
}