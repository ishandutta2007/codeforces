#include<iostream>
using namespace std;
int T;
int A[100][100];
main()
{
	cin>>T;
	for(;T--;)
	{
		int N,M,K;
		cin>>N>>M>>K;
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)A[i][j]=0;
		bool flag=false;
		if(N%2==0)
		{
			if(M%2==0)
			{
				flag=K%2==0;
			}
			else if(M==1)
			{
				flag=K==0;
			}
			else
			{
				flag=K%2==0&&(N*M/2-K)>=N/2;
			}
		}
		else if(N==1)
		{
			flag=K==M/2;
		}
		else
		{
			flag=(N*M/2-K)%2==0&&K>=M/2;
		}
		if(flag)
		{
			cout<<"YES\n";
			int id=0;
			if(N%2==0)
			{
				for(int i=0;i<N;i+=2)for(int j=0;j<M;j++)
				{
					A[i][j]=A[i+1][j]=++id;
				}
			}
			else
			{
				for(int i=0;i<N;i++)for(int j=0;j<M;j+=2)
				{
					A[i][j]=A[i][j+1]=++id;
				}
				K=N*M/2-K;
			}
			for(int i=0;i+1<N;i+=2)for(int j=0;j+1<M;j+=2)
			{
				if(K>0)
				{
					K-=2;
					swap(A[i][j+1],A[i+1][j]);
				}
			}
			for(int i=0;i<N;i++)for(int j=0;j<M;j++)if(A[i][j]>0)
			{
				int msk=0;
				if(i+1<N&&A[i][j]==A[i+1][j])
				{
					if(i>0&&A[i-1][j]<=0)msk|=1<<-A[i-1][j];
					if(j>0&&A[i][j-1]<=0)msk|=1<<-A[i][j-1];
					if(j>0&&A[i+1][j-1]<=0)msk|=1<<-A[i+1][j-1];
					if(i+2<N&&A[i+2][j]<=0)msk|=1<<-A[i+2][j];
					if(j+1<M&&A[i][j+1]<=0)msk|=1<<-A[i][j+1];
					if(j+1<M&&A[i+1][j+1]<=0)msk|=1<<-A[i+1][j+1];
					msk++;
					int c=0;
					while(!(msk>>c&1))c++;
					A[i][j]=A[i+1][j]=-c;
				}
				else
				{
					if(i>0&&A[i-1][j]<=0)msk|=1<<-A[i-1][j];
					if(i>0&&A[i-1][j+1]<=0)msk|=1<<-A[i-1][j+1];
					if(j>0&&A[i][j-1]<=0)msk|=1<<-A[i][j-1];
					if(i+1<N&&A[i+1][j]<=0)msk|=1<<-A[i+1][j];
					if(i+1<N&&A[i+1][j+1]<=0)msk|=1<<-A[i+1][j+1];
					if(j+2<M&&A[i][j+2]<=0)msk|=1<<-A[i][j+2];
					msk++;
					int c=0;
					while(!(msk>>c&1))c++;
					A[i][j]=A[i][j+1]=-c;
				}
			}
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<M;j++)cout<<(char)('a'-A[i][j]);
				cout<<endl;
			}
		}
		else cout<<"NO\n";
	}
}