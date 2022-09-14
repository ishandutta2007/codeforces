#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,X,W[100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&X);
		for(int i=0;i<N;i++)scanf("%d",&W[i]);
		sort(W,W+N);
		bool ok=true;
		for(int i=0;i<N;i++)
		{
			X-=W[i];
			if(X==0)
			{
				if(i+1==N)ok=false;
				else
				{
					swap(W[i],W[i+1]);
				}
			}
		}
		if(ok)
		{
			puts("YES");
			for(int i=0;i<N;i++)printf("%d%c",W[i],i+1==N?10:32);
		}
		else puts("NO");
	}
}