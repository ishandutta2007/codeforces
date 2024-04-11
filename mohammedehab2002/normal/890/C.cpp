#include <iostream>
using namespace std;
int arr[200005];
bool last[200005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	int ans=1;
	last[0]=1;
	for (int i=1;i<=n;i++)
	{
		if (!last[arr[i]])
		ans++;
		else
		last[arr[i]]=0;
		last[i]=1;
	}
	printf("%d",ans);
}