#include <bits/stdc++.h>
#define MAXN 1007
using namespace std;
int a[MAXN],s[MAXN];
int main()
{
	int n; scanf("%d",&n);
	for(int i=n;i>=2;i--)
	{
		printf("? 1 %d\n",i);
		fflush(stdout);
		scanf("%d",&s[i]);
	}
	for(int i=n;i>2;i--) a[i]=s[i]-s[i-1];
	printf("? 2 3\n");
	fflush(stdout);
	scanf("%d",&s[1]);
	a[2]=s[1]-a[3];
	a[1]=s[2]-a[2];
	printf("!");
	for(int i=1;i<=n;i++) printf(" %d",a[i]);
	printf("\n");
	fflush(stdout);
}