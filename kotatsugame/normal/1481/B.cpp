#include<cstdio>
using namespace std;
int T,N,K;
int H[100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		for(int i=0;i<N;i++)scanf("%d",&H[i]);
		int ans=-1;
		for(int c=0;c<K;c++)
		{
			int i=0;
			while(i<N-1&&H[i]>=H[i+1])i++;
			if(i==N-1)break;
			else if(c==K-1)ans=i+1;
			H[i]++;
		}
		printf("%d\n",ans);
	}
}