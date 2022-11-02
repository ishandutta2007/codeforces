#include<cstdio>
const int N=1002,M=1000000007;
int n,m,i,j,r,c,p[N][N],ans=1;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&r);
		for(j=1;j<=r;j++){
			if(p[i][j]==0||p[i][j]==2)
				p[i][j]=2;
			else{
				printf("0");
				return 0;
			}
		}
		if(p[i][j]==0||p[i][j]==1)
			p[i][j]=1;
		else{
			printf("0");
			return 0;
		}
	}
	for(j=1;j<=m;j++){
		scanf("%d",&c);
		for(i=1;i<=c;i++){
			if(p[i][j]==2||p[i][j]==0)
				p[i][j]=2;
			else{
				printf("0");
				return 0;
			}
		}
		if(p[i][j]==0||p[i][j]==1)
			p[i][j]=1;
		else{
			printf("0");
			return 0;
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(p[i][j]==0)
				ans=ans*2%M;
	printf("%d",ans);
//(1);
}