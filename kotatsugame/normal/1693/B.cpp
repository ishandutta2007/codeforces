#include<iostream>
using namespace std;
int T,N;
int P[2<<17];
int L[2<<17],R[2<<17];
int dp[2<<17];
long long S[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=1;i<N;i++)
		{
			cin>>P[i];
			P[i]--;
		}
		for(int i=0;i<N;i++)cin>>L[i]>>R[i];
		for(int i=0;i<N;i++)
		{
			dp[i]=0;
			S[i]=0;
		}
		for(int i=N;i--;)
		{
			if(S[i]<L[i])
			{
				S[i]=R[i];
				dp[i]++;
			}
			if(S[i]>R[i])S[i]=R[i];
			if(i>0)
			{
				dp[P[i]]+=dp[i];
				S[P[i]]+=S[i];
			}
		}
		cout<<dp[0]<<"\n";
	}
}