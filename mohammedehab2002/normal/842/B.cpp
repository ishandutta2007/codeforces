#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int r,d,n,ans=0;
	scanf("%d%d%d",&r,&d,&n);
	while (n--)
	{
		int x,y,ri;
		scanf("%d%d%d",&x,&y,&ri);
		if (sqrt(x*x+y*y)-ri>=r-d && sqrt(x*x+y*y)<=r-ri)
		ans++;
	}
	printf("%d",ans);
}