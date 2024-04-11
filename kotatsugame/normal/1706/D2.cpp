#include<iostream>
#include<algorithm>
using namespace std;
int T,N,K;
int A[1<<17],R[1<<17];
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
		for(int l=0;l<=A[0];l++)R[l]=0;
		for(int i=0;i<N;i++)
		{
			R[0]=max(R[0],A[i]/K);
			int l=1;
			while(l<=A[0])
			{
				int q=A[i]/l;
				R[l]=max(R[l],A[i]/min(q,K));
				l=A[i]/q+1;
			}
		}
		int ans=R[0];
		for(int l=1;l<=A[0];l++)
		{
			R[l]=max(R[l],R[l-1]);
			ans=min(ans,R[l]-l);
		}
		cout<<ans<<"\n";
	}
}