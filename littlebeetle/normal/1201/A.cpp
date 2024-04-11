#include<cstdio>
const int N=1002;
int n,m,i,j,t[N][5],ans,x,y;
char s[N][N];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(j=1;j<=m;j++)
			t[j][s[i][j]-65]++;
	}
	for(j=1;j<=m;j++){
		x=0;
		for(i=0;i<5;i++)
			if(t[j][i]>x)
				x=t[j][i];
		scanf("%d",&y);
		ans+=x*y;
	}
	printf("%d",ans);
}