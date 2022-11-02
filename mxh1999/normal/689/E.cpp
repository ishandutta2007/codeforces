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
const ll mo=1e9+7;
#define maxn 200010
int n,m;
int seg[maxn<<3];
int num[maxn<<1],cnt;

ll powmod(ll a,ll b)
{
	ll mjy=1;
	while (b)
	{
		if (b&1)	mjy=mjy*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return mjy;
}
void insert(int t,int l,int r,int ql,int qr)
{
	if (l==ql && r==qr)
	{
		seg[t]++;
		return;
	}
	int mid=(l+r)>>1;
	if (qr<=mid)	insert(t<<1,l,mid,ql,qr);else
	if (ql>mid)	insert(t<<1|1,mid+1,r,ql,qr);else
	insert(t<<1,l,mid,ql,mid),insert(t<<1|1,mid+1,r,mid+1,qr);
}
int nnm;
ll zxo;
void query(int t,int l,int r,int pos)
{
	nnm+=seg[t];
	if (l==r)	return;
	int mid=(l+r)>>1;
	if (pos<=mid)	query(t<<1,l,mid,pos);else query(t<<1|1,mid+1,r,pos);
}
ll fac[maxn],_fac[maxn];
int a[maxn],b[maxn];
int main()
{
	read(n),read(m);
	fac[0]=_fac[0]=1;
	for (int i=1;i<=n;i++)
	{
		fac[i]=fac[i-1]*i%mo;
		_fac[i]=powmod(fac[i],mo-2);
	}
	for (int i=1;i<=n;i++)
	{
		read(a[i]);
		read(b[i]);
		a[i]--;
		num[++cnt]=a[i];
		num[++cnt]=b[i];
	}
	sort(num+1,num+cnt+1);
	cnt=unique(num+1,num+cnt+1)-num-1;
	for (int i=1;i<=n;i++)
	{
		a[i]=lower_bound(num+1,num+cnt+1,a[i])-num;
		b[i]=lower_bound(num+1,num+cnt+1,b[i])-num;
		insert(1,1,cnt,a[i]+1,b[i]);
	}
	for (int i=2;i<=cnt;i++)
	{
		nnm=0;
		query(1,1,cnt,i);
		//cerr<<nnm<<endl;
		if (nnm<m)	continue;
		zxo=(zxo+(num[i]-num[i-1])*fac[nnm]%mo*_fac[nnm-m]%mo*_fac[m]%mo)%mo;
	}
	cout<<zxo<<endl;
	return 0;
}