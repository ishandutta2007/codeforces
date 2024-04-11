#include<bits/stdc++.h>
using namespace std;

int a,b,c,n;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&n);
	if (a>n || b>n || a<c || b<c)
	{
		printf("-1\n");
		return 0;
	}
	int t=n-(a+b-c);
	if (t<=0)	printf("-1\n");else printf("%d\n",t);
	return 0;
}