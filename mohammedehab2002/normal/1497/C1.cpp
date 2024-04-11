#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if (n%2)
		printf("%d %d 1\n",n/2,n/2);
		else if (n%4)
		printf("%d %d 2\n",n/2-1,n/2-1,2);
		else
		printf("%d %d %d\n",n/2,n/4,n/4);
	}
}