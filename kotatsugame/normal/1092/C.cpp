#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
string S[200];
main()
{
	cin>>N;
	int s=-1,t;
	for(int i=0;i<2*N-2;i++)
	{
		cin>>S[i];
		if(S[i].size()==N-1)
		{
			if(s==-1)s=i;
			else t=i;
		}
	}
	string ans="";
	for(int r=0;r<2;r++)
	{
		if(S[s].substr(1)==S[t].substr(0,N-2))
		{
			string now=S[s];
			now+=S[t][N-2];
			vector<int>usd(N,0);
			bool ok=true;
			string ret(2*N-2,'0');
			ret[s]='P';
			ret[t]='S';
			for(int i=0;i<2*N-2;i++)if(ret[i]=='0')
			{
				bool p=false,s=false;
				int n=S[i].size();
				if(now.substr(0,n)==S[i])p=true;
				if(now.substr(N-n)==S[i])s=true;
				if(usd[n]==0)
				{
					if(p)
					{
						ret[i]='P';
						usd[n]=1;
					}
					else if(s)
					{
						ret[i]='S';
						usd[n]=-1;
					}
					else
					{
						ok=false;
						break;
					}
				}
				else if(usd[n]==1)
				{
					if(s)
					{
						ret[i]='S';
					}
					else
					{
						ok=false;
						break;
					}
				}
				else
				{
					if(p)
					{
						ret[i]='P';
					}
					else
					{
						ok=false;
						break;
					}
				}
			}
			if(ok)ans=ret;
		}
		if(!ans.empty())break;
		swap(s,t);
	}
	cout<<ans<<endl;
}