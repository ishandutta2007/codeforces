#include<cstdio>
#include<algorithm>
using std::swap;
using std::greater;
using std::sort;
inline int read()
{
	int res=0,f=0;
	char x;
	while((x=getchar())<'0'||x>'9')
		f|=x=='-';
	for(;x>='0'&&x<='9';x=getchar())
		res=res*10+x-'0';
	return f?-res:res;
}
const int N=1e4+5,inf=0x3f3f3f3f;
int n,h,l,r,ans;
int atot,btot;
int a[N],b[N],c[N];
int dp[N];
signed main()
{
	register int i,j;
	n=read();l=read();r=read();
	for(i=1;i<=n;i++)
		h+=(c[i]=read());
	swap(l,r);l=h-l;r=h-r;
	for(i=1;i<=n;i++)
		(read()?b[++btot]:a[++atot])=c[i];
	for(i=1;i<=h;i++)
		dp[i]=-inf;
	for(i=1;i<=atot;i++)
		for(j=h;j>=a[i];j--)
			if(dp[j-a[i]]>dp[j])
				dp[j]=dp[j-a[i]];
	sort(b+1,b+btot+1,greater<int>());
	for(i=1;i<=btot;i++)
		for(j=h;j>=b[i];j--)
			if(dp[j-b[i]]+(j>=l&&j<=r)>dp[j])
				dp[j]=dp[j-b[i]]+(j>=l&&j<=r);
	for(i=0;i<=h;i++)
		if(dp[i]>ans)
			ans=dp[i];
	printf("%d\n",ans);
	return 0;
}