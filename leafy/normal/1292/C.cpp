#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
const int N=3005,mod=998244353;
inline int pls(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int dec(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=mul(a,a)) if(b&1) res=mul(res,a);
	return res;
}
int n;
vector<int> G[N];
int dep[N],fa[N],son[N],siz[N],top[N];
ll f[N][N];int to[N][N];
void dfs1(int u,int f){
	fa[u]=f;siz[u]=1;dep[u]=dep[f]+1;
	int t=u;
	while(fa[t]!=0) {to[fa[t]][u]=t;t=fa[t];}
	for(int v:G[u]) {
		if(v==f) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int k){
	top[u]=k;
	if(!son[u]) return;
	dfs2(son[u],k);
	for(int v:G[u]) if(v!=fa[u]&&v!=son[u]) dfs2(v,v); 
}
inline int LCA(int u,int v){
    while(top[u]!=top[v]){
        dep[top[u]]>dep[top[v]]?u=fa[top[u]]:v=fa[top[v]];
    }
    return dep[u]<dep[v]?u:v;
}
ll dfs(int l,int r){
	if(l==r) return 0;
	int z=LCA(l,r);
	if(z==r) swap(l,r);
	if(f[l][r]) return f[l][r];
	if(z==l) {
		int L=to[l][r],R=fa[r];
		int s1=n-siz[L],s2=siz[r];
		f[l][r]=max(dfs(L,r),dfs(l,R))+s1*s2;
	}else {
		int L=fa[l],R=fa[r];
		f[l][r]=max(dfs(L,r),dfs(l,R))+siz[l]*siz[r];
	}
	return f[l][r];
}
int main(){
	n=read();
	for(int i=1;i<n;i++) {
		int u=read(),v=read();
		G[u].push_back(v);G[v].push_back(u);
	}
	ll ans=0;dfs1(1,0);dfs2(1,1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans=max(ans,dfs(i,j));
	cout<<ans;
	return 0;
}