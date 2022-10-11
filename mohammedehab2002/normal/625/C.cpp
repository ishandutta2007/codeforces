#include <iostream>
using namespace std;
int arr[505][505];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	k--;
	int cur=n*n,cur2=1,ans=0;
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<k;x++)
		arr[i][x]=cur2++;
		for (int x=n-1;x>=k;x--)
		arr[i][x]=cur--;
		ans+=arr[i][k];
	}
	printf("%d\n",ans);
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<n;x++)
		printf("%d ",arr[i][x]);
		printf("\n");
	}
}