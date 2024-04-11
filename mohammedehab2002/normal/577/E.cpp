#include <iostream>
#include <algorithm>
using namespace std;
int p[1000005],x[1000005],y[1000005];
bool cmp(int a,int b)
{
	if (x[a]/1000==x[b]/1000)
	return ((y[a]<y[b])^((x[a]/1000)%2));
	return (x[a]<x[b]);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		p[i]=i;
	}
	sort(p,p+n,cmp);
	for (int i=0;i<n;i++)
	printf("%d ",p[i]+1);
}