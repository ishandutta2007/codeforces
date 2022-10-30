#include<bits/stdc++.h>
using namespace std;
int Q,n,a[500005];
int main()
{
	for(scanf("%d",&Q);Q--;)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		if(a[1]+a[2]<=a[n]) printf("%d %d %d\n",1,2,n);else puts("-1");
	}
	return 0;
}