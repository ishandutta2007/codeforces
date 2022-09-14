#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int A[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		sort(A,A+N);
		int mx=0;
		for(int i=0;i<N;)
		{
			int j=i;
			while(j<N&&A[i]==A[j])j++;
			int k=j-i;
			if(mx<k)mx=k;
			i=j;
		}
		printf("%d\n",mx*2<=N?N%2:mx*2-N);
	}
}