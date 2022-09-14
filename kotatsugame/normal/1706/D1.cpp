#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int T,N,K;
int A[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		for(int i=0;i<N;i++)cin>>A[i];
		N=unique(A,A+N)-A;
		int r=0;
		priority_queue<pair<int,int> >Q;
		for(int i=0;i<N;i++)
		{
			r=max(r,A[i]/K);
			Q.push(make_pair(-1,i));
		}
		int ans=r;
		for(int l=1;l<=A[0];l++)
		{
			while(!Q.empty()&&-Q.top().first==l)
			{
				int id=Q.top().second;
				Q.pop();
				int q=A[id]/l;
				r=max(r,A[id]/min(q,K));
				int nl=A[id]/q+1;
				Q.push(make_pair(-nl,id));
			}
			ans=min(ans,r-l);
		}
		cout<<ans<<"\n";
	}
}