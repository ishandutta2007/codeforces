#include<bits/stdc++.h>
using namespace std;
long long a[1000000];             
int main()
{
	long long n,k,ans,now=1;
	cin>>n>>k;
	ans=k;
	for(long long i=1;i<=k+1;i++)
	{
		a[i]=now;
		if(i%2==1)
		{
			now=now+ans;
		}
		else
		{
			now=now-ans;
		}
		ans--;
	}
	for(long long i=k+2;i<=n;i++)
	{
		a[i]=i;
	}
	for(long long i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}