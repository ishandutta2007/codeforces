#include<iostream>
using namespace std;
int T;
int N;
string S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>S;
		int c[26]={};
		bool ok=true;
		int prv=-1;
		for(char d:S)
		{
			int now=d-'A';
			if(prv==now);
			else
			{
				if(prv!=-1)c[prv]=2;
				if(c[now]!=0)ok=false;
				c[now]=1;
			}
			prv=now;
		}
		cout<<(ok?"YES":"NO")<<"\n";
	}
}