#include<iostream>

using namespace std;

int calc(int a,int b)
{
	return (!b)?0:calc(b,a%b)+a/b;
}

int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		int a,b;
		cin>>a>>b;
		cout<<calc(a,b)<<endl;
	}
	return 0;
}