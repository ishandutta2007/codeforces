#include <iostream>
#include <algorithm>
using namespace std;
bool sorted[100005];
int arr[100005];
int main()
{
	int n,idx=-1;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if (!i)
		sorted[i]=1;
		else
		sorted[i]=(sorted[i-1] && arr[i]>=arr[i-1]);
		if (!sorted[i])
		{
			if (idx==-1)
			idx=i,sorted[i]=1;
			else
			{
				printf("-1");
				return 0;
			}
		}
	}
	if (idx==-1)
	{
		printf("0");
		return 0;
	}
	if (sorted[idx] && arr[n-1]<=arr[0])
	printf("%d",n-idx);
	else
	printf("-1");
}