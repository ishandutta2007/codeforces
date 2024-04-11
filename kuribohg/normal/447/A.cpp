#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n,p,k;
bool used[10100];
int main()
{
	scanf("%d%d",&p,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		k%=p;
		if(!used[k]) used[k]=true;
		else {printf("%d\n",i);return 0;}
	}
	puts("-1");
	return 0;
}