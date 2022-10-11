#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000005],k[1000005];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	int last=n;
	for (int i=n-1;i>=0;i--)
	{
		ans+=!k[i];
		last=min(last,i-1);
		for (;last>=max(i-arr[i],0);last--)
		k[last]=1;
		last++;
	}
	printf("%d",ans);
}