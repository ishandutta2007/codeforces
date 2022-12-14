#include<iostream>
#include<cmath>
using namespace std;
double n,a,mn,mni,an,man;
int main()
{
	cin>>n>>a;
	mn=1e18;
	an=180-360/n;man=an/(n-2);
	for (int i=1;i<=n-2;i++)
	{
		if (abs(an-a)<mn) 
		{
			mn=abs(an-a);
			mni=i+2;
		}
		an-=man;
	}
	cout<<"1 2 "<<mni<<endl;
	return 0; 
}