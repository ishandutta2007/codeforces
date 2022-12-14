#include<bits/stdc++.h>
using namespace std;
int test,n,x,a,b;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d%d",&n,&x,&a,&b);
		printf("%d\n",min(n-1,abs(a-b)+x));
	}
	return 0;
}