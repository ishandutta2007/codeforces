#include<iostream>
using namespace std;
int T;
string s;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>s;
		long long ans=s.size();
		int id=0,now=0,mn=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='+')now++;
			else now--;
			if(mn>now)
			{
				mn=now;
				ans+=i+1;
			}
		}
		cout<<ans<<endl;
	}
}