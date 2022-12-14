#include<iostream>
using namespace std;
int n,k,tim,ans;
int main()
{
	cin>>n>>k;
	tim=240-k;
	for (ans=1;ans<=n;ans++)
	{
		tim-=ans*5;
		if (tim<0) break;
	}
	cout<<ans-1<<endl;
	return 0;
}