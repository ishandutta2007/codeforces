#include<cstdio>
const int N=2002,M=1000000007;
int n,m,i,j,k;
int f[N][N],g[N][N];
int sf[N][N],sg[N][N];
char s[N][N];
void init(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(j=1;j<=m;j++)
			if(s[i][j]=='R')
				sf[i][j]++,sg[i][j]++;
	}
	for(i=n;i;i--)
		for(j=m;j;j--){
			sf[i][j]+=sf[i][j+1];
			sg[i][j]+=sg[i+1][j];
		}
}
void work(){
	f[1][1]=1;
	f[2][1]=-1;
	g[1][1]=1;
	g[1][2]=-1;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			f[i][j]=(f[i][j]+f[i-1][j])%M;
			g[i][j+1]=(g[i][j+1]+f[i][j])%M;
			g[i][m-sf[i][j+1]+1]=(g[i][m-sf[i][j+1]+1]-f[i][j])%M;
			g[i][j]=(g[i][j]+g[i][j-1])%M;
			f[i+1][j]=(f[i+1][j]+g[i][j])%M;
			f[n-sg[i+1][j]+1][j]=(f[n-sg[i+1][j]+1][j]-g[i][j])%M;
		}
		if(n==1&&m==1)
			printf("1");
		else
	printf("%d",((f[n][m]+M)%M+(g[n][m]+M)%M)%M);
		//while(1);
}
int main(){
	init();
	work();
	return 0;
}