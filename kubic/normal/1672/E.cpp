#include <bits/stdc++.h>
using namespace std;
int n,l,r,ans;
int qry(int x)
{	
	if(x<1) return 0;
	int res;printf("? %d\n",x);
	fflush(stdout);scanf("%d",&res);return res;
}
int main()
{
	scanf("%d",&n);l=1;r=5e6;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(qry(mid)==1) r=mid-1;else l=mid+1;
	}ans=l;
	for(int i=2,t;i<=n;++i)
	{
		t=qry((l-1)/i);
		if(t) ans=min(ans,(l-1)/i*t);
	}printf("! %d\n",ans);fflush(stdout);return 0;
}