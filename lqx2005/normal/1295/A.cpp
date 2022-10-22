#include<bits/stdc++.h>
using namespace std;
int T,n;
int main()
{
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++)
	{
		scanf("%d",&n);
		if(n%2==0) for(int i=1;i<=n/2;i++) printf("1");
		else 
		{
			printf("7");
			for(int i=1;i<=n/2-1;i++) printf("1");
		}
		printf("\n");
	}
	return 0;
}