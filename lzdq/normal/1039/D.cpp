#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,q,k;
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1];
inline void adde(int u,int v){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	h[u]=cnte;
}
int f[MAXN],fa[MAXN],p[MAXN],clk;
void Dfs(int u){
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		Dfs(v);
	}
	p[++clk]=u;
	return ;
}
int Calc(int k){
	if(k==1) return n;
	int res=0;
	for(int i=1; i<=n; i++)
		f[i]=1;
	for(int i=1; i<=n; i++){
		int u=p[i];
		//printf("u %d f %d\n",u,f[u]);
		if(!f[u]) continue;
		if(f[fa[u]]+f[u]>=k) res++,f[fa[u]]=0;
		else if(f[fa[u]]) f[fa[u]]=max(f[fa[u]],f[u]+1);
	}
	return res;
}
int main(){
	//freopen("in1.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		adde(u,v),adde(v,u);
	}
	q=min(250,n);
	Dfs(1);
	for(int i=1;i<=q;i++)
		printf("%d\n",Calc(i));
	int w=q;
	for(int i=q+1,l,r;i<=n;){
		l=i,r=n;
		int t=Calc(i);
		//printf("i %d l %d r %d\n",i,l,r);
		while(l<r){
			int mid=l+r+1>>1;
			if(Calc(mid)<t) r=mid-1;
			else l=mid;
		}
		while(i<=r) printf("%d\n",t),i++;
	}
	return 0;
}