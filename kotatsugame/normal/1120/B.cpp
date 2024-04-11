#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
char sA[1<<17],sB[1<<17];
int A[1<<17],B[1<<17];
int d[1<<17];
main()
{
	scanf("%d\n%s\n%s",&N,sA,sB);
	for(int i=0;i<N;i++)
	{
		A[i]=sA[i]-'0';
		B[i]=sB[i]-'0';
	}
	long long ans=0;
	for(int i=0;i<N-1;i++)
	{
		d[i]=B[i]-(A[i]+(i>0?d[i-1]:0));
		ans+=abs(d[i]);
	}
	if(d[N-2]+A[N-1]!=B[N-1])
	{
		puts("-1");
		return 0;
	}
	vector<pair<int,int> >ret;
	while(ret.size()<(int)1e5)
	{
		bool fn=false;
		int p=0;
		for(int i=0;i<N-1;i++)if(d[i]!=0)
		{
			fn=true;
			bool now=false;
			if(d[i]>0)now=A[i]<9&&A[i+1]<9;
			else now=A[i]>(i>0?0:1)&&A[i+1]>0;
			if(now)
			{
				for(int j=i;j>=p;j--)if(d[j]!=0)
				{
					if(d[j]>0)
					{
						ret.push_back(make_pair(j,1));
						d[j]--;
						A[j]++;
						A[j+1]++;
					}
					else
					{
						ret.push_back(make_pair(j,-1));
						d[j]++;
						A[j]--;
						A[j+1]--;
					}
				}
				p=i+1;
			}
		}
		if(!fn)break;
	}
	printf("%lld\n",ans);
	for(int i=0;i<ret.size()&&i<(int)1e5;i++)
	{
		printf("%d %d\n",ret[i].first+1,ret[i].second);
	}
}