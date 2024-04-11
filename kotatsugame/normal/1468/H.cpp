#include<cstdio>
#include<vector>
using namespace std;
int T,N,K,M;
bool ex[2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%d",&N,&K,&M);
		for(int i=0;i<N;i++)ex[i]=false;
		for(int i=0;i<M;i++)
		{
			int b;scanf("%d",&b);ex[b-1]=true;
		}
		if((N-M)%(K-1)!=0)
		{
			puts("NO");
			continue;
		}
		int t=(N-M)/(K-1);
		vector<int>del;del.reserve(N-M);
		for(int i=0;i<N;i++)if(!ex[i])del.push_back(i);
		int L=del[K/2-1],R=del[N-M-K/2];
		bool fn=false;
		for(int i=L;i<=R;i++)if(ex[i])fn=true;
		puts(fn?"YES":"NO");
	}
}