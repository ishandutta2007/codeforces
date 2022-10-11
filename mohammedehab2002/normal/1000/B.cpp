#include <iostream>
using namespace std;
int n,arr[100005],o[100005],p[100005];
void go(int idx,bool on)
{
	if (idx==n)
	return;
	go(idx+1,!on);
	o[idx]=o[idx+1];
	if (on)
	o[idx]+=arr[idx+1]-arr[idx];
}
int main()
{
	scanf("%d",&n);
	scanf("%d",&arr[n]);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	go(0,1);
	p[0]=arr[0];
	for (int i=1;i<=n;i++)
	{
		p[i]=p[i-1];
		if (i%2==0)
		p[i]+=arr[i]-arr[i-1];
	}
	int ans=p[n];
	for (int i=0;i<n;i++)
	{
		if (!i)
		{
			if (arr[i]==1 && arr[i+1]==arr[i]+1)
			continue;
		}
		else if (arr[i+1]==arr[i]+1 && arr[i-1]==arr[i]-1)
		continue;
		if (i%2==0)
		ans=max(ans,p[i]+o[i+1]+arr[i+1]-arr[i]-1);
	}
	printf("%d",ans);
}