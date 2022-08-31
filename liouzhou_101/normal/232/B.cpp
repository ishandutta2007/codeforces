#include<cstdio>
#include<iostream>

using namespace std;

const long long MOD=1000000007;
const int MaxN=120;

int n,k,m1;
long long m,m0;

long long C[MaxN][MaxN];
long long F[MaxN][MaxN*MaxN];
long long v[MaxN];
long long a[MaxN][MaxN];

long long power(long long x,long long p)
{
	if (!p) return 1;
	long long t=power(x,p>>1);
	t=t*t%MOD;
	if (p&1) t=t*x%MOD;
	return t;
}

int main()
{
	cin>>n>>m>>k;
	//m=m0*n+m1
	m0=m/n;
	m1=m%n;
	for (int i=1;i<=n;++i)
		v[i]=m0;
	for (int i=1;i<=m1;++i)
		v[i]++;
	for (int i=0;i<=n;++i)
		C[i][0]=1;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	for (int x=0;x<=n;++x)
		for (int i=1;i<=n;++i)
			a[x][i]=power(C[n][x],v[i]);
	F[0][0]=1;
	for (int i=0;i<n;++i)
		for (int j=0;j<=k;++j)
		{
			if (!F[i][j]) continue;
			for (int x=0;x<=n;++x)
				(F[i+1][j+x]+=F[i][j]*a[x][i+1])%=MOD;
		}
	cout<<F[n][k]<<endl;
	return 0;
}