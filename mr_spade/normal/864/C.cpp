#include<cstdio>
const int N=1e6+5;
int a,b,f,k;
int kk=0,bb,now=0,ans=0;
signed main()
{
	int i,j;
	scanf("%d%d%d%d",&a,&b,&f,&k);
	bb=b;
	while(kk<k)
	{
		if(kk==k-1)
		{
			if(!now)
			{
				if(bb<f||b<a-f)
				{
					puts("-1");
					return 0;
				}
				if(a<=bb)
					bb-=a;
				else
				{
					ans++;
					bb=b;
					bb-=a-f;
				}
			}
			else
			{
				if(bb<a-f||b<f)
				{
					puts("-1");
					return 0;
				}
				if(a<=bb)
					bb-=a;
				else
				{
					ans++;
					bb=b;
					bb-=f;
				}
			}
			kk++;
			continue;
		}
		if(!now)
		{
			if(bb<f)
			{
				puts("-1");
				return 0;
			}
			if(2*a-f<=bb)
				bb-=a;
			else
			{
				ans++;
				bb=b;
				bb-=a-f;
			}
			now=a;
		}
		else
		{
			if(bb<a-f)
			{
				puts("-1");
				return 0;
			}
			if(a+f<=bb)
				bb-=a;
			else
			{
				ans++;
				bb=b;
				bb-=f;
			}
			now=0;
		}
		kk++;
	}
	printf("%d\n",ans);
	return 0;
}