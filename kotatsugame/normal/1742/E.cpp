#include<iostream>
using namespace std;
int N,Q;
int A[2<<17];
long long S[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>Q;
		for(int i=0;i<N;i++)cin>>A[i];
		S[0]=0;
		for(int i=0;i<N;i++)S[i+1]=S[i]+A[i];
		for(int i=1;i<N;i++)A[i]=max(A[i],A[i-1]);
		A[N]=2e9;
		for(int i=0;i<Q;i++)
		{
			int K;cin>>K;
			int l=-1,r=N;
			while(r-l>1)
			{
				int mid=(l+r)/2;
				if(A[mid]<=K)l=mid;
				else r=mid;
			}
			cout<<S[r]<<(i+1==Q?"\n":" ");
		}
	}
}