#include<cstdio>
#include<cstring>
using namespace std;const int INF=-1e9-7;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
inline void chk(int &a,int b) {if(a<b) a=b;}
int n,m,P,dp[105][105][15],a[105][105],tp;char st[105];
int main()
{
	read(n),read(m),read(P),P++,memset(dp,~0x3f,sizeof(dp));int res=INF,y,g;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%1d",&a[i][j]);
	for(int j=1;j<=m;j++) dp[1][j][a[1][j]%P]=a[1][j];
	for(int i=1;i<n;i++) for(int j=1;j<=m;j++) for(int l=0;l<P;l++) if(dp[i][j][l]>INF)
		chk(dp[i+1][j-1][(l+a[i+1][j-1])%P],dp[i][j][l]+a[i+1][j-1]),chk(dp[i+1][j+1][(l+a[i+1][j+1])%P],dp[i][j][l]+a[i+1][j+1]);
	for(int j=1;j<=m;j++) if(res<dp[n][j][0]) res=dp[n][j][0],y=j;
	if(res<=INF) return puts("-1");else tp=0,g=0,printf("%d\n%d\n",res,y);
	// for(int k=0;k<P;k++) {for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d%c",dp[i][j][k],j==m?'\n':'\t');putchar('\n');}
	for(int s=n;s>1;s--)
	{
		if(dp[s][y][g]>dp[s-1][y-1][(g-a[s][y]+P*10)%P]+a[s][y]||y==1) g=(g-a[s][y]+P*10)%P,st[++tp]='R',y++;
		else g=(g-a[s][y]+P*10)%P,st[++tp]='L',y--;
	}
	for(int i=1;i<=tp;i++) putchar(st[i]);
	return putchar('\n'),0;
}