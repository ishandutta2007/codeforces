#include<bits/stdc++.h>
#define int long long
using namespace std;
int res,t,n,s[100005],a[100005],b[1000005<<1];const int dx=1000005;
signed main()
{
	for(s[0]=0,scanf("%lld",&t);t--;)
	{
		scanf("%lld",&n),memset(b,0,sizeof(b)),memset(s,0,sizeof(s)),b[0+dx]=1,res=0;
		for(int i=1;i<=n;i++) scanf("%1lld",a+i),a[i]--;
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
//		for(int i=1;i<=n;i++) printf("%lld%c",s[i],i==n?'\n':' ');
		for(int i=1;i<=n;i++) res+=b[s[i]+dx],b[s[i]+dx]++;
		printf("%lld\n",res);
	}
	return 0;
}