#include <iostream>
using namespace std;
int arr[100005];
int main()
{
	int n,c,ans=0;
	scanf("%d%d",&n,&c);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		ans++;
		if (!i)
		continue;
		if (arr[i]-arr[i-1]>c)
		ans=1;
	}
	printf("%d",ans);
}