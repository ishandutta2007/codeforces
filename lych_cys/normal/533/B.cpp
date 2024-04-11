#include<bits/stdc++.h>
#define ll long long
#define N 200009
using namespace std;

int n,fa[N],a[N],fst[N],nxt[N]; ll f[N],g[N];
void dfs(int x){
	int i; ll u=0,v=-(1ll<<60),p,q;
	for (i=fst[x]; i; i=nxt[i]){
		dfs(i); int y=i;
		p=max(u+g[y],v+f[y]); q=max(v+g[y],u+f[y]);
		u=p; v=q;
	}
	f[x]=max(u+a[x],v); g[x]=u;
}
int main(){
	scanf("%d",&n);
	int i,rt;
	for (i=1; i<=n; i++){
		scanf("%d%d",&fa[i],&a[i]);
		if (fa[i]!=-1){
			nxt[i]=fst[fa[i]]; fst[fa[i]]=i;
		} else{
			rt=i; fa[i]=0;
		}
	}
	dfs(rt);
	printf("%lld\n",max(f[1],g[1]));
	return 0;
}