#include<iostream>
using namespace std;
long long n,a[5555];
long long doit(long long b,long long e,long long y)
{
	if (b>e) return 0;
	long long mn=2e9,mni;
	for (long long i=b;i<=e;i++)
	{
		if (a[i]<mn) 
		{
			mn=a[i];
			mni=i;
		}
	}
	return min(e-b+1,doit(b,mni-1,mn)+doit(mni+1,e,mn)+mn-y);
}
int main()
{
	cin>>n;
	for (long long i=1;i<=n;i++) cin>>a[i];
	cout<<doit(1,n,0);
	return 0;
}