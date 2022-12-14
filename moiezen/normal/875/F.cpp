#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++) 
#define ll long long
#define N 300005
int n,m,u,v;
int fa[N],tag[N];
ll ans;
int father(int x){
	return fa[x]==x?x:fa[x]=father(fa[x]);
}
struct edge{
	int a,b,c;
}e[N];
bool cmp(edge x,edge y){
	return x.c>y.c;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m) scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
	std::sort(e+1,e+m+1,cmp);
	ans=0;
	rep(i,1,n) fa[i]=i;
	rep(i,1,m){
		u=father(e[i].a),v=father(e[i].b);
		if(u!=v){
			if(tag[u]&&tag[v]) continue;
			if(tag[v]) tag[u]=1;
			fa[v]=u;
			ans+=e[i].c;
		}
		else if(!tag[u]){
			tag[u]=1;
			ans+=e[i].c;
		}
	}
	printf("%lld\n",ans);
}