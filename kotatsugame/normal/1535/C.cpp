#include<iostream>
#include<algorithm>
using namespace std;
int T;
string S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>S;
		int id[2][2]={};
		long long ans=0;
		int cnt=0;
		for(int i=0;i<S.size();i++)
		{
			if(S[i]!='?')
			{
				id[i%2][S[i]-'0']=i+1;
				cnt=0;
			}
			else cnt++;
			ans-=cnt;
			ans+=i+1-max(id[0][0],id[1][1]);
			ans+=i+1-max(id[1][0],id[0][1]);
		}
		cout<<ans<<"\n";
	}
}