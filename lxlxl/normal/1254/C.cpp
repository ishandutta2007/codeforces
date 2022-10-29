#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 2100;

int n;
ll query(int ti,int x,int y,int z)
{
	printf("%d %d %d %d\n",ti,x,y,z);
	fflush(stdout);
	ll re;
	scanf("%lld",&re);
	return re;
}
int p1,p2;
struct node
{
	int i,sig;
	ll s;
}a[maxn];
inline bool cmpsig(const node &x,const node &y){ return x.sig<y.sig; }
inline bool cmps(const node &x,const node &y){ return x.s<y.s; }
inline bool cmps2(const node &x,const node &y){ return x.s>y.s; }
int t[maxn],tp;

void solve(int l,int r,int op)
{
	int mxi=l;
	for(int i=l;i<=r;i++) 
	{
		a[i].s=query(1,p1,p2,a[i].i);
		if(a[mxi].s<a[i].s) mxi=i;
	}
	for(int i=l;i<=r;i++)
		a[i].sig=i==mxi?0:query(2,p1,a[mxi].i,a[i].i);
	sort(a+l,a+r+1,cmpsig);
	
	int mid=l;
	while(a[mid].sig!=0) mid++;
	if(l<mid)
	{
		sort(a+l,a+mid,cmps);
		for(int i=l;i<mid;i++) t[++tp]=a[i].i;
	}
	t[++tp]=a[mid].i;
	if(mid<r)
	{
		sort(a+mid+1,a+r+1,cmps2);
		for(int i=mid+1;i<=r;i++) t[++tp]=a[i].i;
	}
}

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%d",&n);
	p1=1,p2=2;
	for(int i=3;i<=n;i++) a[i].i=i,a[i].sig=query(2,p1,p2,i);
	sort(a+3,a+n+1,cmpsig);
	int mid;
	for(mid=3;mid<=n&&a[mid].sig==-1;mid++); mid--;
	
	t[++tp]=1;
	if(3<=mid) solve(3,mid,0);
	t[++tp]=2;
	mid++;
	if(mid<=n) solve(mid,n,1);
	
	printf("0");
	for(int i=1;i<=tp;i++) printf(" %d",t[i]);
	
	return 0;
}