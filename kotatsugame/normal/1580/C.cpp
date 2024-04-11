#include<cstdio>
using namespace std;
const int B=450;
int N,M;
int X[2<<17],Y[2<<17];
int inday[2<<17];
int cnt[B+1][B];
int sum[2<<17];
int day[B+1];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)scanf("%d%d",&X[i],&Y[i]);
	for(int i=0;i<M;i++)
	{
		int op,k;
		scanf("%d%d",&op,&k);k--;
		int len=X[k]+Y[k];
		if(len<=B)
		{
			if(op==1)inday[k]=i;
			int nt=(inday[k]+X[k])%len;
			int add=op==1?1:-1;
			for(int j=0;j<Y[k];j++)
			{
				cnt[len][nt]+=add;
				nt++;
				if(nt==len)nt=0;
			}
		}
		else
		{
			if(op==1)
			{
				inday[k]=i;
				int nt=i;
				while(true)
				{
					nt+=X[k];
					if(nt>=M)break;
					sum[nt]++;
					nt+=Y[k];
					if(nt>=M)break;
					sum[nt]--;
				}
			}
			else
			{
				int diff=(i-inday[k])%len;
				int nt;
				if(diff<X[k])
				{
					nt=i+X[k]-diff;
					if(nt<M)
					{
						sum[nt]--;
						nt+=Y[k];
						if(nt<M)sum[nt]++;
					}
				}
				else
				{
					sum[i]--;
					nt=len-diff;
					if(nt<M)
					{
						nt+=i;
						if(nt<M)
						{
							sum[nt]++;
						}
					}
				}
				while(nt<M)
				{
					nt+=X[k];
					if(nt>=M)break;
					sum[nt]--;
					nt+=Y[k];
					if(nt>=M)break;
					sum[nt]++;
				}
			}
		}
		int ans=0;
		for(int j=1;j<=B;j++)
		{
			ans+=cnt[j][day[j]];
			day[j]++;
			if(day[j]==j)day[j]=0;
		}
		ans+=sum[i];
		sum[i+1]+=sum[i];
		printf("%d\n",ans);
	}
}