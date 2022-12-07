#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
			if(j==i) printf("%d ",k);
			else printf("0 ");
		printf("0\n");
	}
	for(int i=1;i<n;i++)
		printf("0 ");
	printf("%d\n",k);
	return 0;
}