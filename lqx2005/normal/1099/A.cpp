#include<bits/stdc++.h>
using namespace std;
int w,h,ua,ha,ub,hb;
int main()
{
	scanf("%d%d%d%d%d%d",&w,&h,&ua,&ha,&ub,&hb);
	int ans=w;
	for(int i=h;i>=1;i--)
	{
		ans+=i;
		if(ha==i) ans-=ua;
		if(hb==i) ans-=ub;
		if(ans<0) ans=0;
	}
	printf("%d\n",ans);
	return 0;
}