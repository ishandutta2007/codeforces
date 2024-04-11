#include<iostream>
using namespace std;
int A[2][2<<17];
int L[2][2<<17],R[2][2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;
		cin>>N;
		for(int i=0;i<2;i++)for(int j=0;j<N;j++)cin>>A[i][j];
		for(int i=0;i<2;i++)
		{
			L[i][N]=0;
			for(int j=N;j--;)
			{
				L[i][j]=max(L[i][j+1],A[i][j]+(A[i][j]==0?0:1)+N-j);
			}
			R[i][N]=-1;
			for(int j=N;j--;)
			{
				R[i][j]=max(R[i][j+1]+1,A[i][j]+(A[i][j]==0?0:1));
			}
		}
		int ans=2e9;
		int now=0;
		for(int j=0;j<N;j++)
		{
			if(j%2==0)
			{
				ans=min(ans,max(max(now+N-j,L[0][j])+N-j-1,R[1][j]));
				now=max(now,A[1][j]);
				now++;
				if(j+1<N)now=max(now,A[1][j+1]);
				now++;
			}
			else
			{
				ans=min(ans,max(max(now+N-j,L[1][j])+N-j-1,R[0][j]));
				now=max(now,A[0][j]);
				now++;
				if(j+1<N)now=max(now,A[0][j+1]);
				now++;
			}
		}
		cout<<ans<<"\n";
	}
}