#include <iostream>
using namespace std;
int cum[1000005][15];
int f(int x)
{
	if (x<10)
	return x;
	int ans=1;
	while (x)
	{
		if (x%10)
		ans*=(x%10);
		x/=10;
	}
	return f(ans);
}
int main()
{
	for (int i=1;i<=1000000;i++)
	{
		for (int x=1;x<10;x++)
		cum[i][x]=cum[i-1][x];
		cum[i][f(i)]++;
	}
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",cum[r][k]-cum[l-1][k]);
	}
}