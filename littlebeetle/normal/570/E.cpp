#include<cstdio>
const int N=500,M=1000000007;
int n,m,k,l,i,j,a,b,c,d,f[N][N],ans,t,q;
char s[N][N];
int min(int x,int y){
	return x<y?x:y;
}
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d%d",&n,&m);
	n--;m--;
	for(i=0;i<=n;i++)
		scanf("%s",s[i]);
	k=n+m>>1;
	if(s[0][0]==s[n][m])
	f[0][0]=1;
	for(l=1;l<=k;l++){
		t=max(l-m,0);
		for(a=min(l,n);a>=t;a--){
			q=max(t,2*l-a-m);
			for(b=min(n-a,l);b>=q;b--){
				c=l-a;
				d=l-b;
				if(s[a][c]==s[n-b][m-d])
					f[a][b]=(0ll+(a?f[a-1][b]:0)+f[a][b]+(b?f[a][b-1]:0)+(a&&b?f[a-1][b-1]:0))%M;
				else
					f[a][b]=0;
			}
		}
	}
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			if(i+j<=n&&k-i+k-j<=m&&k-i<=m&&k-j<=m&&k-i>=0&&k-j>=0)
		ans=(ans+f[i][j])%M;
	printf("%d",ans);
}