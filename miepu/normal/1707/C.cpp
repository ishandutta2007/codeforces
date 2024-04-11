#include<bits/stdc++.h>
#define int long long
const int N=400005,P=21;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

int f[P][N];

int fa[N];
int gf(int k){
	return k==fa[k]?k:fa[k]=gf(fa[k]);
}
int n,m;
int fl[N];
int dp[N],sz[N],sg[N],bc[N],cnt;
int X[N],Y[N];
int s[N];

void dfs(int k,int fa){
	f[0][k]=fa;
	sz[k]=1,sg[k]=++cnt;
	dp[k]=dp[fa]+1;
	for(int i=1;i<P;i++)f[i][k]=f[i-1][f[i-1][k]];
	fore(k)if(_to!=fa){
		dfs(_to,k);
		sz[k]+=sz[_to];
	}
}

int lca(int x,int y){
	if(dp[x]<dp[y])swap(x,y);
	for(int i=P-1;i>=0;i--)
		if(dp[f[i][x]]>=dp[y])x=f[i][x];
	if(x==y)return x;
	for(int i=P-1;i>=0;i--)
		if(f[i][x]!=f[i][y])
			x=f[i][x],y=f[i][y];
	return f[0][x]; 
}
int gsn(int x,int y){
	for(int i=P-1;i>=0;i--)
		if(dp[f[i][x]]>dp[y])
			x=f[i][x];
	return x;
} 

int sm[N];
void add(int l,int r,int k){
	sm[l]+=k;
	sm[r+1]-=k;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		fa[i]=i; 
	}
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		X[i]=x,Y[i]=y;
		if(gf(x)==gf(y))continue;
		fl[i]=1;
		add(x,y),add(y,x);
		fa[gf(x)]=gf(y);
	}
//	cout<<endl;for(int i=1;i<=m;i++)
//		if(!fl[i])
//		cout<<X[i]<<' '<<Y[i]<<endl;cout<<endl;
	
	dfs(1,0);
	
	for(int i=1;i<=m;i++){
		if(fl[i])continue;
		int l=lca(X[i],Y[i]);
		if(l==X[i]||l==Y[i]){
			if(l==Y[i])swap(X[i],Y[i]);
			int t=gsn(Y[i],X[i]);
			add(sg[t],sg[t]+sz[t]-1,1);
			add(sg[Y[i]],sg[Y[i]]+sz[Y[i]]-1,-1); 
		}else{
			add(1,n,1);
			add(sg[X[i]],sg[X[i]]+sz[X[i]]-1,-1);
			add(sg[Y[i]],sg[Y[i]]+sz[Y[i]]-1,-1);
		}
	}
	
	
	for(int i=1;i<=n;i++)
		sm[i]+=sm[i-1];
	for(int i=1;i<=n;i++){
		cout<<(sm[sg[i]]==0);
	}
	
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;//cin>>_T;
	while(_T--)solve();
}