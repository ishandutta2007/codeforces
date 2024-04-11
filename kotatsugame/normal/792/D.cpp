#include<iostream>
using namespace std;
long long N;
int Q;
main()
{
	cin>>N>>Q;
	for(;Q--;)
	{
		long long u;
		string s;
		cin>>u>>s;
		for(char c:s)
		{
			long long i=u&-u;
			if(c=='L')
			{
				if(i>=2)u-=i/2;
			}
			else if(c=='R')
			{
				if(i>=2)u+=i/2;
			}
			else
			{
				if(u&2*i)u-=i;
				else u+=i;
				if(u>N)u-=i;
			}
		}
		cout<<u<<"\n";
	}
}