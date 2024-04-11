#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define ll long long
ll n,m,L,R,x,y;
struct Matrix
{
	ll v[2][2];
	Matrix(bool fl=0) {v[0][0]=v[0][1]=v[1][0]=v[1][1]=0;if(fl) v[0][0]=v[1][1]=1;}
	Matrix operator * (Matrix t)
	{
		Matrix res;
		for(int i=0;i<2;++i) for(int j=0;j<2;++j) for(int k=0;k<2;++k)
			res.v[i][j]=(res.v[i][j]+v[i][k]*t.v[k][j]%MOD)%MOD;return res;
	}
}a;
ll qPow(ll x,ll y)
{
	ll res=1;
	for(;y;y>>=1,x=x*x%MOD) if(y&1) res=res*x%MOD;return res;
}
Matrix MatQPow(Matrix x,ll y)
{
	Matrix res(1);
	for(;y;y>>=1,x=x*x) if(y&1) res=res*x;return res;
}
int main()
{
	scanf("%lld %lld %lld %lld",&n,&m,&L,&R);n*=m;
	if(n&1) {printf("%lld\n",qPow(R-L+1,n));return 0;}
	x=R-L+1>>1;if((L&1) && (R&1)) ++x;y=R-L+1-x;
	a.v[0][0]=y;a.v[0][1]=x;a.v[1][0]=x;a.v[1][1]=y;
	a=MatQPow(a,n);printf("%lld\n",a.v[0][0]);return 0;
}