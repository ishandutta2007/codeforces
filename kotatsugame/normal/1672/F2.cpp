#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int T,N,A[2<<17],B[2<<17];
int cnt[2<<17];
vector<int>G[2<<17];
int deg[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=1;i<=N;i++)cnt[i]=0,G[i].clear(),deg[i]=0;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			cnt[A[i]]++;
		}
		int mx=1;
		for(int i=1;i<=N;i++)if(cnt[mx]<cnt[i])mx=i;
		for(int i=0;i<N;i++)
		{
			cin>>B[i];
			G[A[i]].push_back(B[i]);
			deg[B[i]]++;
		}
		queue<int>Q;
		for(int i=1;i<=N;i++)if(!deg[i])
		{
			Q.push(i);
		}
		if(deg[mx])Q.push(mx);
		int cnt=0;
		while(!Q.empty())
		{
			int u=Q.front();Q.pop();
			cnt++;
			for(int v:G[u])if(!--deg[v]&&v!=mx)Q.push(v);
		}
		cout<<(cnt<N?"WA\n":"AC\n");
	}
}