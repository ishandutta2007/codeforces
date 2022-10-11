#include <iostream>
#include <algorithm>
using namespace std;
int k,p[100005];
void solve(int l,int r)
{
	if (l+1==r)
	return;
	int mid=(l+r)/2;
	if (k>0)
	{
		swap(p[mid-1],p[mid]);
		k-=2;
		solve(l,mid);
		solve(mid,r);
	}
}
int main()
{
	int n;
	scanf("%d%d",&n,&k);
	k--;
	for (int i=0;i<n;i++)
	p[i]=i+1;
	solve(0,n);
	if (k)
	{
		printf("-1");
		return 0;
	}
	for (int i=0;i<n;i++)
	printf("%d ",p[i]);
}