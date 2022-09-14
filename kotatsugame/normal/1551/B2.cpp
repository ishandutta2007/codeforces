#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int T;
main()
{
	cin>>T;
	for(;T--;)
	{
		int N,K;
		cin>>N>>K;
		vector<vector<int> >id(N);
		for(int i=0;i<N;i++)
		{
			int A;cin>>A;
			id[A-1].push_back(i);
		}
		vector<int>ans(N,0);
		queue<int>rest;
		for(int i=0;i<N;i++)
		{
			if(id[i].size()>=K)
			{
				for(int j=0;j<K;j++)ans[id[i][j]]=j+1;
			}
			else
			{
				for(int j:id[i])rest.push(j);
				if(rest.size()>=K)
				{
					for(int j=0;j<K;j++)
					{
						ans[rest.front()]=j+1;
						rest.pop();
					}
				}
			}
		}
		for(int i=0;i<N;i++)cout<<ans[i]<<(i+1==N?"\n":" ");
	}
}