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
		string ans;
		for(int len=1;;len++)
		{
			int lim=1;
			for(int i=0;i<len;i++)lim*=26;
			for(int t=0;t<lim;t++)
			{
				string now(len,'a');
				{
					int u=t;
					for(int i=0;i<len;i++)now[len-i-1]=u%26+'a',u/=26;
				}
				bool fn=false;
				for(int i=0;i+len<=N;i++)
				{
					if(S.substr(i,len)==now)
					{
						fn=true;
						break;
					}
				}
				if(!fn)
				{
					ans=now;
					break;
				}
			}
			if(!ans.empty())break;
		}
		cout<<ans<<endl;
	}
}