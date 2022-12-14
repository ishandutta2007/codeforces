#include<bits/stdc++.h>
using namespace std;
int n,k,a[222222],b[222222];
char s[222222];
bool f;
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	for (int i=1;i<=n;i++) a[i]=s[i-1]-'0';
	for (int i=1;i<=k;i++) b[i]=a[i];
	for (int i=k+1;i<=n;i++) b[i]=b[i-k];
	for (int i=1;i<=n;i++)
	{
		if (b[i]>a[i])
		{
			break;
		}
		if (a[i]>b[i])
		{
			f=1;
			break;
		}
	}
	if (f)
	{
		b[k]++;
		int pos=k;
		while(b[pos]==10)
		{
			b[pos]=0;
			b[--pos]++;
		}
		for (int i=k+1;i<=n;i++) b[i]=b[i-k];
	}
	printf("%d\n",n);
	for (int i=1;i<=n;i++) printf("%d",b[i]);
	printf("\n");
	return 0;
}