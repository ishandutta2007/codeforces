#include<bits/stdc++.h>
using namespace std;
int test,n,a[111111],flg,cur,nw;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		flg=0;cur=1e9;
		for (int i=1;i<=n;i++)
		{
			nw=min(cur,a[i]);
			if (i>1 && a[i]-nw<a[i-1]-cur) nw=a[i]-a[i-1]+cur;
			if (nw<0) flg=1;
			cur=nw;
		}
		if (flg) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}