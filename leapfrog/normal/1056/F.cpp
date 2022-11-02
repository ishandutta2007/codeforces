//Coded by leapfrog on 2021.11.05 {{{
//
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
const int N=105;int n;
struct ${int a,p;char operator<($ b) {return a>b.a;}}a[N];
typedef long double ld;ld dp[N][N*10],C,T;
inline void solve()
{
	read(n),scanf("%Lf%Lf",&C,&T);for(int i=1;i<=n;i++) read(a[i].a,a[i].p);
	int m=0;sort(a+1,a+n+1);for(int i=1;i<=n;i++) m+=a[i].p;
	for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) dp[i][j]=1e18;
	dp[0][0]=0;for(int i=1;i<=n;i++)
	{
		ld pw=1;for(int j=1;j<=i;j++) pw/=0.9;
		for(int j=i;j>=1;j--,pw*=0.9) for(int k=m;k>=a[i].p;k--)
			dp[j][k]=min(dp[j-1][k-a[i].p]+a[i].a*pw,dp[j][k]);
	}
	//for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%.5Lf%c",dp[i][j],j==m?'\n':' ');
	int rs=0;for(int i=1;i<=n;i++)
	{
		ld t=max((T-10*i-1/C)/2,(ld)0),tim=(T-10*i-t)*(1+C*t);//(T-t)*(1+Ct)
		for(int j=m;j;j--) if(dp[i][j]<=tim) {rs=max(rs,j);break;}
	}
	printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}