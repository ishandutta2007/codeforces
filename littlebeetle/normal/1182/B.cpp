#include<cstdio>
const int N=503;
char s[N][N];
int n,m,i,j,x,y;
void d(int u,int v){
	int X=x,Y=y;
	while(s[X+u][Y+v]=='*'){
		X+=u;Y+=v;
		s[X][Y]='.';
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(i=2;i<n;i++)
		for(j=2;j<m;j++)
			if(s[i][j]=='*'&&s[i-1][j]=='*'&&s[i+1][j]=='*'&&s[i][j+1]=='*'&&s[i][j-1]=='*')
				x=i,y=j;
	if(x==0){
		printf("NO");
		return 0;
	}
	d(1,0);
	d(0,1);
	d(-1,0);
	d(0,-1);
	s[x][y]='.';
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(s[i][j]=='*'){
				printf("NO");
				return 0;
			}
	printf("YES");
}