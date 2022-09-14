#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,A[1<<20];
int idx[(2<<20)+1];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	N=unique(A,A+N)-A;
	{
		int prv=0;
		for(int i=0;i<N;i++)
		{
			while(prv<=A[i])idx[prv++]=i;
		}
	}
	long long cumsum=1;
	for(int k=1;;cumsum+=k*2+1,k++)
	{
		long long l=cumsum,r=cumsum+k+1;
		if(r<=A[0])continue;
		long long add=A[0]<l?l-A[0]:0;
		long long mn=1e18;
		bool ok=true;
		long long i=k;
		while(true)
		{
			int ni=r-add<=A[N-1]?idx[r-add]:N;
			if(ni==N)break;
			long long prv=add+A[ni-1];
			mn=min(mn,r-prv-1);
			long long nl=r+i,nr=r+i+i+2;
			i++;
			long long nxt=add+A[ni];
			if(nxt<nl)
			{
				long long need=nl-nxt;
				if(mn<need)
				{
					ok=false;
					break;
				}
				mn-=need;
				add+=need;
			}
			l=nl,r=nr;
		}
		if(ok)
		{
			cout<<add<<endl;
			return 0;
		}
	}
}