#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
string A,B;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>A>>B;
		vector<vector<int> >G(20);
		int cnt=0;
		bool ok=true;
		for(int i=0;i<N;i++)
		{
			if(A[i]<B[i])
			{
				G[A[i]-'a'].push_back(B[i]-'a');
			}
			else if(A[i]>B[i])
			{
				ok=false;
			}
		}
		if(!ok)
		{
			cout<<-1<<endl;
			continue;
		}
		for(int i=0;i<20;i++)
		{
			sort(G[i].begin(),G[i].end());
			G[i].erase(unique(G[i].begin(),G[i].end()),G[i].end());
			int id=0;
			if(!G[i].empty()&&G[i][0]==i)id++;
			if(id==G[i].size())continue;
			cnt++;
			for(int j=id+1;j<G[i].size();j++)
			{
				G[G[i][id]].push_back(G[i][j]);
			}
		}
		cout<<cnt<<endl;
	}
}