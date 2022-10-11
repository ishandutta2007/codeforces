#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define mod 998244353
long long arr[505];
int n,e[]={0,0,2000000000,2000000,50000};
map<long long,int> cnt;
bool d[505];
long long pow(int m,int r)
{
	long long ans=1;
	while (r--)
	ans*=m;
	return ans;
}
int root(long long x,int r)
{
	int st=0,en=e[r];
	while (st!=en)
	{
		int mid=st+(en-st)/2;
		if (pow(mid,r)<x)
		st=mid+1;
		else
		en=mid;
	}
	if (pow(st,r)==x)
	return st;
	return 1;
}
void go(long long p)
{
	if (p==1)
	return;
	for (int i=0;i<n;i++)
	{
		while (arr[i]%p==0)
		{
			d[i]=1;
			arr[i]/=p;
			cnt[p]++;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%I64d",&arr[i]);
	for (int i=0;i<n;i++)
	{
		for (int x=4;x>=2;x--)
		go(root(arr[i],x));
	}
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<n;x++)
		{
			if (arr[i]!=arr[x])
			go(__gcd(arr[i],arr[x]));
		}
	}
	for (int i=0;i<n;i++)
	{
		if (d[i])
		go(arr[i]);
	}
	long long ans=1;
	for (int i=0;i<n;i++)
	{
		if (!d[i])
		{
			int c=2;
			for (int x=i+1;x<n;x++)
			{
				if (arr[i]==arr[x])
				{
					c++;
					arr[x]=1;
					d[x]=1;
				}
			}
			ans=(ans*c*c)%mod;
		}
	}
	for (auto p:cnt)
	ans=(ans*(p.second+1))%mod;
	printf("%I64d\n",ans);
	fflush(stdout);
}