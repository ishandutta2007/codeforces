#include<cstdio>
#include<algorithm>
using namespace std;
int T,N;
long long t[1<<17];
int x[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%lld%d",&t[i],&x[i]);
		}
		int cnt=0;
		int pos=0,to=0;
		t[N]=1e10;
		for(int i=0;i<N;i++)
		{
			if(pos==to)
			{
				to=x[i];
				int dist=abs(pos-to);
				if(dist<=t[i+1]-t[i])
				{
					pos=to;
					cnt++;
				}
				else
				{
					if(pos<to)pos+=t[i+1]-t[i];
					else pos-=t[i+1]-t[i];
				}
			}
			else
			{
				long long tm=t[i+1]-t[i];
				if(pos<to)
				{
					int R=min(pos+tm,(long long)to);
					if(pos<=x[i]&&x[i]<=R)cnt++;
					pos=R;
				}
				else
				{
					int L=max(pos-tm,(long long)to);
					if(L<=x[i]&&x[i]<=pos)cnt++;
					pos=L;
				}
			}
		}
		printf("%d\n",cnt);
	}
}