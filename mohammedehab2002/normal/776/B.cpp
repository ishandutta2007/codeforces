#include <iostream>
using namespace std;
bool prime[100005];
int main()
{
	int n,mx=1;
	scanf("%d",&n);
	for (int i=2;i<=n+1;i++)
	{
		if (!prime[i])
		{
			for (int x=2*i;x<=n+1;x+=i)
			prime[x]=1;
		}
	}
	if (n<=2)
	printf("1\n");
	else
	printf("2\n");
	for (int i=2;i<=n+1;i++)
	printf("%d ",prime[i]+1);
}