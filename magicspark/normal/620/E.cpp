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
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#endif
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}

int n,m;
int c[400005];
vector<int>g[400005];
int L[400005],R[400005],dfs_clock;

struct SGT{
	#define SIZE 524288
	ll mask[SIZE<<1],lazy[SIZE<<1],l,r,v;
	void set(int x,ll v){
		x+=SIZE;mask[x]=v;
		while(x!=1){
			x>>=1;
			mask[x]=mask[x<<1]|mask[x<<1|1];
		}
	}
	void pushdown(int k){
		mask[k<<1]=mask[k<<1|1]=lazy[k<<1]=lazy[k<<1|1]=lazy[k];lazy[k]=0;
	}
	void pushup(int k){
		mask[k]=mask[k<<1]|mask[k<<1|1];
	}
	void _modify(int L,int R,int k){
		if(R<l||r<L)return;
		if(l<=L&&R<=r){
			mask[k]=lazy[k]=v;
			return;
		}
		if(lazy[k])pushdown(k);
		_modify(L,L+R>>1,k<<1);
		_modify((L+R>>1)+1,R,k<<1|1);
		pushup(k);
	}
	void modify(int _l,int _r,ll _v){
		l=_l;r=_r;v=_v;_modify(0,SIZE-1,1);
	}
	ll _query(int L,int R,int k){
		if(R<l||r<L)return 0;
		if(l<=L&&R<=r){
//			cerr<<L<<" "<<R<<" "<<k<<" "<<mask[k]<<endl; 
			return mask[k];
		}
		if(lazy[k])pushdown(k);
		return _query(L,L+R>>1,k<<1)|_query((L+R>>1)+1,R,k<<1|1);
	}
	ll query(int _l,int _r){
		l=_l;r=_r;return _query(0,SIZE-1,1);
	}
}Tree;

void dfs(int x,int par){
	L[x]=++dfs_clock;
	for(int i=0;i<g[x].size();i++){
		int to=g[x][i];
		if(to!=par){
			dfs(to,x);
		}
	}
	R[x]=dfs_clock;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	dfs(1,-1);
	
	for(int i=1;i<=n;i++){
		Tree.set(L[i],1ll<<c[i]);
	}
	
	while(m--){
		int type;scanf("%d",&type);
		if(type==1){
			int v,k;scanf("%d%d",&v,&k);
			Tree.modify(L[v],R[v],1ll<<k);
		}else{
			int v;scanf("%d",&v);
//			cerr<<Tree.query(L[v],R[v])<<endl;
			printf("%d\n",__builtin_popcountll(Tree.query(L[v],R[v])));
		}
	}
	
	return 0;
}