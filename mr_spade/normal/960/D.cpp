#include<cstdio>
#define int long long
const int N=1e5+5;
inline int bel(int x)
{
	int res=0;
	while(x)
		res++,x>>=1ll;
	return res;
}
int q;
int move_wch[N],move[N];
signed main()
{
	int opt,x,y,k,base,mod;
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld",&opt);
		if(opt==1ll)
		{
			scanf("%lld%lld",&x,&k);
			x=bel(x);mod=1ll<<(x-1ll);
			move[x]=(move[x]+(k%mod+mod)%mod)%mod;
		}
		else if(opt==2)
		{
			scanf("%lld%lld",&x,&k);
			x=bel(x);mod=1ll<<(x-1ll);
			move_wch[x]=(move_wch[x]+(k%mod+mod)%mod)%mod;
		}
		else
		{
			scanf("%lld",&x);
			while(true)
			{
				printf("%lld ",x);
				if(x==1ll)
					break;
				y=x>>1ll;k=bel(x);base=0;
				mod=1ll<<(k-2);
				if(x&1)
					base=(base+((move[k]+move_wch[k]+1)/2)%mod)%mod;
				else
					base=(base+((move[k]+move_wch[k])/2)%mod)%mod;
				base=(base-(move[k-1ll]%mod+mod)%mod+mod)%mod;
				y+=base;
				if(y>(1ll<<(k-1ll))-1ll)
					y-=mod;
				x=y;
			}
			putchar('\n');
		}
	}
	return 0;
}