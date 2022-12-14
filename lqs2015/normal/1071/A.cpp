#include<iostream>
#include<cstdio>
using namespace std;
int a,b,sum,pos,p[111111],la,lb,q[111111],f;
bool used[111111];
int main()
{
	cin>>a>>b;
	if (a>b) 
	{
		swap(a,b);
		f=1;
	}
	for (int i=1;i<=100000;i++)
	{
		sum+=i;
		if (sum>=a)
		{
			pos=i;
			break;
		}
	}
	for (int i=pos;i>=1;i--)
	{
		if (a>=i) 
		{
			a-=i;
			p[++la]=i;
			used[i]=1;
		}
	}
	for (int i=1;i<=100000;i++)
	{
		if (!used[i])
		{
			if (i>b) break;
			q[++lb]=i;
			b-=i;
		}
	}
	if (f)
	{
		printf("%d\n",lb);
		for (int i=1;i<=lb;i++) printf("%d ",q[i]);
		printf("\n");
		printf("%d\n",la);
		for (int i=1;i<=la;i++) printf("%d ",p[i]);
		printf("\n");
	}
	else
	{
		printf("%d\n",la);
		for (int i=1;i<=la;i++) printf("%d ",p[i]);
		printf("\n");
		printf("%d\n",lb);
		for (int i=1;i<=lb;i++) printf("%d ",q[i]);
		printf("\n");
	}
	
	return 0;
}