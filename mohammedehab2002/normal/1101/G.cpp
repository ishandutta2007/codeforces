#include <iostream>
#include <algorithm>
using namespace std;
int arr[200005],bas[35];
void add(int x)
{
	for (int i=29;i>=0;i--)
	{
		if (x&(1<<i))
		x^=bas[i];
	}
	for (int i=29;i>=0;i--)
	{
		if (x&(1<<i))
		{
			bas[i]=x;
			return;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		arr[i]^=arr[i-1];
	}
	if (!arr[n])
	{
		printf("-1");
		return 0;
	}
	for (int i=n;i>0;i--)
	add(arr[i]);
	printf("%d",30-count(bas,bas+30,0));
}