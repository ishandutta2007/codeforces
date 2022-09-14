#include<iostream>
#include<algorithm>
using namespace std;
int T;
string N;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int ans=1e9;
		for(int i=0;i<N.size();i++)for(int j=i+1;j<N.size();j++)
		{
			int now=(N[i]-'0')*10+N[j]-'0';
			if(now%25==0)
			{
				ans=min(ans,(int)N.size()-i-2);
			}
		}
		cout<<ans<<"\n";
	}
}