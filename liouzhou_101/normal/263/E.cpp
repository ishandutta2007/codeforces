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

int n,m,k;

struct matrix
{
	int n,m;
	ll a[MaxN][MaxN];
	ll sy[MaxN][MaxN];
	ll ty[MaxN][MaxN];
	ll sv[MaxN*2][MaxN];
	ll tv[MaxN][MaxN];
	ll st[MaxN][MaxN];
	void set(int _n,int _m)
	{
		n=_n;
		m=_m;
	}
	ll getsy(int y,int L,int R)
	{
		ll p=sy[R][y];
		if (L>=2) p-=sy[L-1][y];
		return p;
	}
	ll getsv(int p,int L,int R)
	{
		if (p<=1||p>n+m) return 0;
		ll s=sv[p][min(R,n)];
		if (L>=2) s-=sv[p][L-1];
		return s;
	}
	void init()
	{
		for (int j=1;j<=m;++j)
			for (int i=1;i<=n;++i)
				sy[i][j]=sy[i-1][j]+a[i][j];
		for (int j=1;j<=m;++j)
			for (int i=1;i<=n;++i)
				ty[i][j]=ty[i-1][j]+(k+1)*a[i][j]-getsy(j,i-k,i);
		for (int p=2;p<=n+m;++p)
			for (int i=1;i<=n;++i)
			{
				sv[p][i]=sv[p][i-1];
				if (p-i>=1&&p-i<=m) sv[p][i]+=a[i][p-i];
			}
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j)
				tv[i][j]=tv[i][j-1]+getsy(j,i-k+1,i)-getsv(i+j-k,i-k+1,i);
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j)
				st[i][j]=st[i][j-1]+ty[i][j]-tv[i][j-1];
	}
	ll calc(int i,int j)
	{
		return st[i][j]-ty[i][j];
	}
}T1,T2,T3,T4;

void init()
{
	cin>>n>>m>>k;
	T1.set(n,m);
	T2.set(m,n);
	T3.set(n,m);
	T4.set(m,n);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			int x;
			scanf("%d",&x);
			T1.a[i][j]=T2.a[m-j+1][i]=T3.a[n-i+1][m-j+1]=T4.a[j][n-i+1]=x;
		}
	T1.init();
	T2.init();
	T3.init();
	T4.init();
}

void work()
{
	ll ans=-1;
	int a=k,b=k;
	for (int i=k;i<=n-k+1;++i)
		for (int j=k;j<=m-k+1;++j)
		{
			ll p=T1.calc(i,j)+T2.calc(m-j+1,i)+T3.calc(n-i+1,m-j+1)+T4.calc(j,n-i+1)+k*T1.a[i][j];
			if (p>ans)
			{
				ans=p;
				a=i;
				b=j;
			}
		}
	cout<<a<<" "<<b<<endl;
}

int main()
{
	init();
	work();
	return 0;
}