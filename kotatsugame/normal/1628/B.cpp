#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int Q,N;
string S[1<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>Q;
	for(;Q--;)
	{
		cin>>N;
		bool fn=false;
		set<string>S2,S23,S3;
		for(int i=0;i<N;i++)
		{
			cin>>S[i];
			string T=S[i];
			reverse(T.begin(),T.end());
			if(S[i]==T)fn=true;
			if(S[i].size()==2)
			{
				if(S2.find(T)!=S2.end())fn=true;
				if(S23.find(T)!=S23.end())fn=true;
				S2.insert(S[i]);
			}
			if(S[i].size()==3)
			{
				if(S3.find(T)!=S3.end())fn=true;
				if(S2.find(T.substr(0,2))!=S2.end())fn=true;
				S23.insert(S[i].substr(0,2));
				S3.insert(S[i]);
			}
		}
		cout<<(fn?"YES\n":"NO\n");
	}
}