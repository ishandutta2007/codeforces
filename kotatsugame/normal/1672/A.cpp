#include<iostream>
#include<set>
using namespace std;
int T,N;
int G[51];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	G[1]=0;
	for(int i=2;i<=50;i++)
	{
		set<int>S;
		for(int j=1;j<i;j++)S.insert(G[j]^G[i-j]);
		int id=0;
		while(S.find(id)!=S.end())id++;
		G[i]=id;
	}
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int X=0;
		for(int i=0;i<N;i++)
		{
			int A;cin>>A;
			X^=G[A];
		}
		cout<<(X?"errorgorn":"maomao90")<<"\n";
	}
}