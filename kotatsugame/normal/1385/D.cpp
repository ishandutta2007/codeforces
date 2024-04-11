#include<cstdio>
#include<algorithm>
using namespace std;
int t,N;
char S[2<<17];
int T[18][1<<17];
main()
{
	scanf("%d\n",&t);
	for(;t--;)
	{
		scanf("%d\n",&N);
		scanf("%s\n",S);
		int mx=0;
		while(1<<mx<N)
		{
			mx++;
		}
		for(int k=0;k<=mx;k++)
		{
			char now='a'+mx-k;
			for(int i=0;i<N;i+=1<<k)
			{
				if(k==0)
				{
					T[k][i]=S[i]==now?0:1;
				}
				else
				{
					int L=0,R=0;
					int LIM=1<<k-1;
					for(int j=0;j<LIM;j++)
					{
						L+=S[i+j]!=now;
						R+=S[i+LIM+j]!=now;
					}
					T[k][i]=min(L+T[k-1][i+LIM],R+T[k-1][i]);
				}
			}
		}
		printf("%d\n",T[mx][0]);
	}
}