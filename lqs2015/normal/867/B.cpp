#include<iostream>
using namespace std;
int n;
int main()
{
	cin>>n;
	if (n==1)
	{
		cout<<1<<" "<<1<<endl;
		cout<<1<<endl;
		return 0;
	}
	cout<<3*(n-1)<<" "<<2<<endl;
	cout<<3<<" "<<1<<endl;
	return 0;
}