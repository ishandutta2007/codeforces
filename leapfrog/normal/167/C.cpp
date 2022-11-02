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
/*int dp[105][105];
inline char qry(int x,int y)
{//1:
	if(x==0||y==0) return 1;else if(x>y) swap(x,y);
	char fg=0;if(~dp[x][y]) return dp[x][y];
	fg=fg||qry(x,y%x);if(x==1) fg=fg||qry(x,y-1);
	else for(int p=1;p<=y;p*=x) fg=fg||qry(x,y-p);
	return dp[x][y]=!fg;
}
int main()
{
	memset(dp,-1,sizeof(dp));const int N=20;
	for(int i=1;i<=N;i++,putchar('\n')) for(int j=1;j<=N;j++) printf("%d",qry(i,j));
	for(int i=1;i<=N;i++)
	{
		printf("%d -> ",i);
		for(int j=i;j<=N;j++) if(dp[i][j]) printf("%d ",j);
		putchar('\n');
	}
	return 0;
}*/
inline char qry(ll a,ll b)
{
	if(!a||!b) return 0;else if(a==1||b==1) return 1;else if(a>b) swap(a,b);
	return ((((b/a)%(a+1))&1)==0)||!qry(a,b%a);
}
inline void solve() {ll a,b;read(a,b),puts(qry(a,b)?"First":"Second");}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}