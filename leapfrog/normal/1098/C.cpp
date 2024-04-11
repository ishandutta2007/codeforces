#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,l,r,si[1000005],d[1000005];
inline char ck(int x)
{
	int t=1,num=k-n,dep=0;memset(si,0,sizeof(si)),memset(d,0,sizeof(d));
	for(int i=2;i<=n;) {t*=x,dep++;for(int j=1;j<=t&&i<=n;j++,i++) si[dep]++,d[i]=dep,num-=dep;}
	if(num<0) return 0;
	for(int j=n;num;)
	{
		if(si[d[j]]==1) j--;
		dep++,t=min(num,dep-d[j]),si[d[j]]--,d[j]+=t,si[d[j]]++,num-=t,j--;
	}
	return 1;
}
signed main()
{
	scanf("%lld%lld",&n,&k),l=1,r=n;
	if(k<((n<<1)-1)||k>(n*(n+1)/2)) return puts("No"),0;
	while(l<r) {int mid=(l+r)>>1;if(ck(mid)) r=mid;else l=mid+1;}
	ck(r),puts("Yes");int w=1;
	d[w]=0,sort(d+2,d+n+1),memset(si,0,sizeof(si));
	for(int i=2;i<=n;i++)
	{
		while(d[w]!=d[i]-1||si[w]==r) w++;
		printf("%lld ",w),si[w]++;
	}
	return 0;
}