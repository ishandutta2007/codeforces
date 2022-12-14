#include<bits/stdc++.h>
using namespace std;
int test,a,b;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&a,&b);
		if (a>=b)
		{
			printf("YES\n");
			continue;
		}
		if (a==2 && b==3)
		{
			printf("YES\n");
			continue;
		}
		if (a<4)
		{
			printf("NO\n");
		}
		else printf("YES\n"); 
	}
	return 0;
}