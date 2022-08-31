#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int ans=0;
	for (int i=1;i<=n;++i)
	{
		int sum=0;
		for (int p=0;p<3;++p)
		{
			int x;
			cin>>x;
			sum+=x;
		}
		if (sum>=2) ++ans;
	}
	cout<<ans<<endl;
	return 0;
}