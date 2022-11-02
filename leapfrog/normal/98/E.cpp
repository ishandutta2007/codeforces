//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m;double dp[1005][1005];
inline double dfs(int n,int m)
{
	if(!m) return 1;else if(!n) return 1.0/(m+1);else if(dp[n][m]>0) return dp[n][m];
	double A=1.0*m/(m+1)*(1-dfs(m-1,n)),B=1,C=A+1.0/(m+1),D=1-dfs(m,n-1),P=(D-B)/(A+D-B-C);
	return dp[n][m]=P*A+(1-P)*B;
}
int main() {return read(n),read(m),printf("%.10lf %.10lf\n",dfs(n,m),1-dfs(n,m)),0;}