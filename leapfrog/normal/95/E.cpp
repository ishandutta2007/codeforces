//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,m,fa[100005],sz[100005],cn[100005],dp[100005];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) fa[x]=y;}
inline char chk(int x) {for(;x;x/=10) if(x%10!=4&&x%10!=7) return 0;return 1;}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,x,y;i<=m;i++) read(x),read(y),mrg(x,y);
	memset(dp,0x3f,sizeof(dp));for(int i=1;i<=n;i++) sz[getf(i)]++;
	dp[0]=0;for(int i=1;i<=n;i++) if(getf(i)==i) cn[sz[i]]++;
	for(int i=1;i<=n;i++) if(cn[i])
	{
		int to=cn[i];for(int p=1;to;p<<=1)
		{
			p=min(p,to),to-=p;int vl=p*i;
			for(int j=n;j>=vl;j--) dp[j]=min(dp[j],dp[j-vl]+p);
		}
	}
	int rs=1e9;for(int i=1;i<=n;i++) if(chk(i)) rs=min(rs,dp[i]);
	return printf("%d\n",rs>=1e9?-1:rs-1),0;
}