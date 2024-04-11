#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,n,a,b,x;
bool f;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d",&n,&a,&b);
		f=0;
		for (int i=1;i<=a;i++)
		{
			scanf("%d",&x);
			if (x==n) f=1;
		}
		for (int i=1;i<=b;i++)
		{
			scanf("%d",&x);
			if (x==n) f=0;
		}
		if (f) printf("YES\n");
		else printf("NO\n");
	}
	return Accepted;
}