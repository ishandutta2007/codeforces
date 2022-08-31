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
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=2010;
const int MOD=1000000007;

int n,m;
ll F[MaxN][MaxN],sF[MaxN][MaxN],tF[MaxN][MaxN],a[MaxN][MaxN],b[MaxN][MaxN],c[MaxN][MaxN],d[MaxN][MaxN];
ll ans;

int main()
{
	cin>>n>>m;
	for (int i=1;i<m;++i)
	{
		F[1][i]=1;
		sF[1][i]=(sF[1][i-1]+F[1][i])%MOD;
		tF[1][i]=(tF[1][i-1]+F[1][i]*i)%MOD;
	}
	for (int i=2;i<=n;++i)
		for (int j=1;j<m;++j)
		{
			//for (int k=1;k<=j;++k)
				//F[i][j]+=F[i-1][k]*(j-k+1);
			F[i][j]=((j+1)*sF[i-1][j]-tF[i-1][j])%MOD;
			sF[i][j]=(sF[i][j-1]+F[i][j])%MOD;
			tF[i][j]=(tF[i][j-1]+F[i][j]*j)%MOD;
		}
	for (int i=1;i<=n;++i)
		for (int j=1;j<m;++j)
		{
			a[i][j]=(a[i-1][j]+a[i][j-1]-a[i-1][j-1]+F[i][j])%MOD;
			b[i][j]=(b[i-1][j]+b[i][j-1]-b[i-1][j-1]+F[i][j]*i)%MOD;
			c[i][j]=(c[i-1][j]+c[i][j-1]-c[i-1][j-1]+F[i][j]*j)%MOD;
			d[i][j]=(d[i-1][j]+d[i][j-1]-d[i-1][j-1]+F[i][j]*i*j)%MOD;
		}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			/*
			for (int ii=1;ii<=n-i;++ii)
				for (int jj=1;jj<j;++jj)
					ans+=F[i][j]*F[ii][jj]*(j-jj+1)*(n-i-ii+1)*(m-j);
			*/		
					//F[i][j]*(kj-j)*(ki-i)=F[i][j]*ki*kj-F[i][j]*i*kj-F[i][j]*j*ki+F[i][j]*i*j
			//F[i][j]*(m-j)*F[ii][jj]*(j-jj+1)*(n-i-ii+1);
			
			int ii=n-i,jj=j-1,ki=n-i+1,kj=j+1;
			ans+=(a[ii][jj]*ki*kj-b[ii][jj]*kj-c[ii][jj]*ki+d[ii][jj])%MOD*(F[i][j]*(m-j)%MOD);
			ans+=F[i][j]*(n-i+1)*(m-j);
			ans%=MOD;
			
			//ans+=F[i][j]*(n-i+1)*(m-j);
		}
	cout<<ans<<endl;
	return 0;
}