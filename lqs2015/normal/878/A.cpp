#include<iostream>
#include<cstdio>
using namespace std;
int n,res1,res2,cur0,cur1;
char c[555555];
int a[555555];
int doit(int cur)
{
	for (int i=1;i<=n;i++)
	{
		if (c[i]=='&') cur=cur&(a[i]&1);
		else if (c[i]=='|') cur=cur|(a[i]&1);
		else cur=cur^(a[i]&1);
	}
	return cur;
}
int main()
{
	scanf("%d",&n);
	getchar();
	for (int i=1;i<=n;i++)
	{
		scanf("%c %d",&c[i],&a[i]);
		getchar();
	}
	for (int i=0;i<10;i++)
	{
		cur0=doit(0);
		cur1=doit(1);
		for (int j=1;j<=n;j++) a[j]>>=1;
		if (!cur0 && !cur1) 
		{
			res1+=(1<<i);
			res2+=(1<<i);	
		}
		else if (!cur0 && cur1);
		else if (cur0 && !cur1) res2+=(1<<i);
		else res1+=(1<<i);
	}
	printf("2\n");
	printf("| %d\n^ %d\n",res1,res2);
	return 0;
}