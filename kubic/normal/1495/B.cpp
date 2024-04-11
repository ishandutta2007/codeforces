#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,ans,a[N],pr1[N],sf1[N],pr2[N],sf2[N];
int prMx[N],sfMx[N];bool tg[N];
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		if(a[i]>a[i-1]) pr1[i]=pr1[i-1]+1,pr2[i]=1;
		else pr1[i]=1,pr2[i]=pr2[i-1]+1;
	}
	for(int i=n;i;--i)
	{
		if(a[i]>a[i+1]) sf1[i]=sf1[i+1]+1,sf2[i]=1;
		else sf1[i]=1,sf2[i]=sf2[i+1]+1;
	}
	for(int i=1;i<=n;++i)
	{
		prMx[i]=max(prMx[i-1],max(pr2[i],sf2[i]));
		if(prMx[i-pr1[i]]>=max(pr1[i],sf1[i])) tg[i]=1;
		if(pr1[i]/2*2>=sf1[i] || sf1[i]/2*2>=pr1[i]) tg[i]=1;
		if(pr2[i-pr1[i]+1]>=max(pr1[i],sf1[i])) tg[i]=1;
		if(sf2[i+sf1[i]-1]>=max(pr1[i],sf1[i])) tg[i]=1;
	}
	for(int i=n;i;--i)
	{
		sfMx[i]=max(sfMx[i+1],max(pr2[i],sf2[i]));
		if(sfMx[i+sf1[i]]>=max(pr1[i],sf1[i])) tg[i]=1;
		ans+=tg[i]^1;
	}printf("%d\n",ans);return 0; 
}