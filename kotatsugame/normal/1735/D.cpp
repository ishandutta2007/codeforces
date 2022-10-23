#include<iostream>
#include<map>
using namespace std;
int N,K;
map<long long,int>mp;
int C[1000][20];
int V[1000];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>K;
	for(int i=0;i<N;i++)
	{
		long long t=0;
		for(int j=0;j<K;j++)
		{
			cin>>C[i][j];
			t=t*3+C[i][j];
		}
		mp[t]=i;
	}
	for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)
	{
		long long t=0;
		for(int k=0;k<K;k++)t=t*3+(6-C[i][k]-C[j][k])%3;
		if(mp.find(t)!=mp.end())
		{
			V[i]++;
			V[j]++;
			V[mp[t]]++;
		}
	}
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		V[i]/=3;
		ans+=V[i]*(V[i]-1)/2;
	}
	cout<<ans<<endl;
}