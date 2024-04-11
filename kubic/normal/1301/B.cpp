#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define INF 0x3f3f3f3f
int T,n,mn,mx,t,ans,a[N];bool fl;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		mn=INF;ans=mx=-INF;fl=0;scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)
		{
			if(a[i]==-1 && i>1 && a[i-1]!=-1) mn=min(mn,a[i-1]),mx=max(mx,a[i-1]);
			if(a[i]==-1 && i<n && a[i+1]!=-1) mn=min(mn,a[i+1]),mx=max(mx,a[i+1]);
			if(a[i]!=-1) fl=1;if(i>1 && a[i]!=-1 && a[i-1]!=-1) ans=max(ans,abs(a[i]-a[i-1]));
		}if(!fl) puts("0 0");else t=mn+mx>>1,printf("%d %d\n",max(ans,mx-t),t);
	}return 0;
}