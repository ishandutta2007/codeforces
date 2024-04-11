#include <iostream>
using namespace std;
int main()
{
	int n,mnx=(1<<30),mny=(1<<30),mxx=-(1<<30),mxy=-(1<<30);
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		mnx=min(mnx,x);
		mny=min(mny,y);
	}
	for (int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		mxx=max(mxx,x);
		mxy=max(mxy,y);
	}
	printf("%d %d",mnx+mxx,mny+mxy);
}