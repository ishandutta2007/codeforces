#include<cstdio>
const int N=1002;
int n,m,i,j,u,v,f[N][N];
char s[N][N];
bool ok(int x,int y){
	for(u=0;u<=2;u++)
		for(v=0;v<=2;v++){
			if(u==1&&v==1)
				continue;
			if(s[x+u][y+v]=='.')
				return 0;
		}
	return 1;
}//
void draw(int x,int y){
	for(u=0;u<=2;u++)
		for(v=0;v<=2;v++){
			if(u==1&&v==1)
				continue;
			f[x+u][y+v]=1;
		}
}
	int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(i=1;i+2<=n;i++)
		for(j=1;j+2<=m;j++)
			if(ok(i,j))
				draw(i,j);
	for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
if((f[i][j]==0&&s[i][j]=='#')||(f[i][j]==1&&s[i][j]=='.')){
printf("NO");
return 0;
}
printf("YES");
}