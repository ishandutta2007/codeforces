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
#define maxm 1048576
int b[maxn];
ll f[maxm],g[maxm],c[maxm];
int n,m,all;

void cheng(ll *c,ll *a,ll *b,int n)
{
	if (n==1)
	{
		c[0]=a[0]*b[0];
		return;
	}
	ll A[n],B[n],C[n],D[n];
	for (int i=0;i<n/2;i++)	A[i]=a[i]+a[i+n/2];
	for (int i=0;i<n/2;i++)	B[i]=b[i]+b[i+n/2];
	cheng(C,A,B,n/2);
	for (int i=0;i<n/2;i++)	A[i]=a[i]-a[i+n/2];
	for (int i=0;i<n/2;i++)	B[i]=b[i]-b[i+n/2];
	cheng(D,A,B,n/2);
	for (int i=0;i<n/2;i++)	c[i]=(C[i]+D[i])/2;
	for (int i=0;i<n/2;i++)	c[i+n/2]=(C[i]-D[i])/2;
}
ll mjy;
int main()
{
	read(n);read(m);
	mjy=n*m;
	for (int i=n;i>=1;i--)
		for (int j=1;j<=m;j++)
		{
			char ch=getchar();
			while (ch!='0'&& ch!='1')	ch=getchar();
			if (ch=='1')	b[j]+=1<<(i-1);
		}
	all=1<<n;
	for (int i=1;i<=m;i++)	f[b[i]]++;
	for (int i=0;i<all;i++)
	{
		int q=__builtin_popcount(i);
		g[i]=min(q,n-q);
	}
	n=all;
	cheng(c,f,g,n);
	for (int i=0;i<n;i++)	mjy=min(mjy,c[i]);
	cout<<mjy<<endl;
	return 0;
}