#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<int>A(N),B(N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		for(int i=0;i<N;i++)scanf("%d",&B[i]);
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		vector<int>SA(N+1),SB(N+1);
		for(int i=0;i<N;i++)
		{
			SA[i+1]=SA[i]+A[N-i-1];
			SB[i+1]=SB[i]+B[N-i-1];
		}
		int cnt=0;
		while(true)
		{
			long long a=0,b=0;
			int n=N+cnt;
			int use=n-n/4;
			if(use<=cnt)
			{
				a=(long long)use*100;
			}
			else
			{
				a=(long long)cnt*100+SA[use-cnt];
			}
			if(N<=use)b=SB[N];
			else b=SB[use];
			if(a>=b)break;
			cnt++;
		}
		printf("%d\n",cnt);
	}
}