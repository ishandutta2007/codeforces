#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[5010],c[5010],cnt[5010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) cnt[j]=0;
		int count=0,k=0;
		for(int j=i;j<=n;j++)
		{
			cnt[a[j]]++;
			if(cnt[a[j]]>count||(cnt[a[j]]==count&&a[j]<k)) k=a[j],count=cnt[a[j]];
			c[k]++;
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",c[i]);
	return 0;
}