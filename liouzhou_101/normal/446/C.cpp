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
#include<unordered_set>
#include<unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=300010;
const ll MOD=1000000009;

int n,m;
ll a[MaxN];

ll A[3][3]={{1,1,0},{0,1,1},{0,1,0}};
ll P[MaxN][3][3];

inline ll getsum(ll a,ll b,ll k)
{
	if (k<=0) return 0;
	if (k==1) return a;
	if (k==2) return (a+b)%MOD;
	return (P[k-1][0][0]*a+P[k-1][0][1]*b+P[k-1][0][2]*a)%MOD;
}

inline ll getkth(ll a,ll b,ll k)
{
	return (getsum(a,b,k)-getsum(a,b,k-1))%MOD;
}

struct node
{
	ll da;
	ll db;
	ll sum;
}p[MaxN*4];

void add(int k,int L,int R,int x,int y,ll a,ll b)
{
	if (L==x&&R==y)
	{
		(p[k].da+=a)%=MOD;
		(p[k].db+=b)%=MOD;
		return;
	}
	p[k].sum+=getsum(a,b,y-x+1);
	int m=(L+R)>>1;
	if (y<=m)
		add(k<<1,L,m,x,y,a,b);
	else if (x>m)
		add(k<<1|1,m+1,R,x,y,a,b);
	else
	{
		add(k<<1,L,m,x,m,a,b);
		ll ta=getkth(a,b,m-x+2);
		ll tb=getkth(a,b,m-x+3);
		add(k<<1|1,m+1,R,m+1,y,ta,tb);
	}
}

ll get(int k,int L,int R,int x,int y)
{
	if (L==x&&R==y)
		return (p[k].sum+getsum(p[k].da,p[k].db,R-L+1))%MOD;
	int m=(L+R)>>1;
	ll ans=(getsum(p[k].da,p[k].db,y-L+1)-getsum(p[k].da,p[k].db,x-L))%MOD;
	if (y<=m)
		return (get(k<<1,L,m,x,y)+ans)%MOD;
	if (x>m)
		return (get(k<<1|1,m+1,R,x,y)+ans)%MOD;
	return (get(k<<1,L,m,x,m)+get(k<<1|1,m+1,R,m+1,y)+ans)%MOD;
}

int main()
{
	cin>>n>>m;
	for (int i=0;i<3;++i)
		for (int j=0;j<3;++j)
			P[0][i][j]=i==j;
	for (int c=1;c<=n;++c)
	{
		for (int k=0;k<3;++k)
			for (int i=0;i<3;++i)
				for (int j=0;j<3;++j)
					P[c][i][j]=(P[c][i][j]+P[c-1][i][k]*A[k][j])%MOD;
	}
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		a[i]=(a[i-1]+x)%MOD;
	}
	while (m--)
	{
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if (t==1)
		{
			add(1,1,n,x,y,1,1);
		}
		else
		{
			ll ans=get(1,1,n,x,y)+a[y]-a[x-1];
			ans=(ans%MOD+MOD)%MOD;
			printf("%d\n",(int)ans);
		}
	}
	return 0;
}