#include <bits/stdc++.h>
using namespace std;
int T,n,ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;scanf("%d",&n);ans=(1<<n);
		for(int i=1;i<(n>>1);++i) ans+=(1<<i);
		for(int i=(n>>1);i<n;++i) ans-=(1<<i);
		printf("%d\n",ans);
	}return 0;
}