#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T,n,m;ll ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;scanf("%d %d",&n,&m);
		for(int i=10;i<=m+1;i*=10) ans+=n;printf("%lld\n",ans);
	}
}