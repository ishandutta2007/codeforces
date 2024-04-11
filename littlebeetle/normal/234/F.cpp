#include<cstdio>
const int N=202,M=40002,Inf=15<<26;
int n,i,j,a,b,h[N],s[N],f[N][M],g[N][M],ans;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);	
	scanf("%d%d%d",&n,&a,&b);
	for(i=1;i<=n;i++)
		scanf("%d",h+i),s[i]=s[i-1]+h[i];
	for(i=0;i<=n;i++){
		for(j=0;j<=s[n]||j<=a;j++)
			f[i][j]=Inf;
		for(j=0;j<=s[n]||j<=b;j++)
			g[i][j]=Inf;
	}
	f[0][0]=g[0][0]=0;
	for(i=1;i<=n;i++){
		for(j=h[i];j<=a&&j<=s[i];j++)
			f[i][j]=min(f[i-1][j-h[i]],g[i-1][s[i]-j]+min(h[i],h[i-1]));
		for(j=h[i];j<=b&&j<=s[i];j++)
			g[i][j]=min(g[i-1][j-h[i]],f[i-1][s[i]-j]+min(h[i],h[i-1]));
	}
	ans=Inf;
	for(i=0;i<=s[n];i++)
		ans=min(ans,min(f[n][i],g[n][i]));
	printf("%d",ans==Inf?-1:ans);
}