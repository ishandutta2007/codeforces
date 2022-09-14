#include<iostream>
using namespace std;
int Q,N;
string S,T;
main()
{
	cin>>Q;
	for(;Q--;)
	{
		cin>>N>>S>>T;
		int ans=0;
		for(int i=0;i<N;i++)
		{
			if(S[i]!=T[i])ans+=2;
			else
			{
				if(S[i]=='0')
				{
					if(i+1<N&&S[i+1]=='1'&&T[i+1]=='1')
					{
						i++;
						ans+=2;
					}
					else ans+=1;
				}
				else
				{
					if(i+1<N&&S[i+1]=='0'&&T[i+1]=='0')
					{
						i++;
						ans+=2;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
}