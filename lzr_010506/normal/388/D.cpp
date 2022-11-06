#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
const int N = 35;

int f[N][2][N], k,a[N],n,ans;


int main()
{
	scanf("%d",&k);
	k ++;
	for(; k; k >>= 1) a[++ n] = k & 1;
	f[n][0][0] = 1;
	for(int i = n; i; i --)
		for(int j = 0; j < 2; j ++)
			for(int k = 0; k < n; k ++)
			{
				int cur = f[i][j][k];
				if(!cur) continue;
				if(j || a[i]) f[i - 1][j][k + 1] = (f[i - 1][j][k + 1] + cur) % mod;
				f[i - 1][j | a[i]][k] += (ll)cur * (k ? 1 << k - 1: 1) % mod;
				f[i - 1][j | a[i]][k] %= mod;
				if((j || a[i]) && k) f[i - 1][j][k] += ((ll)cur*(1 << k - 1) % mod), f[i - 1][j][k] %= mod;
			}
	for(int i = 0; i < n; i ++)
		ans +=  f[0][1][i], ans %= mod;
	printf("%d\n", ans);
	return 0;
}