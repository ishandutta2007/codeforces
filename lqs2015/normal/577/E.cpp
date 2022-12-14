#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=1000;
struct point
{
	int x,y,id;
	bool operator < (const point &a) const
	{
		if (x!=a.x) return x<a.x;
		if (x%2) return y>a.y;
		return y<a.y;
	}
}p[1111111];
int n;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].x/=mod;
		p[i].id=i;
	}
	sort(p+1,p+n+1);
	for (int i=1;i<=n;i++)
	{
		if (i-1) printf(" ");
		printf("%d",p[i].id);
	}
	return 0;
}