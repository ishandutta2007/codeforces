#include <iostream>
using namespace std;
bool b[205];
int arr[205];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<2*n;i++)
	scanf("%d",&arr[i]);
	int ans=0;
	for (int i=0;i<2*n;i++)
	{
		if (b[i])
		continue;
		int x=i+1,cnt=0;
		for (;arr[i]!=arr[x];x++)
		cnt+=!b[x];
		ans+=cnt;
		b[x]=1;
	}
	printf("%d",ans);
}