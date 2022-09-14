#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,K;
char S[2<<17];
const char P[]="RGB";
int cnt[3][3][2<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%s",&N,&K,S);
		for(int i=0;i<3;i++)for(int j=0;j<3;j++)cnt[i][j][0]=0;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<3;j++)for(int k=0;k<3;k++)
			{
				cnt[j][k][i+1]=cnt[j][k][i];
				if(i%3==j&&S[i]==P[k])cnt[j][k][i+1]++;
			}
		}
		int ans=0;
		for(int i=0;i+K<=N;i++)
		{
			for(int j=0;j<3;j++)
			{
				int now=0;
				for(int k=0;k<3;k++)
				{
					now+=cnt[(i+k)%3][(j+k)%3][i+K]-cnt[(i+k)%3][(j+k)%3][i];
				}
				if(ans<now)ans=now;
			}
		}
		printf("%d\n",K-ans);
	}
}