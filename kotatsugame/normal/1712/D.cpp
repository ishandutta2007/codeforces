#include<iostream>
using namespace std;
int N,K,A[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		for(int i=0;i<N;i++)cin>>A[i];
		int L=1,R=(int)1e9+1;
		while(R-L>1)
		{
			int mid=(L+R)/2;
			int cnt=0;
			for(int i=0;i<N;i++)if(2*A[i]<mid)cnt++;
			int need=K+1;
			for(int i=0;i+1<N;i++)
			{
				int c=0;
				if(A[i]<mid&&2*A[i]>=mid)c++;
				if(A[i+1]<mid&&2*A[i+1]>=mid)c++;
				need=min(need,c);
			}
			if(cnt+need<=K)L=mid;
			else R=mid;
		}
		cout<<L<<"\n";
	}
}