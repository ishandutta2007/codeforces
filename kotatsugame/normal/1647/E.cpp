#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int N;
int P[1<<17];
int cnt[1<<17];
int A[1<<17];
int B[1<<17];
bool vis[1<<17];
int E[1<<17];
int T[1<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	int turn=0;
	for(int i=0;i<N;i++)
	{
		cin>>P[i];
		P[i]--;
		if(cnt[P[i]]++)turn++;
	}
	int mx=0;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		A[i]--;
		if(mx<A[i])mx=A[i];
	}
	int step=turn==0?0:(mx-(N-1))/turn;
	for(int i=0;i<N;i++)E[i]=i;
	while(step>0)
	{
		if(step%2)
		{
			for(int i=0;i<N;i++)T[i]=E[i];
			for(int i=0;i<N;i++)E[i]=P[T[i]];
		}
		step>>=1;
		for(int i=0;i<N;i++)T[i]=P[i];
		for(int i=0;i<N;i++)P[i]=T[T[i]];
	}
	for(int i=0;i<N;i++)B[i]=A[E[i]];
	set<int>S;
	for(int i=0;i<N;i++)S.insert(i);
	for(int i=0;i<N;i++)if(S.find(B[i])!=S.end())
	{
		vis[i]=true;
		S.erase(B[i]);
	}
	for(int i=0;i<N;i++)if(!vis[i])
	{
		auto it=S.lower_bound(B[i]);
		B[i]=*it;
		S.erase(it);
	}
	for(int i=0;i<N;i++)cout<<B[i]+1<<(i+1==N?"\n":" ");
}