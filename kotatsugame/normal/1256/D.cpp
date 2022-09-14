#include<cstdio>
using namespace std;
int T,N;
long long K;
char S[1<<20];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%lld%s",&N,&K,S);
		int id=0;
		for(int i=0;i<N;i++)if(S[i]=='1')
		{
			if(i>id)id=i;
			while(id<N&&S[id]=='1')id++;
			if(id==N)break;
			if(K>=id-i)
			{
				K-=id-i;
				S[i]='0';
				S[id]='1';
				if(K==0)break;
			}
			else
			{
				S[id]='1';
				S[id-K]='0';
				K=0;
				break;
			}
		}
		puts(S);
	}
}