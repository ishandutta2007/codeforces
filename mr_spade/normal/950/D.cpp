#include<cstdio>
typedef long long ll;
const int Q=2e5+5;
ll n;
int q;
signed main()
{
	ll nown,x,ans;
	scanf("%lld%d",&n,&q);
	while(q--)
	{
		ans=0;nown=n;
		scanf("%lld",&x);
		while(!(x&1))
		{
			if(nown&1)
			{
				ans+=nown+1>>1;
				x=(x>>1)-1;
				if(!x)
					x=nown>>1;
				nown>>=1;
			}
			else
			{
				ans+=nown>>1;
				x=(x>>1);
				nown>>=1;
			}
		}
		printf("%lld\n",ans+(x+1>>1));
	}
	return 0;
}