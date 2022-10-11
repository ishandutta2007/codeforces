#include <iostream>
using namespace std;
#define mod 1000000007
int arr[1000005],z[1000005];
bool det[1000005];
int main()
{
	int n,m;
	string p;
	cin >> n >> m >> p;
	for (int i=0;i<m;i++)
	scanf("%d",&arr[i]);
	z[0]=p.size();
	int l=0,r=0;
	for (int i=1;i<p.size();i++)
	{
		if (i>r)
		{
			l=r=i;
			while (r<p.size() && p[r]==p[r-l])
			r++;
			z[i]=r-l;
			r--;
		}
		else
		{
			int k=i-l;
			if (z[k]<r-i+1)
			z[i]=z[k];
			else
			{
				l=i;
				while (r<p.size() && p[r]==p[r-l])
				r++;
				z[i]=r-l;
				r--;
			}
		}
	}
	if (m)
	{
		for (int i=arr[0];i<arr[0]+p.size();i++)
		det[i]=1;
	}
	for (int i=1;i<m;i++)
	{
		int t=arr[i]-arr[i-1];
		if (t<p.size() && z[t]!=p.size()-t)
		{
			printf("0");
			return 0;
		}
		for (int x=max(arr[i-1]+(int)p.size(),arr[i]);x<arr[i]+p.size();x++)
		det[x]=1;
	}
	long long ans=1;
	for (int i=1;i<=n;i++)
	{
		if (!det[i])
		ans=(ans*26)%mod;
	}
	printf("%I64d",ans);
}