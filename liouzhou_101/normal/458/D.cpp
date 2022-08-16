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
#include<list>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=100010;

ld a[MaxN],b[MaxN];

ld C(int n,int m)
{
	if (n<0||m<0||n<m) return -1e100;
	return b[n]-b[m]-b[n-m];
}

ld A(int n,int m)
{
	if (n<0||m<0||n<m) return -1e100;
	return b[n]-b[n-m];
}

ld p[311][311];

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=1;i<=m;++i)
	{
		a[i]=log(i);
		b[i]=b[i-1]+a[i];
	}
	ld ans=0;
	for (int i=0;i<=n;++i)
		for (int j=0;j<=n;++j)
		{
			//ans+=exp((i+j)*a[2]+C(m,n*(i+j)-i*j)+C(m-n*(i+j)+i*j,k-n*(i+j)+i*j)+C(m-k,n*n-k)+C(n,i)+C(n,j)-C(m,n*n)-C(m,k));
			//p[i][j]=exp(A(m,n*(i+j)-i*j)+C(m-n*(i+j+2)+(i+1)*(j+1),k-n*(i+j)+i*j)+A(m-n*(i+j)+i*j,n*n-n*(i+j)+i*j)+C(n,i)+C(n,j)-A(m,n*n)-C(m,k));
			ans+=exp(C(m-n*(i+j)+i*j,k-n*(i+j)+i*j)+C(n,i)+C(n,j)-C(m,k));
		}
	/*
	for (int i=0;i<=n;++i)
		for (int j=0;j<=n;++j)
		{
			//ld t=p[i][j]-p[i+1][j]-p[i][j+1]+p[i+1][j+1];
			ld t=p[i][j];
			for (int k=1;k<=i+j;++k) t*=2;
			ans+=t;
		}
	*/
	printf("%.20f\n",(double)ans);
	return 0;
}