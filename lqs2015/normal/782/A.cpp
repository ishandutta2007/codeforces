#include<iostream>
#include<cstdio>
using namespace std;
int n,x,mx,cur;
bool u[222222];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=2*n;i++)
	{
		scanf("%d",&x);
		if (u[x]) 
		{
			u[x]=0;
			cur--;
		}
		else
		{
			u[x]=1;
			cur++;
		}
		mx=max(mx,cur);
	}
	printf("%d\n",mx);
	return 0;
}