#include<iostream>
using namespace std;
long long A[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;
		long long K,B,S;
		cin>>N>>K>>B>>S;
		if(N==1)
		{
			if(S/K==B)cout<<S<<"\n";
			else cout<<"-1\n";
			continue;
		}
		S-=K*B;
		if(S<0||S>N*(K-1))
		{
			cout<<"-1\n";
			continue;
		}
		for(int i=0;i<N;i++)
		{
			A[i]=(B/N+(i<B%N))*K;
			long long t=min(S,K-1);
			S-=t;
			A[i]+=t;
			cout<<A[i]<<(i+1==N?"\n":" ");
		}
	}
}