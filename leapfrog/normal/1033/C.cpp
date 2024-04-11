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
int n,a[100005],dp[100005];pair<int,int>p[100005];
int main()
{
	read(n),memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++) read(a[i]),p[i]=make_pair(a[i],i);
	sort(p+1,p+n+1,greater<pair<int,int> >());
	for(int i=1;i<=n;i++)
	{
		int id=p[i].second;dp[id]=0;
		for(int j=id%a[id];j<=n;j+=a[id]) if(j!=id&&!dp[j]) {dp[id]=1;break;}
	}
	for(int i=1;i<=n;i++) putchar(66-dp[i]);
	return putchar('\n'),0;
}