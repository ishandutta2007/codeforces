#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define sz size
#define fi first
#define se second
#define mp make_pair
#define pb push_back
void read(int &digit)
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
#define maxn 200010
int maxx[maxn<<2],minx[maxn<<2];
int n,m;
int a[maxn],b[maxn];

void build(int t,int l,int r)
{
	if (l==r)
	{
		maxx[t]=a[l];
		minx[t]=b[l];
		return;
	}
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
	maxx[t]=max(maxx[t<<1],maxx[t<<1|1]);
	minx[t]=min(minx[t<<1],minx[t<<1|1]);
}

int qmax(int t,int l,int r,int ql,int qr)
{
	if (l==ql && r==qr)	return maxx[t];
	int mid=(l+r)>>1;
	if (qr<=mid)	return qmax(t<<1,l,mid,ql,qr);
	if (ql>mid)	return qmax(t<<1|1,mid+1,r,ql,qr);
	return max(qmax(t<<1,l,mid,ql,mid),qmax(t<<1|1,mid+1,r,mid+1,qr));
}
int qmin(int t,int l,int r,int ql,int qr)
{
	if (l==ql && r==qr)	return minx[t];
	int mid=(l+r)>>1;
	if (qr<=mid)	return qmin(t<<1,l,mid,ql,qr);
	if (ql>mid)	return qmin(t<<1|1,mid+1,r,ql,qr);
	return min(qmin(t<<1,l,mid,ql,mid),qmin(t<<1|1,mid+1,r,mid+1,qr));
}
int main()
{
	read(n);
	for (int i=1;i<=n;i++)	read(a[i]);
	for (int i=1;i<=n;i++)	read(b[i]);
	build(1,1,n);
	ll zxo=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]>b[i])	continue;
		int zxo1,zxo2;
		if (a[i]==b[i])	zxo1=i-1;else
		{
			int l=i,r=n;
			while (l<r)
			{
				int mid=((l+r)>>1)+((l+r)&1);
				if (qmax(1,1,n,i,mid)<qmin(1,1,n,i,mid))	l=mid;else r=mid-1;
			}
			zxo1=l;
		}
		if (qmax(1,1,n,i,n)<=qmin(1,1,n,i,n))	zxo2=n+1;else
		{
			int l=i,r=n;
			while (l<r)
			{
				int mid=(l+r)>>1;
				if (qmax(1,1,n,i,mid)<=qmin(1,1,n,i,mid))	l=mid+1;else r=mid;
			}
			zxo2=r;
		}
		zxo+=zxo2-zxo1-1;
	}
	cout<<zxo<<endl;
	return 0;
}