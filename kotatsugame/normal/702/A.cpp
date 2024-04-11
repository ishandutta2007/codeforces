#include<cstdio>
using namespace std;
int N,A[1<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	int ans=0;
	for(int i=0;i<N;)
	{
		int j=i+1;
		while(j<N&&A[j-1]<A[j])j++;
		if(ans<j-i)ans=j-i;
		i=j;
	}
	printf("%d\n",ans);
}