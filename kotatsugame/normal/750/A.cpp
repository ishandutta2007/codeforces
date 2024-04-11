#include<iostream>
using namespace std;
main()
{
	int n,k;cin>>n>>k;
	k=240-k;
	int i;
	for(i=1;i<=n;i++)
	{
		if(k-i*5<0)
		{
			cout<<i-1<<endl;
			return 0;
		}
		k-=i*5;
	}
	cout<<n<<endl;
}