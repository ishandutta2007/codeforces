#include<iostream>
#include<cstdio>
using namespace std;
int n,x,cnt;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (x&1) cnt++;
	}
	if (!cnt) printf("Second\n");
	else printf("First\n");
	return 0;
}