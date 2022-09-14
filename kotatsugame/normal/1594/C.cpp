#include<iostream>
using namespace std;
int T;
main()
{
	cin>>T;
	for(;T--;)
	{
		int N;
		char c;
		string S;
		cin>>N>>c>>S;
		bool ok=true;
		for(char d:S)if(d!=c)ok=false;
		if(ok)
		{
			cout<<"0\n";
			continue;
		}
		int id=-1;
		for(int k=2;k<=N;k++)
		{
			bool now=true;
			for(int i=k;i<=N;i+=k)if(S[i-1]!=c)
			{
				now=false;
				break;
			}
			if(now)
			{
				ok=true;
				id=k;
				break;
			}
		}
		if(ok)
		{
			cout<<"1\n"<<id<<"\n";
		}
		else
		{
			cout<<"2\n"<<N-1<<" "<<N<<"\n";
		}
	}
}