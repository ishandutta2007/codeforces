#include<iostream>
#include<cstdio>
using namespace std;
int n,ans;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i*=2)
	{
		ans++;
		n-=i;
	}
	if (n!=0) 
	{
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}