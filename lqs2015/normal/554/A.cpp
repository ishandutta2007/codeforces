#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,int> mp;
string s,str;
int t;
int main()
{
	cin>>s;
	int n=s.size();
	for (int i=0;i<=s.size();i++)
	{
		for (int j=1;j<=26;j++)
		{
			char c=(char) j+96;
			str=s.substr(0,i)+c+s.substr(i);
			if (mp[str]==0)
			{
				mp[str]=++t;
			}
		}
	}
	cout<<t<<endl;
	return 0;
}