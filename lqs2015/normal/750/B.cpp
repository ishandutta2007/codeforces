#include<iostream>
#include<string>
using namespace std;
int n,l,dist;
string s;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>l>>s;
		if ((!dist && s!="South") || (dist==20000 && s!="North"))
		{
			cout<<"NO"<<endl;
			return 0;
		}
		if (s=="South")
		{
			dist=dist+l;
			if (dist>20000) 
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
		else if (s=="North")
		{
			dist=dist-l;
			if (dist<0) 
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	if (dist!=0) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}