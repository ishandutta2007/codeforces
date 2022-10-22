#include <bits\stdc++.h>
using namespace std;
int n,m,k;
int b=10000;
int a[1000];
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]>0 && a[i]<=k)
		{
			if(abs(i-m)<b) b=abs(i-m);
		}
	}
	b=b*10;
	printf("%d",b);
	return 0;
}