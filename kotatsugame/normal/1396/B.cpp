#include<cstdio>
using namespace std;
int T,N,A[100];
int main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int sum=0,MX=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			sum+=A[i];
			if(MX<A[i])MX=A[i];
		}
		if(MX>sum-MX)puts("T");
		else puts(sum%2==1?"T":"HL");
	}
}