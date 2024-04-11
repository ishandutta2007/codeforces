#include<iostream>
using namespace std;
int n;string s;
main()
{
	cin>>n>>s;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]>s[i+1])
		{
			cout<<"YES"<<endl;
			cout<<i+1<<" "<<i+2<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
}