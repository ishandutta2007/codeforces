#include<bits/stdc++.h>
using namespace std;
int n,test,k;
int a[2222],l[2222],r[2222],cnt,b[2222],pos;
char s[2222];
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s);
		for (int i=1;i<=n;i++) 
		{
			if (s[i-1]=='(') a[i]=0;
			else a[i]=1;
		}
		for (int i=1;i<k;i++)
		{
			b[i*2-1]=0;b[i*2]=1;
		}
		for (int i=2*k-1;i<=(2*k-1+n)/2;i++)
		{
			b[i]=0;
		}
		for (int i=(2*k-1+n)/2+1;i<=n;i++) b[i]=1;
		cnt=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]==b[i]) continue;
			pos=-1;
			for (int j=i+1;j<=n;j++)
			{
				if (a[j]==b[i]) 
				{
					pos=j;
					break;
				}
			}
			++cnt;l[cnt]=i;r[cnt]=pos;
			reverse(a+i,a+pos+1);
		}
		printf("%d\n",cnt);
		for (int i=1;i<=cnt;i++)
		{
			printf("%d %d\n",l[i],r[i]);
		}
	}
	return 0;
}