#include <bits/stdc++.h>
using namespace std;
int T,n,x,y,t,a,b,d,ans;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&x,&y);
		ans=0;
		t=max(x+y-n,0);a=n-y;b=n-x;
		if(t<x-1) ans+=(d=min(x-t-1,a)),a-=d;
		if(t<y-1) ans+=(d=min(y-t-1,b)),b-=d;
		ans+=min(a,b);
		printf("%d ",n-ans);
		ans=0;
		t=min(x+y-1,n);a=y-1;b=x-1;
		if(x<t) ans+=(d=min(t-x,a)),a-=d;
		if(y<t) ans+=(d=min(t-y,b)),b-=d;
		ans+=min(a,b);
		printf("%d\n",ans+1); 
	}return 0;
}