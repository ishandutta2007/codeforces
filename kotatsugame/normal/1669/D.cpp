#include<iostream>
using namespace std;
int T,N;
string S;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>S;
		bool f=true;
		for(int i=0;i<N;)
		{
			if(S[i]=='W')i++;
			else
			{
				bool b=false,r=false;
				while(i<N&&S[i]!='W')
				{
					if(S[i]=='B')b=true;
					else r=true;
					i++;
				}
				if(!(b&&r))f=false;
			}
		}
		cout<<(f?"YES\n":"NO\n");
	}
}