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
int n,dp[65][100005],id[100005],now,s[2][100005];long long a[100005];
inline char cmp(int x,int y) {return (a[x]&((1ll<<now)-1))<(a[y]&((1ll<<now)-1));}
signed main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);for(int i=1;i<=n;i++) a[i]=a[n]-a[i],id[i]=i;
	memset(dp,0x3f,sizeof(dp)),dp[0][0]=0;
	for(now=0;now<=60;now++)
	{
		sort(id+1,id+n+1,cmp);
		for(int i=1;i<=n;i++) s[0][i]=s[0][i-1],s[1][i]=s[1][i-1],s[(a[id[i]]>>now)&1][i]++;
		for(int i=0;i<=n;i++)
		{
			int qwq,qaq;
			qwq=s[1][n-i]+s[0][n]-s[0][n-i],qaq=s[1][n]-s[1][n-i];
			dp[now+1][qaq]=min(dp[now+1][qaq],dp[now][i]+qwq);
			qwq=s[0][n-i]+s[1][n]-s[1][n-i],qaq=n-s[0][n-i];
			dp[now+1][qaq]=min(dp[now+1][qaq],dp[now][i]+qwq);
		}
	}
	return printf("%d\n",dp[61][0]),0;
}