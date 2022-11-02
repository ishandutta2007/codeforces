#include<cstdio>
const int N=200002;
int g[4][2][2],h[4][2][2],i,j;
int p[N][2],f[N][4],n,q;
void Uzi(){
	g[1][0][0]=1;
	g[1][0][1]=1;
	g[1][1][1]=2;
	g[2][0][0]=2;
	g[2][1][0]=2;
	g[2][1][1]=1;
	g[3][0][0]=3;
	g[3][0][1]=1;
	g[3][1][0]=2;
	g[3][1][1]=1;
	h[3][1][1]=2;
}
int main(){
	Uzi();
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		for(i=0;i<=n;i++)
			for(j=0;j<4;j++)
				f[i][j]=0;
		f[0][1]=1;
		for(i=1;i<=n;i++)
			scanf("%1d",p[i]+0),p[i][0]=p[i][0]>2;
		for(i=1;i<=n;i++)
			scanf("%1d",p[i]+1),p[i][1]=p[i][1]>2;
		for(i=1;i<=n;i++)
			for(j=1;j<=3;j++)
				if(f[i-1][j]){
					f[i][h[j][p[i][0]][p[i][1]]]=1;
					f[i][g[j][p[i][0]][p[i][1]]]=1;
				}
		printf("%s\n",f[n][2]||f[n][3]?"YES":"NO");
	}
	//while(1);
}