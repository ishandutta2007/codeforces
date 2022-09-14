#include<iostream>
#include<algorithm>
using namespace std;
int N;
main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int a[3];
		for(int j=0;j<3;j++)cin>>a[j];
		sort(a,a+3);
		if(a[0]+a[1]<a[2])
		{
			cout<<a[0]+a[1]<<endl;
		}
		else
		{
			cout<<(a[0]+a[1]+a[2])/2<<endl;
		}
	}
}