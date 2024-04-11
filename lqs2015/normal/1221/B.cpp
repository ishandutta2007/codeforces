#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if ((i+j)%2==0) printf("B");
			else printf("W");
		}
		printf("\n");
	}
	return 0;
}