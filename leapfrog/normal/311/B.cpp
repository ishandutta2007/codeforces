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
int n,m,q[100005],hd,tl,p,t[100005];long long s[100005],d[100005],dp[105][100005];
inline double slp(int zk,int i,int j) {return 1.0*(dp[zk-1][i]+s[i]-dp[zk-1][j]-s[j])/(i-j);}
int main()
{
	read(n),read(m),read(p),memset(dp,0x3f,sizeof(dp)),dp[0][0]=0;
	for(int i=2;i<=n;i++) read(d[i]),d[i]+=d[i-1];
	for(int i=1,h;i<=m;i++) read(h),read(t[i]),t[i]-=d[h];
	sort(t+1,t+m+1);for(int i=1;i<=m;i++) s[i]=s[i-1]+t[i];
	int st=0;hd=1,tl=0;while(s[st]<0) st++;
	for(int zk=1;zk<=p;zk++,hd=1,tl=0)
	{
		for(int i=0;i<st;i++)
		{
			while(hd<tl&&slp(zk,q[tl-1],q[tl])>=slp(zk,q[tl],i)) --tl;
			q[++tl]=i;
		}
		for(int i=st;i<=m;i++)
		{
			while(hd<tl&&slp(zk,q[hd],q[hd+1])<=t[i]) hd++;
			int j=q[hd];dp[zk][i]=dp[zk-1][j]+1ll*(i-j)*t[i]-s[i]+s[j];
			while(hd<tl&&slp(zk,q[tl-1],q[tl])>=slp(zk,q[tl],i)) --tl;
			q[++tl]=i;
		}
	}
	return printf("%lld\n",dp[p][m]),0;
}