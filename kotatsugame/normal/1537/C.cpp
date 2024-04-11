#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
int H[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&H[i]);
		sort(H,H+N);
		int mid=0;
		for(int i=1;i<N-1;i++)
		{
			if(H[mid+1]-H[mid]>H[i+1]-H[i])mid=i;
		}
		printf("%d",H[mid]);
		for(int i=mid+2;i<N;i++)
		{
			printf(" %d",H[i]);
		}
		for(int i=0;i<mid;i++)
		{
			printf(" %d",H[i]);
		}
		printf(" %d\n",H[mid+1]);
	}
}