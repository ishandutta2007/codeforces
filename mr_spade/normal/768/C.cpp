#include<cstdio>
#include<cstring>
const int N=1e5+5;
int n,k,x;
int a[N],b[N];
signed main()
{
	int key;
	bool p;
	register int i,j;
	scanf("%d%d%d",&n,&k,&x);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&key);
		a[key]++;
	}
	if(!k)
	{
		for(j=1023;j>=0;j--)
			if(a[j])
			{
				printf("%d ",j);
				break;
			}
		for(j=0;j<1024;j++)
			if(a[j])
			{
				printf("%d\n",j);
				break;
			}
		return 0;
	}
	for(i=0;i<k;)
	{
		p=0;
		memset(b,0,sizeof(int)*1024);
		for(j=0;j<1024;j++)
			if(a[j])
			{
				if(p)
				{
					b[j^x]+=a[j]>>1;
					b[j]+=(a[j]+1)>>1;
				}
				else
				{
					b[j^x]+=(a[j]+1)>>1;
					b[j]+=a[j]>>1;
				}
				if(a[j]&1)
					p^=1;
			}
		if((++i)==k)
		{
			for(j=1023;j>=0;j--)
				if(b[j])
				{
					printf("%d ",j);
					break;
				}
			for(j=0;j<1024;j++)
				if(b[j])
				{
					printf("%d\n",j);
					break;
				}
			return 0;
		}
		p=0;
		memset(a,0,sizeof(int)*1024);
		for(j=0;j<1024;j++)
			if(b[j])
			{
				if(p)
				{
					a[j^x]+=b[j]>>1;
					a[j]+=(b[j]+1)>>1;
				}
				else
				{
					a[j^x]+=(b[j]+1)>>1;
					a[j]+=b[j]>>1;
				}
				if(b[j]&1)
					p^=1;
			}
		if((++i)==k)
		{
			for(j=1023;j>=0;j--)
				if(a[j])
				{
					printf("%d ",j);
					break;
				}
			for(j=0;j<1024;j++)
				if(a[j])
				{
					printf("%d\n",j);
					break;
				}
			return 0;
		}
	}
}