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
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
int n,q;
vector<int>g[100005];
int p[20][100005],dep[100005];
void dfs(int x,int pr){
	p[0][x]=pr;
	for(auto to:g[x]){
		if(to!=pr){
			dep[to]=dep[x]+1;
			dfs(to,x);
		}
	}
}
void init(){
	dfs(1,0);
	for(int i=1;i<18;i++){
		for(int j=1;j<=n;j++){
			p[i][j]=p[i-1][p[i-1][j]];
		}
	}
}
int lca(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	int mask=dep[y]-dep[x];
	int ret=mask;
	for(int i=0;i<18;i++)if((1<<i)&mask){
		y=p[i][y];
	}
	if(x==y)return ret;
	for(int i=17;i>=0;i--){
		if(p[i][x]!=p[i][y]){
			ret+=1<<i+1;
			x=p[i][x];y=p[i][y];
		}
	}
	return ret+2;
}
int LCA(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	int mask=dep[y]-dep[x];
	int ret=mask;
	for(int i=0;i<18;i++)if((1<<i)&mask){
		y=p[i][y];
	}
	if(x==y)return ret;
	for(int i=17;i>=0;i--){
		if(p[i][x]!=p[i][y]){
			ret+=1<<i+1;
			x=p[i][x];y=p[i][y];
		}
	}
	return p[0][x];
}
bool ok(int x,int k){
	if(x<=k&&(x-k)%2==0)return true;
	return false;
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	init();
	cin>>q;
	while(q--){
		int x,y,a,b,k;
		cin>>x>>y>>a>>b>>k;
		int way1=lca(a,b),way2=lca(a,x)+lca(b,y)+1,way3=lca(a,y)+lca(b,x)+1;
//		cerr<<way1<<" "<<way2<<" "<<way3<<endl;
		if(ok(way1,k)||ok(way2,k)||ok(way3,k)){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}