#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,int> mp;
string s,s1;
int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		if (mp[s]==0) 
		{
			mp[s]++;
			cout<<"OK"<<endl;
		}
		else
		{
			cout<<s<<mp[s]<<endl;
			mp[s]++;
		}
	}
	return 0;
}