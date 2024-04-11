#include<cstdio>
#include<vector>
using namespace std;
int N,K;
int mc[2<<17],c[2<<17];
vector<int>A[2<<17];
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		int m;scanf("%d",&m);
		mc[m]++;
	}
	for(int i=1;i<=K;i++)scanf("%d",&c[i]);
	int L=0,R=N;
	while(R-L>1)
	{
		long long M=L+R>>1;
		int cumsum=0;
		bool ok=true;
		for(int i=K;i>0;i--)
		{
			cumsum+=mc[i];
			if(c[i]*M<cumsum)
			{
				ok=false;
				break;
			}
		}
		if(ok)R=M;
		else L=M;
	}
	int id=0;
	for(int i=K;i>0;i--)
	{
		while(mc[i]>0)
		{
			A[id].push_back(i);
			mc[i]--;
			id++;
			if(id==R)id=0;
		}
	}
	printf("%d\n",R);
	for(int i=0;i<R;i++)
	{
		printf("%d",(int)A[i].size());
		for(int a:A[i])printf(" %d",a);
		puts("");
	}
}