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
int T,n,a[200005],b[200005],le[200005],ri[200005],pos[200005],dp[200005][3],num[200005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),b[i]=a[i];
	memset(dp,0,sizeof(dp)),memset(num,0,sizeof(num));
	sort(b+1,b+n+1);int tot=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
	for(int i=1;i<=n;i++) ri[a[i]]=i,num[a[i]]++;
	for(int i=n;i>=1;i--) le[a[i]]=i,pos[a[i]]=i;
	int mx=1;for(int i=1;i<=n;i++)
	{
		dp[i][0]=dp[pos[a[i]]][0]+1;
		dp[i][1]=max(dp[pos[a[i]]][1]+1,max(dp[pos[a[i]-1]][0],dp[pos[a[i]-1]][2])+1);
		pos[a[i]]=i;if(i==ri[a[i]]) dp[i][2]=dp[le[a[i]]][1]+num[a[i]]-1;
	}
	for(int i=1;i<=n;i++) mx=max(max(mx,dp[i][0]),max(dp[i][1],dp[i][2]));
	printf("%d\n",n-mx);
}
signed main() {for(read(T);T--;) solve();}