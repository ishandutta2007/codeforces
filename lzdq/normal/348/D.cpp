#include<cstdio>
typedef long long ll;
const int MAXN=3005,mod=1e9+7;
int n,m;
char s[MAXN][MAXN];
int f[MAXN][MAXN];
ll Calc(int x1,int y1,int x2,int y2){
	if(x1>x2||y1>y2) return 0;
	for(int i=x1; i<=x2; i++)
		for(int j=y1; j<=y2; j++){
			f[i][j]=0;
			if(s[i][j]=='#') continue;
			if(i==x1&&j==y1) f[i][j]=1;
			if(i>x1) f[i][j]=(f[i][j]+f[i-1][j])%mod;
			if(j>y1) f[i][j]=(f[i][j]+f[i][j-1])%mod;
		}
	return f[x2][y2];
}
int ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%s",s[i]+1);
	ans=(Calc(1,2,n-1,m)*Calc(2,1,n,m-1)-Calc(1,2,n,m-1)*Calc(2,1,n-1,m)%mod+mod)%mod;
	printf("%d\n",ans);
	return 0;
}