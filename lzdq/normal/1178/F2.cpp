#include<cstdio>
const int MAXN=1505,MAXM=1e6+5,Mod=998244353;
int n,m;
int a[MAXM];
int c[MAXN],f[MAXN][MAXN];
int pos[MAXN][MAXN];
int Calc(){
	int ty=0;
	for(int i=1; i<=m; i++){
		if(a[i]!=a[i-1]) *pos[c[++ty]=a[i]]=0;
		if(ty>n*2+1) return 0;
	}
	int n=ty;
	for(int i=1; i<=n; i++)
		pos[c[i]][++*pos[c[i]]]=i;
	for(int i=0; i<n; i++){
		for(int j=1; j+i<=n; j++){
			int x=j,y=j+i,mi=2e9;
			for(int k=x; k<=y; k++)
				if(mi>c[k]) mi=c[k];
			if(pos[mi][1]<x||y<pos[mi][*pos[mi]]){
				f[x][y]=0;
				continue;
			}
			int s1=0,s2=0;
			for(int k=x; k<=pos[mi][1]; k++)
				s1=(s1+1ll*f[x][k-1]*f[k][pos[mi][1]-1])%Mod;
			for(int k=pos[mi][*pos[mi]]; k<=y; k++)
				s2=(s2+1ll*f[pos[mi][*pos[mi]]+1][k]*f[k+1][y])%Mod;
			f[x][y]=1ll*s1*s2%Mod;
			for(int k=1;k<*pos[mi];k++)
				f[x][y]=1ll*f[x][y]*f[pos[mi][k]+1][pos[mi][k+1]-1]%Mod;
			//printf("%d %d s1 %d s2 %d f %d\n",x,y,s1,s2,f[x][y]);
		}
	}
	return f[1][n];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++)
		scanf("%d",a+i);
	for(int i=0; i<=1000; i++)
		f[i+1][i]=1;
	printf("%d\n",Calc());
	return 0;
}