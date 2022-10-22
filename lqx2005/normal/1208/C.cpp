#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1000;
ll n;
ll a[N+5][N+5];
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n/4;i++)
	{
		for(ll j=1;j<=n/4;j++)
		{
			for(ll k=1;k<=4;k++)
			{
				for(ll l=1;l<=4;l++)
				{
					a[(i-1)*4+k][(j-1)*4+l]=(i-1)*4*n+(j-1)*16+(k-1)*4+l-1;
				}
			}
		}
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			printf("%lld ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}