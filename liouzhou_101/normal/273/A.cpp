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

#define X first
#define Y second

const int MaxN=1<<17;

int n,m;
ll v[MaxN<<1],a[MaxN<<1];

void add(int k,int L,int R,int x,int y,ll p)
{
	v[k]=max(v[k],p);
	if (L==x&&R==y)
	{
		a[k]=max(a[k],p);
		return;
	}
	int m=(L+R)>>1;
	if (y<=m)
		add(k<<1,L,m,x,y,p);
	else if (x>m)
		add(k<<1|1,m+1,R,x,y,p);
	else
	{
		add(k<<1,L,m,x,m,p);
		add(k<<1|1,m+1,R,m+1,y,p);
	}
}

ll get(int k,int L,int R,int x,int y)
{
	if (L==x&&R==y)
		return v[k];
	int m=(L+R)>>1;
	if (y<=m)
		return max(a[k],get(k<<1,L,m,x,y));
	else if (x>m)
		return max(a[k],get(k<<1|1,m+1,R,x,y));
	else
		return max(a[k],max(get(k<<1,L,m,x,m),get(k<<1|1,m+1,R,m+1,y)));
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		add(1,1,MaxN,i,i,x);
	}
	cin>>m;
	while (m--)
	{
		int w,h;
		scanf("%d%d",&w,&h);
		ll p=get(1,1,MaxN,1,w);
		printf("%I64d\n",p);
		add(1,1,MaxN,1,w,p+h);
	}
	return 0;
}