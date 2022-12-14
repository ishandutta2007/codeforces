#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int t,a[111],n,pos,k,b[111],cnt,c[111111];
bool used[1111111],f;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(used,0,sizeof(used));
		f=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		cnt=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			c[++cnt]=abs(a[i]-a[j]);
		}
		k=1;
		for (int i=1;i<=n;i++)
		{
			if (k>1000000)
			{
				f=1;
				break;
			}
			b[i]=k;
			for (int j=1;j<=cnt;j++) used[k+c[j]]=1;
			k++;
			while(k<=1000000 && used[k]) k++;
		}
		if (f) printf("NO\n");
		else 
		{
			printf("YES\n");
			for (int i=1;i<=n;i++) 
			printf("%d ",b[i]);
			printf("\n");
		}
	}
	return 0;
}