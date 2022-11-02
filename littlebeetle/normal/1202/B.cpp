#include<cstdio>
const int N=10;
int d[N][N],f[N][N][N][N],x,y,i,j,k,n,sum;
char s[2000002];
int min(int x,int y){
	return x<y?x:y;
}
void dfs(int x,int y){
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			d[i][j]=1000;
	for(i=0;i<N;i++)
		d[i][(i+x)%N]=1,
		d[i][(i+y)%N]=1;
	for(k=0;k<N;k++)
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			f[x][y][i][j]=d[i][j];
}
void Prepare(){
	for(x=0;x<N;x++)
		for(y=0;y<N;y++)
			dfs(x,y);
}
int main(){
	Prepare();
	scanf("%s",s+1);
	for(x=0;x<N;x++){
		for(y=0;y<N;y++){
			sum=0;
			for(n=1;s[n+1];n++){
				i=s[n]-48;j=s[n+1]-48;
				if(f[x][y][i][j]>=1000){
					printf("-1");
					sum=-1;
					break;
				}
				sum+=f[x][y][i][j]-1;
			}
			if(sum!=-1)
				printf("%d",sum);
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}