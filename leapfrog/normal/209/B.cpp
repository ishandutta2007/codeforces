//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
long long a,b,c;//dp[105][105][105];
// inline int dfs(int a,int b,int c)
// {
// 	if(dp[a][b][c]) return dp[a][b][c];
// 	if(!a+!b+!c==2) return 0;else dp[a][b][c]=1e9;
// 	if(a&&b) dp[a][b][c]=min(dp[a][b][c],dfs(a-1,b-1,c+1));
// 	if(a&&c) dp[a][b][c]=min(dp[a][b][c],dfs(a-1,b+1,c-1));
// 	if(b&&c) dp[a][b][c]=min(dp[a][b][c],dfs(a+1,b-1,c-1));
// 	return ++dp[a][b][c];
// }
// inline void paint(int a,int b,int c)
// {
// 	printf("%d , %d , %d\n",a,b,c);
// 	if(a&&b&&dp[a][b][c]==dp[a-1][b-1][c+1]+1) paint(a-1,b-1,c+1);
// 	else if(b&&c&&dp[a][b][c]==dp[a+1][b-1][c-1]+1) paint(a+1,b-1,c-1);
// 	else if(a&&c) paint(a-1,b+1,c-1);
// }
int main()
{
	read(a),read(b),read(c);
	if((a&1)==(b&1)&&(b&1)==(c&1)) return printf("%lld\n",a+b+c-max(a,max(b,c))-min(a,min(b,c))),0;
	if((a&1)==(b&1)) printf("%lld\n",max(a,b));else if((a&1)==(c&1)) printf("%lld\n",max(a,c));else printf("%lld\n",max(b,c));
	return 0;
	// printf("%d\n",dfs(a,b,c));
	// return paint(a,b,c),0;
}