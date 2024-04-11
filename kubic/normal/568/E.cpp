#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,m,a[N],b[N],dp1[N],dp2[N],dp3[N],dp4[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),dp3[i]=1e9;
	scanf("%d",&m);a[++n]=1e9;dp3[n]=1e9;
	for(int i=1;i<=m;++i) scanf("%d",&b[i]);sort(b+1,b+m+1);
	for(int i=1;i<=n;++i)
		if(~a[i])
		{
			int t=lower_bound(dp3+1,dp3+n+1,a[i])-dp3-1;
			dp1[i]=t+1;dp2[i]=dp4[t];dp3[t+1]=a[i];dp4[t+1]=i;
		}else for(int j=m,t=n;j;--j)
		{while(t && dp3[t]>=b[j]) --t;dp3[t+1]=b[j];dp4[t+1]=i;}
	for(int i=n,len=dp1[n],nw=1e9;len;--len)
		if(~a[i]) nw=a[i],i=dp2[i];
		else
		{
			int t=0;
			for(int j=m;j;--j)
				if(~b[j] && b[j]<nw) {nw=a[i]=b[j];b[j]=-1;break;}
			for(int j=i-1;j;--j)
				if(~a[j] && dp1[j]==len-1 && a[j]<nw) {t=j;break;}
			if(!t) for(int j=i-1;j;--j) if(a[j]==-1) {t=j;break;}i=t;
		}
	for(int i=1;i<n;++i)
	{
		if(a[i]==-1) for(int j=m;j;--j)
			if(~b[j]) {a[i]=b[j];b[j]=-1;break;}printf("%d ",a[i]);
	}return 0;
}