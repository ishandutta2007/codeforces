//This is meng meng da mjy>_<
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000007
typedef long long ll;
using namespace std;

void read(ll &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 100010
ll n,v;
ll tmpx[maxn],tmpy[maxn];
struct Point
{
	ll x,y,id;
}	a[maxn];
int c[maxn],f[maxn];
ll num[maxn],cnt;
int query(int t)
{
	int mjy=0;
	for (int i=t;i;i-=i&(-i))	mjy=max(mjy,c[i]);
	return mjy;
}
void insert(int t,int val)
{
	for (int i=t;i<=cnt;i+=i&(-i))	c[i]=max(c[i],val);
}
bool cmp(Point a,Point b)
{
	if (a.x!=b.x)	return a.x<b.x;
	return a.y<b.y;
}

int main()
{
	read(n);
	for (int i=1;i<=n;i++)	read(tmpx[i]),read(tmpy[i]);
	read(v);
	for (int i=1;i<=n;i++)
	{
		a[i].x=-tmpx[i]+v*tmpy[i];
		a[i].y=tmpx[i]+v*tmpy[i];
		a[i].id=i;
		num[i]=a[i].y;
	}
	num[n+1]=0;
	sort(num+1,num+n+2);
	cnt=unique(num+1,num+n+2)-(num+1);
	for (int i=1;i<=n;i++)	a[i].y=lower_bound(num+1,num+cnt+1,a[i].y)-num;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		f[i]=query(a[i].y)+1;
		insert(a[i].y,f[i]);
	}
	int mjy1=0;
	for (int i=1;i<=n;i++)	mjy1=max(mjy1,f[i]);
	memset(f,0,sizeof(f));
	memset(c,0,sizeof(c));
	n++;
	a[n].id=n;
	a[n].y=lower_bound(num+1,num+cnt+1,0)-num;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		f[i]=query(a[i].y)+1;
		if (a[i].id==n || f[i]>1)	insert(a[i].y,f[i]);
	}
	int mjy2=0;
	for (int i=1;i<=n;i++)	mjy2=max(mjy2,f[i]);
	printf("%d %d\n",mjy2-1,mjy1);
	return 0;
}