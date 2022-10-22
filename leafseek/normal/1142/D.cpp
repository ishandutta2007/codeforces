#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=100000+5;
char str[MaxN];
long long dp[MaxN][11];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	register int n;
	cin>>(str+1),n=strlen(str+1);
	register long long Answer=0;
	rep(i,1,n)
	{
		str[i]-='0';
		rep(x,str[i]+1,10)
		{
			const register int y=(((x*(x-1))>>1)+str[i]+10)%11;
			dp[i][y]+=dp[i-1][x];
		}
		if(str[i])
			++dp[i][str[i]];
		rep(x,0,10)
			Answer+=dp[i][x];
	}
	cout<<Answer<<endl;
	return 0;
}