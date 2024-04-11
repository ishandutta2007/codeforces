#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N,M;
vector<int>G[2<<17];
int pr[2<<17];
int org[2<<17];
int cnt[2<<17];
main()
{
	int s;
	cin>>N>>M>>s;
	for(int i=0;i<M;i++)
	{
		int u,v;cin>>u>>v;
		G[u].push_back(v);
	}
	queue<int>P;
	cnt[s]=1;
	for(int v:G[s])
	{
		pr[v]=s;
		org[v]=v;
		cnt[v]=1;
		P.push(v);
	}
	while(!P.empty())
	{
		int u=P.front();
		P.pop();
		for(int v:G[u])
		{
			if(cnt[v])
			{
				if(v==s||org[v]==org[u])continue;
				cout<<"Possible\n";
				vector<int>A,B;
				A.push_back(v);
				B.push_back(v);
				B.push_back(u);
				while(A.back()!=s)A.push_back(pr[A.back()]);
				while(B.back()!=s)B.push_back(pr[B.back()]);
				reverse(A.begin(),A.end());
				reverse(B.begin(),B.end());
				cout<<A.size()<<"\n";
				for(int i=0;i<A.size();i++)cout<<A[i]<<(i+1==A.size()?"\n":" ");
				cout<<B.size()<<"\n";
				for(int i=0;i<B.size();i++)cout<<B[i]<<(i+1==B.size()?"\n":" ");
				return 0;
			}
			cnt[v]++;
			pr[v]=u;
			org[v]=org[u];
			P.push(v);
		}
	}
	cout<<"Impossible\n";
}