#include<cstdio>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int T,N,A[2000];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int ans=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			for(int j=0;j<i;j++)
			{
				if(gcd(A[i],A[j])>1)ans++;
				else
				{
					if(A[i]%2==0||A[j]%2==0)ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
}