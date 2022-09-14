#include<cstdio>
using namespace std;
char S[1<<17];
int N,K;
main()
{
	scanf("%d%d%s",&N,&K,S);
	for(int i=0;i<N;i++)
	{
		if((int)S[i]-K>=(int)'a')
		{
			S[i]-=K;
			K=0;
		}
		else if((int)S[i]+K<=(int)'z')
		{
			S[i]+=K;
			K=0;
		}
		else
		{
			int L=S[i]-'a',R='z'-S[i];
			if(L>=R)S[i]='a',K-=L;
			else S[i]='z',K-=R;
		}
	}
	puts(K?"-1":S);
}