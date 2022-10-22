#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct br
{
	int sp;
	int vl;
};
int l,r;
int b[200000];
int q[200000];
br a[200000];
int n,m;
bool operator <(br x,br y)
{
	return x.sp<y.sp;
}
int main()
{
	scanf("%d %d %d",&n,&l,&r);
	for(int i=0;i<n;i++) scanf("%d",&a[i].vl);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i].sp);
		q[i]=a[i].sp;
	}
	sort(a,a+n);
	m=0;
	b[0]=m;
	int g,h;
	g=m;
	h=m;
	for(int i=1;i<n;i++)
	{
		m=m+a[i].vl-a[i-1].vl+1;
		b[i]=m;
		if(m>h) h=m;
		if(m<g) g=m;
	}
	if(h-g<=r-l)
	{
		for(int i=0;i<n;i++) 
		{
			b[i]=b[i]+l-g;
		}
		for(int i=0;i<n;i++)
		{
			printf("%d ",b[q[i]-1]);
		}
	}
	else printf("-1");
	return 0;
}