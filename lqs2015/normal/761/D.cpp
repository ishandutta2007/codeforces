#include<iostream>
#include<cstdio>
using namespace std;
int a[111111],b[111111],p[111111],n,l,r;
int pos[111111],dif;
int main()
{
	cin>>n>>l>>r;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		pos[p[i]]=i;
	}
	b[pos[1]]=l;
	dif=l-a[pos[1]];
	for (int i=2;i<=n;i++)
	{
		dif++;
		b[pos[i]]=dif+a[pos[i]];
		if (b[pos[i]]<l) b[pos[i]]=l;
		if (b[pos[i]]>r)
		{
			printf("-1\n");
			return 0;
		}
		dif=b[pos[i]]-a[pos[i]];
	}
	for (int i=1;i<=n;i++) 
	{
		printf("%d ",b[i]);
	}
	printf("\n");
	return 0;
}