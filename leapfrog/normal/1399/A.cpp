#include<bits/stdc++.h>
using namespace std;
int t,n,a[55];
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		sort(a+1,a+n+1);int f=1;
		for(int i=2;i<=n;i++) if(a[i]-a[i-1]>1) f=0;
		if(f) puts("YES");else puts("NO");
	}
	return 0;
}