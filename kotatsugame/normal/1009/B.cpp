#include<iostream>
#include<algorithm>
using namespace std;
string s;
main()
{
	cin>>s;
	string t="";
	int cnt=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')cnt++;
		else t+=s[i];
	}
	for(int j=0;j<t.size();j++)
	{
		if(t[j]=='2')
		{
			while(cnt)cout<<'1',cnt--;
		}
		cout<<t[j];
	}
	while(cnt)cout<<'1',cnt--;
	cout<<endl;
}