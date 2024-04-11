#include<iostream>
using namespace std;
int T,N,x;
int A[5050];
long long S[5050];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>x;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int i=0;i<=N;i++)S[i]=-1e18;
		S[0]=0;
		for(int i=0;i<N;i++)
		{
			long long now=0;
			for(int j=i;j<N;j++)
			{
				now+=A[j];
				S[j-i+1]=max(S[j-i+1],now);
			}
		}
		for(int i=N;i--;)S[i]=max(S[i],S[i+1]);
		for(int i=0;i<=N;i++)S[i]+=(long long)i*x;
		for(int i=0;i<N;i++)S[i+1]=max(S[i],S[i+1]);
		for(int i=0;i<=N;i++)cout<<S[i]<<(i==N?"\n":" ");
	}
}