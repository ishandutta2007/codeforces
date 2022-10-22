#include<bits/stdc++.h>
using namespace std;
long long f[200008];
long long a[200008];
int main()
{
	long long n,A,all=0;
	cin>>n>>A;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		all=all+a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long ans=A-(n-1),tmp=A-(all-a[i]),l,r;
		if(ans>=a[i])
		{
			r=a[i];
		}
		else
		{
			r=ans;
		}
		if(tmp<=0)
		{
			l=1;
		}
		else
		{
			l=tmp;
		}
		f[i]=r-l+1;
	}
	for(long long i=1;i<=n;i++)
	{
		cout<<a[i]-f[i]<<" ";
	}
	cout<<endl;
	return 0;
}