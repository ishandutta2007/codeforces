#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,p,f=-1,s=-1;
	scanf("%d%d%d",&n,&m,&p);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if (a%p && f==-1)
		f=i;
	}
	for (int i=0;i<m;i++)
	{
		int a;
		scanf("%d",&a);
		if (a%p && s==-1)
		s=i;
	}
	printf("%d",f+s);
}