#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

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

#define maxn 100010
const double pi=acos(-1.0);
ll c[maxn],num[maxn],a[maxn];
int n,cnt;

ll ask(int t)
{
	ll mjy=0;
	for (int i=t;i;i-=i&(-i))	mjy=max(mjy,c[i]);
	return mjy;
}
void insert(int t,ll q)
{
	for (int i=t;i<=cnt;i+=i&(-i))	c[i]=max(c[i],q);
}
int main()
{
	read(n);
	for (int i=1;i<=n;i++)
	{
		int x,y;
		read(x),read(y);
		a[i]=1LL*x*x*y;
		num[i]=a[i];
	}
	sort(num+1,num+n+1);
	cnt=unique(num+1,num+n+1)-(num+1);
	for (int i=1;i<=n;i++)	a[i]=lower_bound(num+1,num+cnt+1,a[i])-num;
	ll mjy=0;
	for (int i=1;i<=n;i++)
	{
		ll q=ask(a[i]-1);
		q+=num[a[i]];
		mjy=max(mjy,q);
		insert(a[i],q);
	}
	double mjymjy=mjy;
	mjymjy*=pi;
	printf("%.8lf\n",mjymjy);
	return 0;
}