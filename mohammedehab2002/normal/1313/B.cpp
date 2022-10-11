#include <bits/stdc++.h>
using namespace std;
int get(int a,int b)
{
	return a+(a>=b);
}
int mx(int n,int x,int y)
{
	if (x>y)
	swap(x,y);
	int st=0,en=y-1;
	while (st!=en)
	{
		int mid=(st+en)/2;
		if (y-1+get(mid+n-y+1,x)<=x+y)
		st=mid+1;
		else
		en=mid;
	}
	return st+1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,x,y;
		scanf("%d%d%d",&n,&x,&y);
		printf("%d %d\n",mx(n,x,y),min(x+y-1,n));
	}
}