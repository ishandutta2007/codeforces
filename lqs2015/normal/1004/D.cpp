#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n,a[1111111],sum[1111111],mx,cnt[1111111],rw,c,col;
bool f;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[a[i]]++;
		mx=max(mx,a[i]);
	}
	for (int i=1;i<=n;i++) 
	{
		if (sum[i]<i*4)
		{
			rw=i;
			break;
		}
	}
	for (int i=rw;i<=n;i++)
	{
		if (n%i==0)
		{
			c=n/i;
			col=(i+c)-rw-mx;
			if (col>c || col<=0) continue;
			memset(cnt,0,sizeof(cnt));
			for (int j=1;j<=i;j++)
			{
				for (int k=1;k<=c;k++)
				{
					cnt[abs(j-rw)+abs(k-col)]++;
				}
			}
			f=0;
			for (int j=0;j<=mx;j++)
			{
				if (sum[j]!=cnt[j]) 
				{
					f=1;
					break;
				}
			}
			if (!f)
			{
				printf("%d %d\n",i,c);
				printf("%d %d\n",rw,col);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}