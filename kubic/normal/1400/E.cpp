#include <bits/stdc++.h>
using namespace std;
#define N 10005
int n,ans,cntD,a[N],ds[N],dp[N],s[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {scanf("%d",&a[i]);if(a[i]) ds[++cntD]=a[i];}
	sort(ds+1,ds+cntD+1);cntD=unique(ds+1,ds+cntD+1)-ds-1;
	for(int i=cntD-1;i>=0;--i)
	{
		int ps=0,cnt=0,d=ds[i+1]-ds[i];
		for(int j=1;j<=n;++j)
		{
			s[j]=0;
			if(a[j]>ds[i])
			{
				if(a[j-1]<=ds[i]) ps=j,cnt=0;++cnt;s[ps]+=dp[j];dp[j]=0;
				if(a[j+1]<=ds[i]) dp[ps]=min(s[ps]+d,cnt);
			}
		}
	}for(int i=1;i<=n;++i) ans+=dp[i];printf("%d\n",ans);return 0;
}