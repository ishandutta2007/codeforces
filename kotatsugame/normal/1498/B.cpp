#include<cstdio>
using namespace std;
int T,N,W;
int cnt[30];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&W);
		for(int i=0;i<30;i++)cnt[i]=0;
		for(int i=0;i<N;i++)
		{
			int w;scanf("%d",&w);
			int c=0;
			while(w>1)w/=2,c++;
			cnt[c]++;
		}
		int L=0,R=N;
		while(R-L>1)
		{
			int mid=(L+R)/2;
			long long now=0;
			for(int i=30;i--;)
			{
				now*=2;
				if(W>>i&1)now+=mid;
				now-=cnt[i];
				if(now<0)break;
			}
			if(now>=0)R=mid;
			else L=mid;
		}
		printf("%d\n",R);
	}
}