#include<iostream>
using namespace std;
int T,N;
int ans[1<<20][2];
int pr[1<<20][2];
int P[1<<20];
int ret[1<<20];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		ans[0][0]=-N-1;
		ans[0][1]=N+1;
		P[0]=N+1;
		for(int i=1;i<=N;i++)
		{
			cin>>P[i];
			pr[i][0]=-1;
			pr[i][1]=-1;
			ans[i][0]=N+1;
			ans[i][1]=N+1;
			for(int t=0;t<2;t++)
			{
				int np=t==0?-P[i]:P[i];
				if(-P[i-1]<np)
				{
					if(ans[i][t]>ans[i-1][0])
					{
						ans[i][t]=ans[i-1][0];
						pr[i][t]=0;
					}
				}
				if(ans[i-1][0]<np)
				{
					if(ans[i][t]>-P[i-1])
					{
						ans[i][t]=-P[i-1];
						pr[i][t]=0;
					}
				}
				if(P[i-1]<np)
				{
					if(ans[i][t]>ans[i-1][1])
					{
						ans[i][t]=ans[i-1][1];
						pr[i][t]=1;
					}
				}
				if(ans[i-1][1]<np)
				{
					if(ans[i][t]>P[i-1])
					{
						ans[i][t]=P[i-1];
						pr[i][t]=1;
					}
				}
			}
		}
		if(pr[N][0]!=-1)
		{
			int id=0;
			for(int i=N;i>0;i--)
			{
				ret[i-1]=id==0?-P[i]:P[i];
				id=pr[i][id];
			}
			cout<<"YES\n";
			for(int i=0;i<N;i++)cout<<ret[i]<<(i+1==N?"\n":" ");
		}
		else if(pr[N][1]!=-1)
		{
			int id=1;
			for(int i=N;i>0;i--)
			{
				ret[i-1]=id==0?-P[i]:P[i];
				id=pr[i][id];
			}
			cout<<"YES\n";
			for(int i=0;i<N;i++)cout<<ret[i]<<(i+1==N?"\n":" ");
		}
		else cout<<"NO\n";
	}
}