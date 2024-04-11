#include<iostream>
using namespace std;
int T;
main()
{
	cin>>T;
	for(;T--;)
	{
		long long X;cin>>X;
		bool flag=false;
		for(int i=1;i<=6;i++)
		{
			long long Y=X-(21-i);
			if(Y>=0&&Y%14==0)flag=true;
		}
		cout<<(flag?"YES":"NO")<<endl;
	}
}