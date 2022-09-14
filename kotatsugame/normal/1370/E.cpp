#include<iostream>
using namespace std;
int N;
string s,t;
string now;
main()
{
	cin>>N>>s>>t;
	int dc=0,mc=0,Mc=0;
	for(int i=0;i<N;i++)if(s[i]!=t[i])
	{
		if(s[i]=='0')dc++;
		else dc--;
		if(mc>dc)mc=dc;
		if(Mc<dc)Mc=dc;
	}
	if(dc!=0)
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<Mc-mc<<endl;
}