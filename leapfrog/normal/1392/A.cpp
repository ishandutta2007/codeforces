#include<bits/stdc++.h>
using namespace std;
int Q,n,a[200005];
int main()
{
	for(scanf("%d",&Q);Q--;)
	{
		scanf("%d",&n);int f=0;
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		for(int i=2;i<=n;i++) if(a[i]!=a[i-1]) {f=1;break;}
		if(f) puts("1");else printf("%d\n",n);
	}
	return 0;
}