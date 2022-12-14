#include<iostream>
#include<cstdio>
using namespace std;
int n,a[111111],pos;
bool num[111111],used[111111];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		num[a[i]]=1;
	}
	pos=1;
	for (int i=1;i<=n;i++)
	{
		if (!used[a[i]] && a[i]<=n)
		{
			used[a[i]]=1;
			continue;
		}
		while(num[pos]) pos++;
		a[i]=pos;
		num[pos]=1;
	}
	for (int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}