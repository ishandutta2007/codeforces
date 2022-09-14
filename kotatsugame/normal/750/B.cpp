#include<iostream>
using namespace std;
main()
{
	int n;cin>>n;
	int a=0;
	int k;
	bool fn=true;
	bool fs=false;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>k>>s;
		if(fn&&s!="South")
		{
			cout<<"NO"<<endl;
			return 0;
		}
		if(fs&&s!="North")
		{
			cout<<"NO"<<endl;
			return 0;
		}
		if(s=="South")a+=k;
		else if(s=="North")a-=k;
		fn=fs=false;
		if(a==0)
		{
			fn=true;
		}
		else if(a==20000)
		{
			fs=true;
		}
		else if(a<0||a>20000)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	if(a!=0)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	else
	{
		cout<<"YES"<<endl;
		return 0;
	}
}