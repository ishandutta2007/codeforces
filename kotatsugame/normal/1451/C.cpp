#include<cstdio>
using namespace std;
int T,N,K;
char S[1<<20];
int cA[26],cB[26];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		for(int i=0;i<26;i++)cA[i]=cB[i]=0;
		scanf("%d%d\n",&N,&K);
		scanf("%s\n",S);
		for(int i=0;i<N;i++)cA[S[i]-'a']++;
		scanf("%s\n",S);
		for(int i=0;i<N;i++)cB[S[i]-'a']++;
		int now=0;
		bool out=false;
		for(int i=0;i<26;i++)
		{
			now+=cA[i];
			if(now<cB[i])
			{
				out=true;
				break;
			}
			now-=cB[i];
			if(now%K!=0)
			{
				out=true;
				break;
			}
		}
		puts(out?"No":"Yes");
	}
}