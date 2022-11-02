//mjy.. good luck ..
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

#define maxn 2100010
const int mo=469762049;
const int g=3;
int a[maxn],b[maxn],c[maxn];
int n,m,l;

int po(int a,int b)
{
	int ans=1;
	while (b)
	{
		if (b&1)	ans=(1LL*ans*a)%mo;
		a=(1LL*a*a)%mo;
		b>>=1;
	}
	return ans;
}
void NTT(int *a,int n,int isdft)
{
	int pr=log2(n);
	for (int i=0;i<l;i++)
	{
		int x=i,y=0;
		int q=pr;
		while (q-1)
		{
			if (x&1)	y|=1;
			x>>=1;y<<=1;q--;
		}
		y+=x;
		c[y]=a[i];
	}
	for (int i=2;i<=n;i<<=1)
	{
		int wn=po(g,(mo-1)/i);
		if (isdft==-1)	wn=po(wn,mo-2);
		//Complex wn(cos(isdft*2*pi/i),sin(isdft*2*pi/i));
		for (int j=0;j<n;j+=i)
		{
			int w=1,u,v;
			for (int k=j;k<j+i/2;k++)
			{
				u=c[k],v=(1LL*c[k+i/2]*w)%mo;
				c[k]=(u+v)%mo;
				c[k+i/2]=(u-v+mo)%mo;
				w=(1LL*w*wn)%mo;
			}
		}
	}
	int _n=po(n,mo-2);
	if (isdft==-1)
	for (int i=0;i<l;i++)	c[i]=(1LL*c[i]*_n)%mo;
	for (int i=0;i<l;i++)	a[i]=c[i];
}
int main()
{
	//freopen("632E.in","r",stdin);
	read(n),read(m);
	int maxx=0;
	for (int i=1;i<=n;i++)
	{
		int x;read(x);
		a[x]=1;
		maxx=max(maxx,x);
	}
	maxx*=m;
	maxx++;
	l=1;
	while (l<maxx)	l<<=1;
	NTT(a,l,1);
	for (int i=0;i<l;i++)	b[i]=1;
	while (m)
	{
		if (m&1)
		{
			for (int i=0;i<l;i++)	b[i]=(1LL*b[i]*a[i])%mo;
		}
		for (int i=0;i<l;i++)	a[i]=(1LL*a[i]*a[i])%mo;
		m>>=1;
	}
	NTT(b,l,-1);
	for (int i=1;i<=maxx;i++)
	if (b[i]>0)	printf("%d ",i);
	return 0;
}