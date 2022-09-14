#include<iostream>
using namespace std;
int f(long long X)
{
	X=(X%360+360)%360;
	if(X>=180)X=360-X;
	return X;
}
main()
{
	long long X;cin>>X;
	int ans=f(X),ansc=0;
	for(int i=1;i<=4;i++)
	{
		X-=90;
		if(ans>f(X))
		{
			ans=f(X);
			ansc=i;
		}
	}
	cout<<ansc<<endl;
}