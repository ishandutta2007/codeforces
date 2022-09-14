#include<iostream>
using namespace std;
int A[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,M;
	cin>>N>>M;
	for(int i=0;i<N;i++)cin>>A[i];
	long long ans=(long long)N*(N+1)/2;
	for(int i=0;i+1<N;i++)if(A[i]!=A[i+1])
	{
		//0<=l<=i,i+1<=r<N
		ans+=(long long)(i+1)*(N-(i+1));
	}
	for(;M--;)
	{
		int i,x;cin>>i>>x;i--;
		if(i>0)
		{
			if(A[i-1]!=A[i])ans-=(long long)(i-1+1)*(N-((i-1)+1));
			if(A[i-1]!=x)ans+=(long long)(i-1+1)*(N-((i-1)+1));
		}
		if(i+1<N)
		{
			if(A[i]!=A[i+1])ans-=(long long)(i+1)*(N-(i+1));
			if(x!=A[i+1])ans+=(long long)(i+1)*(N-(i+1));
		}
		A[i]=x;
		cout<<ans<<"\n";
	}
}