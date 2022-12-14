#include<iostream>
#include<cstdio>
using namespace std;
int n,a[222222],f,p1[222222],p2[222222],f1,f2,cur,pos;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n+1;i++) scanf("%d",&a[i]);
	f1=f2=1;cur=1;pos=1;
	for (int i=2;i<=n+1;i++)
	{
		if (a[i]>1 && f2>f1) f=1;
		for (int j=1;j<=a[i];j++) 
		{
			cur++;
			p1[cur]=f1;p2[cur]=pos;
			pos++;
			if (pos>f2) pos=f1;
		}
		f1=cur-a[i]+1;f2=cur;pos=f1;
	}
	if (!f) printf("perfect\n");
	else 
	{
		printf("ambiguous\n");
		for (int i=1;i<=cur;i++)
		{
			printf("%d ",p1[i]);
		}
		printf("\n");
		for (int i=1;i<=cur;i++)
		{
			printf("%d ",p2[i]);
		}
	}
	return 0;
}