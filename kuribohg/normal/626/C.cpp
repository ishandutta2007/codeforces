#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int x,y,l=1,r=1000000000;
int main()
{
	scanf("%d%d",&x,&y);
	while(l<r)
	{
		int mid=(l+r)>>1;
		int p=mid/2,q=mid/3,k=mid/6;
		p-=k,q-=k;
		int xx=x,yy=y;
		xx-=p,yy-=q;
		xx=max(xx,0),yy=max(yy,0);
		if(xx+yy<=k) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}