#include<cstdio>
#include<algorithm>
#include<bitset>
using namespace std;
int Q;
main()
{
	scanf("%d",&Q);
	for(;Q--;)
	{
		int N;scanf("%d",&N);
		bitset<200001>S;
		int M=1;
		for(;N--;)
		{
			int a;scanf("%d",&a);
			S[a]=1;
			M=max(M,a);
		}
		int ans=0;
		if(M%2==0&&M%3==0&&M%5==0)
		{
			if(S[M/2]&&S[M/3]&&S[M/5])
			{
				ans=M/2+M/3+M/5;
			}
		}
		int nxt=M;
		for(int i=1;i<=M;i++)
		{
			if(M%i==0)S[i]=0;
		}
		int id=M;
		while(id>=0&&S[id]==0)id--;
		if(id>1)
		{
			nxt+=id;
			for(int i=1;i<=M;i++)if(id%i==0)S[i]=0;
			id=M;
			while(id>=0&&S[id]==0)id--;
			if(id>1)nxt+=id;
		}
		printf("%d\n",max(ans,nxt));
	}
}