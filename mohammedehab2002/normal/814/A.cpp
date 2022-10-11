#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;
int arr[100005];
int main()
{
	int n,m,a,x;
	scanf("%d%d",&n,&m);
	if (m>1)
	{
		printf("Yes");
		return 0;
	}
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if (arr[i]==0)
		x=i;
		else if (i && arr[i]<=arr[i-1])
		{
			printf("Yes");
			return 0;
		}
	}
	scanf("%d",&a);
	if (!x && a>=arr[1])
	printf("Yes");
	else if (a<=arr[x-1] || (x!=n-1 && a>=arr[x+1]))
	printf("Yes");
	else
	printf("No");
}