#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T,N;
int A[10];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			A[i]=abs(A[i]);
		}
		vector<int>B(1<<N);
		for(int i=0;i<1<<N;i++)
		{
			int sum=0;
			for(int j=0;j<N;j++)if(i>>j&1)sum+=A[j];
			B[i]=sum;
		}
		sort(B.begin(),B.end());
		bool ok=false;
		for(int i=1;i<1<<N;i++)if(B[i-1]==B[i])ok=true;
		puts(ok?"YES":"NO");
	}
}