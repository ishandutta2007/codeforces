#include<iostream>
#include<cstdio>
using namespace std;
int n,mn,mni,cur,pos;
int main()
{
	scanf("%d",&n);
	mn=1e9;
	for (int i=1;i<=n;i++)
	{
		if (n%i==0) cur=n/i;
		else cur=n/i+1;
		if (cur+i<mn)
		{
			mn=cur+i;
			mni=i;
		}
	}
	if (n%mni) cur=n/mni+1;
	else cur=n/mni;
	pos=n;
	for (int i=1;i<=mni;i++)
	{
		if (pos<=cur)
		{
			for (int j=1;j<=pos;j++)
			printf("%d ",j);
			break;
		}
		for (int j=pos-cur+1;j<=pos;j++)
		{
			printf("%d ",j);
		}
		pos-=cur;
	}
	return 0;
}