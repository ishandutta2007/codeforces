#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int n,sum=0;
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		sum+=x;
	}
	if (sum%n==0)
		cout<<n<<endl;
	else
		cout<<n-1<<endl;
	return 0;
}