#include <bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=3e5+10;
const LL INF=1e18;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}
void get_min(LL &x,LL y){
	if(x>y) x=y;
}
void get_max(LL &x,LL y){
	if(x<y) x=y;
}
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int n,m;
struct edge{
	int l,r;
	LL w;
}e[610*610];
LL dis[610][610];
LL lim[610][610];
LL G[610][610];
void MAIN(){
    n=read();m=read();
    for(int i=1;i<=n;++i){
    	for(int j=1;j<=n;++j){
    		if(i==j) dis[i][j]=0;
    		else dis[i][j]=INF;
    		lim[i][j]=-INF;
    		G[i][j]=-INF;
		}
	}
    for(int i=1;i<=m;++i){
    	e[i].l=read();
    	e[i].r=read();
    	e[i].w=read();
    	get_min(dis[e[i].l][e[i].r],e[i].w);
    	get_min(dis[e[i].r][e[i].l],e[i].w);
	}
	int Q=read();
	int u,v;
	LL val;
	while(Q--){
		u=read();
		v=read();
		val=read();
		get_max(lim[u][v],val);
		get_max(lim[v][u],val);
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i!=j&&i!=k&&j!=k){
					get_min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=1;k<=n;++k){
				get_max(G[i][j],lim[k][i]-dis[k][j]);
			}
		}
	}
	int ans=0;
	bool flag=0;
	for(int i=1;i<=m;++i){
		flag=0;
		for(int j=1;j<=n;++j){
			if(G[j][e[i].l]>=e[i].w+dis[e[i].r][j]) {
				flag=1;
				break;
			}
		}
		if(flag) ++ans;
	}
	printf("%d\n",ans);
	return;
}

int main(){
    int ttt=1;
    while(ttt--) MAIN();
    return 0;
}