#include<iostream>
using namespace std;
string s;
main()
{
	cin>>s;
	for(int i=1;i<s.size();i++)
	{
		string t=s.substr(i)+s.substr(0,i);
		bool ok=s!=t;
		if(!ok)continue;
		for(int j=0;j<s.size();j++)
		{
			if(t[j]!=t[t.size()-j-1])
			{
				ok=false;
				break;
			}
		}
		if(ok)
		{
			puts("1");
			return 0;
		}
	}
	int id=0;
	while(id<s.size()&&s[id]==s[0])id++;
	int N=s.size();
	if(N/2<=id)
	{
		puts("Impossible");
	}
	else
	{
		puts("2");
	}
}