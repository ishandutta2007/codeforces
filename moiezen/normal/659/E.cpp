#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 100005
int n,m,i,j,k,x,y,u,v;
int fa[N],siz[N],se[N];
int bo[N];
int ans;
int father(int x){
	return fa[x]==x?x:fa[x]=father(fa[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	rpt(i,1,n) fa[i]=i,siz[i]=1,se[i]=bo[i]=0;
	rpt(i,1,m){
		scanf("%d%d",&x,&y);
		u=father(x);v=father(y);
		if(u==v){
			se[u]++;
			continue;
		}
		if(siz[u]<siz[v]){
			k=u;u=v;v=k;
		}
		fa[v]=u;siz[u]+=siz[v];se[u]+=se[v];
		se[u]++;
	}
	ans=0;
	rpt(i,1,n){
		x=father(i);
		if(bo[x]) continue;
		if(siz[x]==se[x]+1) ans++;
		bo[x]=1;
	}
	printf("%d",ans);
}