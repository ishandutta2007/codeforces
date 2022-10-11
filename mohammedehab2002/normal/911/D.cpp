#include <iostream>
using namespace std;
int arr[1505];
bool check(int x)
{
	return ((x*(x-1)/2)%2==0);
}
int main()
{
	int n,q,inv=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		for (int x=0;x<i;x++)
		{
			if (arr[i]<arr[x])
			inv^=1;
		}
	}
	scanf("%d",&q);
	while (q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if (!check(r-l+1))
		inv^=1;
		if (inv)
		printf("odd\n");
		else
		printf("even\n");
	}
}