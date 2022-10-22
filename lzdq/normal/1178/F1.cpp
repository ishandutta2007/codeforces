#include<cstdio>
const int MAXN=505,Mod=998244353;
int n,m;
int c[MAXN],f[MAXN][MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",c+i),f[i][i-1]=1;
	f[n+1][n]=1;
	for(int i=0; i<n; i++){
		for(int j=1; j+i<=n; j++){
			int x=j,y=j+i,w=j;
			for(int k=x; k<=y; k++)
				if(c[w]>c[k]) w=k;
			int s1=0,s2=0;
			for(int k=x; k<=w; k++)
				s1=(s1+1ll*f[x][k-1]*f[k][w-1])%Mod;
			for(int k=w; k<=y; k++)
				s2=(s2+1ll*f[w+1][k]*f[k+1][y])%Mod;
			f[x][y]=1ll*s1*s2%Mod;
			//printf("%d %d s1 %d s2 %d f %d\n",x,y,s1,s2,f[x][y]);
		}
	}
	printf("%d\n",f[1][n]);
	return 0;
}