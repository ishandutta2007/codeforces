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
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MOD=1000000000;
const int MaxN=1000100;

struct matrix
{
	int v[2][2];
	matrix ()
	{
		memset(v,0,sizeof(v));
	}
};

matrix operator * (matrix a,matrix b)
{
	matrix c;
	for (int i=0;i<2;++i)
		for (int j=0;j<2;++j)
			for (int k=0;k<2;++k)
				c.v[i][j]=(c.v[i][j]+(ll)a.v[i][k]*b.v[k][j])%MOD;
	return c;
}

matrix A[MaxN];

struct node
{
	int a[2];
	node () {}
	node (int x,int y)
	{
		a[0]=x;
		a[1]=y;
	}
	node delta(int x)
	{
		return node(((ll)a[0]*A[x].v[0][0]+(ll)a[1]*A[x].v[0][1])%MOD,((ll)a[0]*A[x].v[1][0]+(ll)a[1]*A[x].v[1][1])%MOD);
	}
	node operator + (node p)
	{
		return node((a[0]+p.a[0])%MOD,(a[1]+p.a[1])%MOD);
	}
}v[MaxN];

int d[MaxN];

int n,m;
int a[MaxN];

void update(int k,int L,int R)
{
	int m=(L+R)>>1;
	v[k]=v[k<<1]+v[k<<1|1].delta(m-L+1);
}

void clear(int k,int L,int R)
{
	
}

void build(int k,int L,int R)
{
	if (L==R)
	{
		v[k].a[0]=a[L];
		v[k].a[1]=0;
		return;
	}
	int m=(L+R)>>1;
	build(k<<1,L,m);
	build(k<<1|1,m+1,R);
	update(k,L,R);
}

void change(int k,int L,int R,int x,int p)
{
	if (L==R)
	{
		v[k].a[0]=p;
		v[k].a[1]=0;
		return;
	}
	clear(k,L,R);
	int m=(L+R)>>1;
	if (x<=m)
		change(k<<1,L,m,x,p);
	else
		change(k<<1|1,m+1,R,x,p);
	update(k,L,R);
}

node query(int k,int L,int R,int x,int y)
{
	if (L==x&&R==y)
		return v[k];
	clear(k,L,R);
	int m=(L+R)>>1;
	if (y<=m)
		return query(k<<1,L,m,x,y);
	if (x>m)
		return query(k<<1|1,m+1,R,x,y);
	node v1=query(k<<1,L,m,x,m);
	node v2=query(k<<1|1,m+1,R,m+1,y);
	return v1+v2.delta(m-x+1);
}

void add(int k,int L,int R,int x,int y,int p)
{
	if (L==x&&R==y)
	{
		d[k]+=p;
		
	}
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	A[0].v[0][0]=A[0].v[1][1]=1;
	A[1].v[0][0]=A[1].v[0][1]=A[1].v[1][0]=1;
	for (int i=2;i<=n;++i)
		A[i]=A[i-1]*A[1];
	build(1,1,n);
	while (m--)
	{
		int t;
		scanf("%d",&t);
		if (t==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			change(1,1,n,x,y);
		}
		else if (t==2)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",query(1,1,n,x,y).a[0]);
		}
		else if (t==3)
		{
			int x,y,d;
			scanf("%d%d%d",&x,&y,&d);
			add(1,1,n,x,y,d);
		}
	}
	return 0;
}