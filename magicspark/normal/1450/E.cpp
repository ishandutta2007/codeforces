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
int n,m,f[205][205],col[205],deg[205],vis[205],val[205];
vector<int>g[205];
vector<pair<int,int> >ng[205];
void dfs(int x){
	for(auto to:g[x]){
		if(!col[to]){
			col[to]=3-col[x];
			dfs(to);
		}else{
			if(col[to]==col[x]){
				puts("NO");
				exit(0);
			}
		}
	}
}
int main(){
	cin>>n>>m;
	memset(f,inf,sizeof f);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		int x,y,c;
		cin>>x>>y>>c;
		f[x][y]=1;
		g[x].push_back(y);
		g[y].push_back(x);
		if(c)f[y][x]=-1;
		else f[y][x]=1;
	}
	col[1]=1;
	dfs(1);
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(f[i][j]!=min(f[i][j],f[i][k]+f[k][j]))return puts("NO"),0;
	pair<int,int>best(-inf,0);
	puts("YES");
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			ans=max(ans,f[i][j]);
			if(f[i][j]==inf){
				ans=-inf;
				break;
			}
		}
		best=max(best,make_pair(ans,i));
	}
	cout<<best.first<<endl;
	for(int i=1;i<=n;i++){
		cout<<f[best.second][i]<<" ";
	}
	return 0;
}