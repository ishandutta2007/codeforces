#include<bits/stdc++.h>
using namespace std;

const int maxn=110;
int a[maxn];
int n;
int main()
{
	scanf("%d",&n);
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans+=a[i];
	}
	sort(a+1,a+n+1);
	int lim=4.5*n;
	if (n&1)	lim++;
	int i=1;
	while (ans<lim)
	{
		ans+=5-a[i];
		i++;
	}
	printf("%d\n",i-1);
	return 0;
}