//meng meng da mjy >w<
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

#define maxn 500010
int n,A,B,T;
int a[maxn];
ll pre[maxn],suf[maxn];
int mjy=0;

int main()
{
	read(n),read(A),read(B),read(T);
	for (int i=1;i<=n;i++)
	{
		char ch=getchar();
		while (ch!='w'&& ch!='h')	ch=getchar();
		if (ch=='w')	a[i]=B+1;else a[i]=1;
	}
	int pos=n+1;
	for (int i=n;i>=1;i--)
	{
		pre[i]=pre[i+1]+A+a[i];
		if (pre[i]<=T)	pos=i;
	}
	ll now=0;
	for (int i=1;i<=n;i++)
	{
		now+=a[i];
		if (i!=1)	now+=A;
		if (now>T)	break;
		if (now<=T)	mjy=max(mjy,i);
		while (pos<=n && pre[pos]+now+1LL*(i-1)*A>T)	pos++;
		if (pos<=n)	mjy=max(mjy,min(n,i+(n+1)-pos));
	}
	pos=1;
	for (int i=2;i<=n;i++)
	{
		suf[i]=suf[i-1]+A+a[i];
		if (suf[i]<=T)	pos=i;
	}
	now=0;
	int ha=1;
	ll mxh=0;
	for (int i=1;i<=n;i++)
	{
		now+=a[ha];
		if (ha!=1)	now+=A,mxh+=A;
		if (now>T)	break;
		if (now<=T)	mjy=max(mjy,i);
		while (pos>=2 && suf[pos]+now+mxh>T)	pos--;
		if (pos>=2)	mjy=max(mjy,min(n,i+pos-1));
		ha--;
		if (ha<=0)	ha+=n;
	}
	cout<<mjy<<endl;
	return 0;
}