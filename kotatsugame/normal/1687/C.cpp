#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
int T,N,M;
int A[2<<17],B[2<<17];
long long S[2<<17];
int cnt[2<<17];
int L[2<<17],R[2<<17];
vector<int>qi[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int i=0;i<N;i++)cin>>B[i];
		S[0]=0;
		for(int i=0;i<N;i++)S[i+1]=S[i]+A[i]-B[i];
		queue<int>Q;
		for(int i=0;i<=N;i++)qi[i].clear();
		for(int i=0;i<M;i++)
		{
			cin>>L[i]>>R[i];
			L[i]--;
			cnt[i]=0;
			if(!S[L[i]])cnt[i]++;
			else qi[L[i]].push_back(i);
			if(!S[R[i]])cnt[i]++;
			else qi[R[i]].push_back(i);
			if(cnt[i]==2)Q.push(i);
		}
		set<int>del;
		{
			vector<int>di;
			for(int i=0;i<=N;i++)if(S[i])di.push_back(i);
			del=set<int>(di.begin(),di.end());
		}
		while(!Q.empty())
		{
			int u=Q.front();
			Q.pop();
			int l=L[u],r=R[u];
			auto it=del.lower_bound(l);
			while(it!=del.end()&&*it<r)
			{
				int v=*it;
				for(int id:qi[v])
				{
					if(++cnt[id]==2)Q.push(id);
				}
				it=del.erase(it);
			}
		}
		cout<<(del.empty()?"YES\n":"NO\n");
	}
}