#include <iostream>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	printf("100003 100003\n");
	for (int i=1;i<n-1;i++)
	printf("%d %d 1\n",i,i+1);
	printf("%d %d %d\n",n-1,n,100005-n);
	m-=(n-1);
	if (!m)
	return 0;
	for (int i=1;i<=n;i++)
	{
		for (int x=i+2;x<=n;x++)
		{
			printf("%d %d 100004\n",i,x);
			m--;
			if (!m)
			return 0;
		}
	}
}