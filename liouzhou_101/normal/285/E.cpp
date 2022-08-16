#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
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

#define X first
#define Y second

const int MaxN=1010;
const int MOD=1000000007;

int n,k;
int C[MaxN][MaxN];
int F[MaxN][MaxN][4];
int p[MaxN];

void add(int &x,int y)
{
	x=(x+y)%MOD;
}

int main()
{
	cin>>n>>k;
	for (int i=0;i<=n;++i)
		C[i][0]=1;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	F[0][0][1]=1;
	for (int i=1;i<=n;++i)
		for (int j=0;j<=i;++j)
			for (int s=0;s<4;++s)
			{
				add(F[i][j][s/2],F[i-1][j][s]);
				add(F[i][j+1][s/2+2],F[i-1][j][s]);
				if (s%2==0) add(F[i][j+1][s/2],F[i-1][j][s]);
			}
	for (int i=0;i<=n;++i)
	{
		add(p[i],F[n][i][0]);
		add(p[i],F[n][i][1]);
		for (int j=1;j<=n-i;++j)
			p[i]=(ll)p[i]*j%MOD;
	}
	for (int i=n;i>=0;--i)
		for (int j=i+1;j<=n;++j)
			add(p[i],MOD-(ll)p[j]*C[j][i]%MOD);
	cout<<p[k]<<endl;
	return 0;
}