#include<iostream>
using namespace std;
int to[26],from[26];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;
		string S;
		cin>>N>>S;
		for(int i=0;i<26;i++)to[i]=from[i]=-1;
		for(char&c:S)
		{
			int u=c-'a';
			if(to[u]==-1)
			{
				int v=0;
				for(;;v++)
				{
					if(u==v||from[v]!=-1)continue;
					int w=v;
					int cnt=0;
					while(to[w]!=-1)w=to[w],cnt++;
					if(w==u&&cnt<25)continue;
					to[u]=v;
					from[v]=u;
					break;
				}
			}
			c=to[u]+'a';
		}
		cout<<S<<"\n";
	}
}