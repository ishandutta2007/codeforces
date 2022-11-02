//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
int m,n,a[35],b[85],nw[85];char dp[85][35][3205],rs[85][85];
inline void pull(int x,int l,int s)
{
	b[x]=a[l];if(x==0) return;
	pull(x-1,l-!dp[x-1][l][s-a[l]],s-a[l]);
}
int main()
{
	int m;read(m);for(int i=1;i<=m;i++) read(a[i]);
	sort(a+1,a+m+1),dp[0][0][0]=1;
	for(int i=1;i<=80;i++) for(int j=1;j<=m;j++) for(int k=i*(i-1)/2;k<=3200;k++)
		if(k>=a[j]) dp[i][j][k]=dp[i-1][j][k-a[j]]|dp[i-1][j-1][k-a[j]];
	for(int i=1;i<=80;i++) if(dp[i][m][i*(i-1)/2]) {n=i,pull(i,m,i*(i-1)/2);break;}
	if(!n) return puts("=("),0;else printf("%d\n",n);
	for(int i=1;i<=n;nw[i]=i-1,i++) for(int j=1;j<=n;j++) rs[i][j]=i>j;
	while(1)
	{
		int fs=0;for(int i=1;i<=n;i++) if(nw[i]<b[i]) {fs=i;break;}
		int ls=0;for(int i=1;i<=n;i++) if(b[i]<nw[i]) {ls=i;break;}
		int nx=0;for(int i=n;i>=1;i--) if(nw[i]==nw[fs]) {nx=i;break;}
		int wh=0;for(int i=n;i>=1;i--) if(rs[ls][i]&&rs[i][nx]) {wh=i;break;}
		if(fs==0||nx==0||ls==0||wh==0) break;
		rs[ls][wh]=rs[wh][nx]=0,rs[wh][ls]=rs[nx][wh]=1,nw[nx]++,nw[ls]--;
	}
	//for(int i=1;i<=n;i++) printf("%d%c",nw[i],i==n?'\n':' ');
	for(int i=1;i<=n;i++) assert(b[i]==nw[i]);
	for(int i=1;i<=n;i++,putchar('\n')) for(int j=1;j<=n;j++) putchar(rs[i][j]^48);
	return 0;
}