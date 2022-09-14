#include<iostream>
#include<vector>
#include<set>
using namespace std;
int T,N,Q;
vector<int>G[1<<20];
int A[1<<20],L[1<<20],K[1<<20],ans[1<<20];
vector<int>Qs[1<<20];
int cnt[1<<20];
int S1[1<<20];
set<int>T1[1<<20];
void dfs(int u)
{
	cnt[A[u]]++;
	S1[cnt[A[u]]]++;
	if(cnt[A[u]]>1)T1[cnt[A[u]]-1].erase(A[u]);
	T1[cnt[A[u]]].insert(A[u]);
	for(int qi:Qs[u])
	{
		int l=L[qi],k=K[qi];
		if(S1[l]<k)ans[qi]=-1;
		else
		{
			int del=S1[l]-k;
			int r=N+1;
			while(r-l>1)
			{
				int mid=(l+r)/2;
				if(S1[mid]>del)l=mid;
				else r=mid;
			}
			ans[qi]=*T1[l].begin();
		}
	}
	for(int v:G[u])dfs(v);
	S1[cnt[A[u]]]--;
	T1[cnt[A[u]]].erase(A[u]);
	if(cnt[A[u]]>1)T1[cnt[A[u]]-1].insert(A[u]);
	cnt[A[u]]--;
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>Q;
		for(int i=0;i<N;i++)
		{
			G[i].clear();
			Qs[i].clear();
			cin>>A[i];
		}
		for(int i=1;i<N;i++)
		{
			int p;cin>>p;
			G[p-1].push_back(i);
		}
		for(int i=0;i<Q;i++)
		{
			int v;cin>>v>>L[i]>>K[i];
			Qs[v-1].push_back(i);
		}
		dfs(0);
		for(int i=0;i<Q;i++)cout<<ans[i]<<(i+1==Q?"\n":" ");
	}
}