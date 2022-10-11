#include <iostream>
using namespace std;
int arr[1000005];
int main()
{
	int cnt=0;
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		cnt+=(arr[i]%2);
	}
	if (!cnt)
	printf("Second");
	else
	printf("First");
}