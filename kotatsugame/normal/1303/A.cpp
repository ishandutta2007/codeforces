#include<iostream>
using namespace std;
int T;
main()
{
	cin>>T;
	for(;T--;)
	{
		string s;cin>>s;
		int ans=0;
		int pre=0;
		bool fd=false;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='0')pre++;
			else
			{
				if(fd)ans+=pre;
				fd=true;
				pre=0;
			}
		}
		cout<<ans<<endl;
	}
}