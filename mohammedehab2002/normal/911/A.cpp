#include <iostream>
using namespace std;
int arr[100005];
int main()
{
	int n,mn=(1<<30);
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		mn=min(mn,arr[i]);
	}
	int l=-(1<<30),ans=(1<<30);
	for (int i=0;i<n;i++)
	{
		if (arr[i]==mn)
		{
			ans=min(ans,i-l);
			l=i;
		}
	}
	printf("%d",ans);
}