#include<iostream>
using namespace std;
int T,N;
string s[111];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N-2;i++)cin>>s[i];
		string ans=s[0];
		for(int i=1;i<N-2;i++)
		{
			if(ans.back()!=s[i][0])ans+=s[i];
			else ans+=s[i][1];
		}
		if(ans.size()<N)ans+='a';
		cout<<ans<<"\n";
	}
}