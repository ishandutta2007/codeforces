#include<iostream>
#include<vector>
using namespace std;
int T,N,K;
int A[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		for(int i=0;i<N;i++)cin>>A[i];
		int cnt=0,out=0;
		for(int i=1;i<N;i++)
		{
			if(A[i-1]>=2*A[i])out++;
			if(out==0&&i>=K)cnt++;
			if(i>=K)
			{
				if(A[i-K]>=2*A[i-K+1])out--;
			}
		}
		cout<<cnt<<"\n";
	}
}