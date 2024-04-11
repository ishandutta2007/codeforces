#include <bits/stdc++.h>
using namespace std;
int n,a[200005],f[200005],K;
signed main()
{
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+1+n);
	if(!K)
	{
		if(a[1]==1) puts("-1");
		else printf("%d\n",a[1]-1);
		return 0;
	}
	int zk=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1]) continue;
		zk=i-1;
		if(zk==K) { printf("%d\n",a[zk]); return 0; }
	}
	zk=n;
	if(zk==K) { printf("%d\n",a[zk]); return 0; }
	puts("-1");
	return 0;
}