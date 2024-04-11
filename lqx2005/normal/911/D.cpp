#include<bits/stdc++.h>
using namespace std;
const int maxn=1500;
int n,m,l,r;
int a[maxn+5],now=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]>a[j]) now^=1;
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		int len=r-l+1;
		len=len*(len-1)/2;
		now^=(len%2);
		if(now) printf("odd\n");
		else printf("even\n");
	}
	return 0;
}