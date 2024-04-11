#include<iostream>

using namespace std;

int main()
{
	int n;
	int b=0,c=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		if(t<0)c+=t;
		else   b+=t;
	}
	cout<<b-c<<endl;
	return 0;
}