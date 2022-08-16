#include<cstdio>
#include<iostream>

using namespace std;

int n,m;

bool check(int x)
{
	long long p=(long long)x*m;
	long long now=n-1;
	long long v=1;
	for (int i=1;i<=x;++i)
	{
		long double a=(long double)v*(x-i+1)/i;
		long double b=p/i;
		long double c=min(a,b);
		now-=(long long)c;
		p-=(long long)c*i;
		if (now<=0) return true;
		if (p<i) break;
		v=(long long)a;
	}
	return false;
}

int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		int L=0,R=n-1,ans=n-1;
		while (L<=R)
		{
			int mid=(L+R)>>1;
			if (check(mid))
			{
				ans=mid;
				R=mid-1;
			}
			else
				L=mid+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}