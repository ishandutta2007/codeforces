#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,a,b,g;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&a,&b);
		if (__gcd(a,b)==1) printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}