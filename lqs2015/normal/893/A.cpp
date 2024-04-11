#include<iostream>
using namespace std;
int n,x,a,b,c;
int main()
{
	cin>>n;
	a=1;b=2;c=3;
	while(n--)
	{
		cin>>x;
		if (x==c)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		else
		{
			if (a==x) swap(b,c);
			else swap(a,c);
		}
	}
	cout<<"YES"<<endl;
	return 0;
}