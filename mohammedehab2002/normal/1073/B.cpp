#include <iostream>
using namespace std;
int inv[200005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		inv[a]=i;
	}
	int cur=0;
	while (n--)
	{
		int a;
		scanf("%d",&a);
		printf("%d ",max(inv[a]-cur+1,0));
		cur=max(cur,inv[a]+1);
	}
}