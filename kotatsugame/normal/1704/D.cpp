#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N,M;
		cin>>N>>M;
		vector<vector<long long> >C(N,vector<long long>(M));
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)cin>>C[i][j];
		}
		vector<long long>add(N,0LL);
		for(int j=0;j<M-1;j++)
		{
			long long mn=C[0][j];
			for(int i=0;i<N;i++)mn=min(mn,C[i][j]);
			for(int i=0;i<N;i++)
			{
				long long d=C[i][j]-mn;
				C[i][j]-=d;
				C[i][j+1]+=d;
				add[i]+=d;
			}
		}
		long long mx=0;
		for(int i=0;i<N;i++)mx=max(mx,add[i]);
		int id=0;
		while(add[id]==mx)id++;
		cout<<id+1<<" "<<mx-add[id]<<"\n";
	}
}