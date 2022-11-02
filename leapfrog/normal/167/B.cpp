//Coded by Kamiyama_Shiki on 2021.11.19 {{{
//
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=205;typedef long double ld;
ld dp[N][N][N];int n,l,k;//i j  k 
struct ${int p,v;char operator<($ b) {return v>b.v;}}q[N];
int main()
{
	read(n,l,k);for(int i=1;i<=n;i++) read(q[i].p);
	for(int i=1;i<=n;i++) read(q[i].v);
	sort(q+1,q+n+1),dp[0][k][0]=1;
	for(int i=1;i<=n;i++) for(int j=0;j<=200;j++) for(int k=0;k<i;k++)
	{
		dp[i][j][k]+=dp[i-1][j][k]*(100-q[i].p)/100.0;
		if(j+q[i].v>=0) dp[i][min(j+q[i].v,200)][k+1]+=dp[i-1][j][k]*q[i].p/100.0;
	}
	//for(int i=1;i<=n;i++) for(int j=0;j<=2;j++) for(int k=0;k<i;k++)
	//	if(dp[i][j][k]>=1e-9) printf("%d %d %d : %.10Lf\n",i,j,k,dp[i][j][k]);
	ld rs=0;for(int i=0;i<=200;i++) for(int j=l;j<=n;j++) rs+=dp[n][i][j];
	return printf("%.10Lf\n",rs),0;
}