#include <iostream>
using namespace std;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int a=0;
	for (int i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		a+=t;
		int tmp=min(k,min(a,8));
		a-=tmp;
		k-=tmp;
		if (k==0)
		{
			printf("%d",i+1);
			return 0;
		}
	}
	printf("-1");
}