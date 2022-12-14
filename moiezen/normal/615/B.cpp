#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#define rpt(i,l,r) for(i=l;i<=r;i++)
#define rpd(i,r,l) for(i=r;i>=l;i--)
#define N 100005
#define M 200005
struct edge{
	int x,y;
}e[M];
bool cmp(edge a,edge b){
	return a.x<b.x;
}
int n,m,i,j,k,t;
long long tmp,ans;
int d[N]={0},f[N];
int main(){
	scanf("%d%d",&n,&m);
	rpt(i,1,m){
		scanf("%d%d",&e[i].x,&e[i].y);
		if(e[i].x>e[i].y){
			t=e[i].x;
			e[i].x=e[i].y;
			e[i].y=t;
		}
		d[e[i].x]++;d[e[i].y]++;
	}
	std::sort(e+1,e+m+1,cmp);
	rpt(i,1,n) f[i]=1;
	rpt(i,1,m) if(f[e[i].x]+1>f[e[i].y]) f[e[i].y]=f[e[i].x]+1;
	ans=0;
	rpt(i,1,n){
		tmp=(long long)d[i]*f[i];
		if(tmp>ans) ans=tmp;
	}
	printf("%I64d\n",ans);
}