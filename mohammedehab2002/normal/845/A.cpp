#include <iostream>
#include <algorithm>
using namespace std;
int arr[205];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<2*n;i++)
	scanf("%d",&arr[i]);
	sort(arr,arr+2*n);
	if (arr[n]==arr[n-1])
	printf("NO");
	else
	printf("YES");
}