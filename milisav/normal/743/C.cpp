#include <iostream>
#include <cstdio>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if(n!=1) printf("%d %d %d",n,n+1,n*(n+1));
	else printf("-1");
	return 0;
}