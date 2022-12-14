#include<iostream>
using namespace std;
int t,s,q,ans;
int main()
{
	cin>>t>>s>>q;
	while(s<t)
	{
		s=s+s*(q-1);
		ans++; 
	}
	cout<<ans<<endl;
	return 0;
}