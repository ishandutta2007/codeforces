#include<iostream>
using namespace std;
int T,N,M,X,Y;
string S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M>>X>>Y;
		if(Y>2*X)Y=2*X;
		int ans=0;
		for(int i=0;i<N;i++)
		{
			cin>>S;
			for(int j=0;j<M;j++)
			{
				if(S[j]=='.')
				{
					if(j+1<S.size()&&S[j+1]=='.')
					{
						ans+=Y;
						j++;
					}
					else
					{
						ans+=X;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}