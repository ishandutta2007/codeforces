#include<cstdio>
const int N=32;
typedef long long ll;
int n,m,i,j,t;
ll c[N][N],ans;
void Prepare(){
	for(i=0;i<N;i++){
		c[i][0]=1;
		for(j=1;j<=i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
}
int main(){
	Prepare();
	scanf("%d%d%d",&n,&m,&t);
	for(i=4;i<t;i++)
		if(n>=i&&t-i<=m)
		ans+=c[n][i]*c[m][t-i];
	printf("%I64d",ans);
}