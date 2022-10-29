#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<vector>
#include<string>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 130;

struct matrix
{
	double a[maxn][maxn];
}st,zero;
int n,m;
double a[maxn];

matrix operator*( matrix x,matrix y )
{
	matrix ret;
	for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++)
			ret.a[i][j]=0;
	for( int i=0;i<=m;i++ )
	{
		for( int j=0;j<=m;j++ )
		{
			for( int k=0;k<=m;k++ )
				ret.a[i][j] += x.a[i][k]*y.a[k][j];
		}
	}
	return ret;
}

matrix pow( int k )
{
	matrix ret = zero;
	int now=0,nowp=1;
	matrix tmp = st;
	while( now != k )
	{
		if( k&nowp )
		{
			ret = ret*tmp;
			now |= nowp;
		}
		nowp<<=1; tmp = tmp*tmp;
	}
	return ret;
}

int main()
{
	scanf("%d%d",&n,&m);
	for( int i=0;i<=m;i++ )
		scanf("%lf",&a[i]);
	int t=1;
	while(t<=m) t*=2;
	t--;
	for( int i=0;i<=t;i++ )
	{
		for( int j=0;j<=m;j++ )
		{
			st.a[i][i^j] = a[j];
		}
		zero.a[i][i] = 1.0;
	}
	m=t;
	matrix k = pow( n );
	printf("%lf\n",1-k.a[0][0]);
	
	return 0;
}