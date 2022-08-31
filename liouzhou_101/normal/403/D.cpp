#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const ll P=1000000007;

int n,k;
ll C[1010][1010],F[55][1010],p[1010],power[1010][1010];

void solve()
{
	int m=(1+k)*k/2;
	if (m>n)
	{
		puts("0");
		return;
	}
	ll ans=0;
	for (int i=m;i<=n;++i)
		ans+=F[k][i]*power[k+1][n-i]%P;
	(ans*=p[k])%=P;
	printf("%d\n",(int)ans);
}

int main()
{
	for (int i=1;i<=1000;++i)
	{
		C[i][0]=1;
		for (int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
	}
	for (int k=1;k<=44;++k)
	{
		F[k][(1+k)*k/2]=1;
		for (int i=1;i<=k;++i)
			for (int j=1000;j>=1;--j)
			{
				if (j-(k-i+1)>=0) (F[k][j]+=F[k][j-(k-i+1)])%=P;
			}
	}
	p[0]=1;
	for (int i=1;i<=44;++i)
		p[i]=p[i-1]*i%P;
	for (int i=1;i<=1000;++i)
	{
		power[i][0]=1;
		for (int j=1;j<=1000;++j)
			power[i][j]=power[i][j-1]*i%P;
	}
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&k);
		solve();
	}
	return 0;
}