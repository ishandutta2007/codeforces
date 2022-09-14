#include<iostream>
using namespace std;
string s;
main()
{
	int ans=0;
	cin>>s;
	for(int k=0;;k+=25)
	{
		string t=to_string(k);
		if(s.size()<t.size())break;
		if(s.size()>t.size())continue;
		char x='-';
		bool ok=true;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='_');
			else if(s[i]=='X')
			{
				if(x=='-')x=t[i];
				else if(x!=t[i])
				{
					ok=false;
					break;
				}
			}
			else if(s[i]!=t[i])
			{
				ok=false;
				break;
			}
		}
		if(ok)ans++;
	}
	cout<<ans<<endl;
}