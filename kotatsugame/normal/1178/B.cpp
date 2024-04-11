#include<iostream>
using namespace std;
string s;
long long L[1<<20],R[1<<20];
main()
{
	cin>>s;
	for(int i=1;i<s.size();i++)
	{
		L[i+1]=L[i]+(s[i]=='v'&&s[i-1]=='v');
	}
	for(int i=s.size()-1;i>=0;i--)
	{
		R[i]=R[i+1]+(s[i]=='v'&&s[i+1]=='v');
	}
	long long ans=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='o')
		{
			ans+=L[i]*R[i+1];
		}
	}
	cout<<ans<<endl;
}