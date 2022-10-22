#include <bits/stdc++.h>
using namespace std;
#define N 105
int T,n,s,ans,a[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		s=ans=0;scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),s+=a[i];
		for(int i=1;i<=n;++i) if(!a[i]) ++s,++ans,a[i]=1;
		if(!s) ++ans;printf("%d\n",ans);
	}return 0;
}