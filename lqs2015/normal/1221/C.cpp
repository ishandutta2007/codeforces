#include<bits/stdc++.h>
using namespace std;
int test,a,b,c;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n",min(min(a,b),(a+b+c)/3));
	}
	return 0;
}