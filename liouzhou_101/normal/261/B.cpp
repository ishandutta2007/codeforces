#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;
typedef __float128 real;

#define X first
#define Y second

const int MaxN=60;

int n,p;
int a[MaxN];
real h[MaxN];
ld F[MaxN][MaxN][MaxN];
real ans;

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	cin>>p;
	F[0][0][0]=1;
	for (int i=0;i<n;++i)
		for (int j=0;j<=i;++j)
			for (int k=0;k<=p;++k)
			{
				F[i+1][j][k]+=F[i][j][k];
				if (k+a[i+1]<=p) F[i+1][j+1][k+a[i+1]]+=F[i][j][k];
			}
	h[0]=1;
	for (int i=1;i<=n;++i)
		h[i]=h[i-1]*i;
	for (int j=0;j<=n;++j)
		for (int k=0;k<=p;++k)
			ans+=F[n][j][k]*h[j]*h[n-j];
	printf("%.20lf\n",(double)(ans/h[n]-1));
	return 0;
}