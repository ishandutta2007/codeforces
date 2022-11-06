#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long n,k,m;int d;cin>>n>>k>>m>>d;
	long long ans=0;
	for(int i=1;i<=d;i++)
	{
		if(i*k-k+1>n)break;
		long long c=n/(k*(i-1)+1);
		ans=max(ans,min(c,m)*i);
	}
	cout<<ans;return 0;
}