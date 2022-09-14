#include<iostream>
using namespace std;
int n,b,p;
main()
{
	cin>>n>>b>>p;
	int y=n*p;
	int x=0;
	while(n>1)
	{
		int k=0;
		while(1<<k+1<=n)k++;
		k=1<<k;
		x+=k*b+k/2;
		n=n-k+k/2;
	}
	cout<<x<<" "<<y<<endl;
}