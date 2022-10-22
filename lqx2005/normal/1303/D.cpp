#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Log=30;
int T,n,m;
int p2[Log+5];
int but[Log+5];
map<int,int> Lg;
signed main()
{
	p2[0]=1;
	for(int i=1;i<=Log;i++) p2[i]=p2[i-1]*2;
	for(int i=0;i<=Log;i++) Lg[p2[i]]=i;
	scanf("%lld",&T);
	for(int tt=1;tt<=T;tt++)
	{
		memset(but,0,sizeof(but));
		scanf("%lld%lld",&n,&m);
		int num,sum=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%lld",&num);
			but[Lg[num]]++;
			sum+=num;
		}
		if(sum<n)
		{
			printf("-1\n");
			continue;
		}
		int ans=0;
		for(int i=0;i<=Log;i++)
		{
			if(n&p2[i])
			{
				if(but[i]>0) but[i]--;
				else 
				{
					for(int j=i;j<=Log;j++)
					{
						if(but[j]>0)
						{
							but[j]--;
							break;
						}
						but[j]++;
						ans++;
					}
				}
			}
			but[i+1]+=but[i]/2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}