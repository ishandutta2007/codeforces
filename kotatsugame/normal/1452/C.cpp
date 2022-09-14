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
		int A=0,B=0,ans=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='(')A++;
			else if(s[i]=='[')B++;
			else if(s[i]==')')
			{
				if(A>0)ans++,A--;
			}
			else
			{
				if(B>0)ans++,B--;
			}
		}
		cout<<ans<<"\n";
	}
}