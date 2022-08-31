#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	if (n<=2) puts("-1");
	else
	{
		for (int i=1;i<=n;++i)
			cout<<n-i+1<<" ";
	}
	return 0;
}