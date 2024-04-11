#include<iostream>
using namespace std;
int T,N;
string S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>S;
		string ans(N,'-');
		bool fu=false,fd=false;
		for(int i=0;i<N;i++)
		{
			if(S[i]=='U')fu=true;
			if(S[i]=='D')fd=true;
		}
		if(fd)
		{
			for(int i=0;i<N;i++)
			{
				if(S[i]=='L')
				{
					ans[i]='L';
					ans[i+1]='R';
					i++;
				}
				else ans[i]='U';
			}
		}
		else
		{
			for(int i=0;i<N;i++)
			{
				if(S[i]=='L')
				{
					ans[i]='L';
					ans[i+1]='R';
					i++;
				}
				else ans[i]='D';
			}
		}
		cout<<ans<<"\n";
	}
}