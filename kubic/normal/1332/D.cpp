#include <bits/stdc++.h>
using namespace std;
int T,n,X=1<<17;
int main()
{
	scanf("%d",&n);
	printf("3 3\n");
	printf("%d %d 0\n",X+n,n);
	printf("%d %d %d\n",X,X+n,n);
	printf("0 0 %d\n",n);
	return 0;
}