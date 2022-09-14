#include<iostream>
using namespace std;
int T;
string s;
string h="RSP";
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>s;
		int c[3]={0,0,0};
		for(int i=0;i<s.size();i++)
		{
			for(int j=0;j<3;j++)if(h[j]==s[i])c[j]++;
		}
		char K;
		if(c[0]>=c[1]&&c[0]>=c[2])
		{
			K='P';
		}
		else if(c[1]>=c[0]&&c[1]>=c[2])
		{
			K='R';
		}
		else
		{
			K='S';
		}
		string ans(s.size(),K);
		cout<<ans<<endl;
	}
}