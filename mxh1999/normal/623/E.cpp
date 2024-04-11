#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
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
#define maxn 30010
int n,m;
const int mo=1000000007;
int powmod(int a,int b)
{
	int mjy=1;
	while (b)
	{
		if (b&1)	mjy=(1LL*mjy*a)%mo;
		a=(1LL*a*a)%mo;
		b>>=1;
	}
	return mjy;
}
int fac[maxn],_fac[maxn],po[maxn];
int F[20][maxn];
int f[maxn],g[maxn],h[maxn];
const db pi=acos(-1.0);
struct Complex
{
	db r,i;
	Complex(db _r=0.0,db _i=0.0)
	{
		r=_r,i=_i;
	}
	Complex operator+(Complex b)
	{
		return Complex(r+b.r,i+b.i);
	}
	Complex operator-(Complex b)
	{
		return Complex(r-b.r,i-b.i);
	}
	Complex operator*(Complex b)
	{
		return Complex(r*b.r-i*b.i,r*b.i+i*b.r);
	}
}	a1[maxn<<2],a2[maxn<<2],b1[maxn<<2],b2[maxn<<2],c1[maxn<<2],c2[maxn<<2],c3[maxn<<2];
int l,q;
void FFT(Complex *a,int n,int isdft)
{
	for (int i=0;i<n;i++)
	{
		int x=0,y=i;
		for (int j=1;j<q;j++)
		{
			x|=y&1;
			x<<=1;y>>=1;
		}
		x|=y;
		if (x>i)	swap(a[x],a[i]);
	}
	for (int i=2;i<=n;i<<=1)
	{
		Complex wn(cos(isdft*2.0*pi/i),sin(isdft*2.0*pi/i));
		for (int j=0;j<n;j+=i)
		{
			Complex w(1,0),u,v;
			for (int k=j;k<i/2+j;k++)
			{
				u=a[k],v=a[k+i/2]*w;
				a[k]=u+v;
				a[k+i/2]=u-v;
				w=w*wn;
			}
		}
	}
	if (isdft==-1)
	for (int i=0;i<n;i++)	a[i].r/=n;
}
const int lim=1<<15;
void cheng(int *h,int *f,int *g)
{
	for (int i=0;i<=m;i++)	a1[i]=Complex(1.0*(f[i]/lim),0),a2[i]=Complex(1.0*(f[i]%lim),0);
	for (int i=0;i<=m;i++)	b1[i]=Complex(1.0*(g[i]/lim),0),b2[i]=Complex(1.0*(g[i]%lim),0);
	for (int i=m+1;i<l;i++)	a1[i]=a2[i]=b1[i]=b2[i]=Complex(0,0);
	FFT(a1,l,1);
	FFT(a2,l,1);
	FFT(b1,l,1);
	FFT(b2,l,1);
	for (int i=0;i<l;i++)	c1[i]=a1[i]*b1[i],c2[i]=a1[i]*b2[i]+a2[i]*b1[i],c3[i]=a2[i]*b2[i];
	FFT(c1,l,-1);
	FFT(c2,l,-1);
	FFT(c3,l,-1);
	for (int i=0;i<=m;i++)
	{
		ll x=(ll)(c3[i].r+0.5);
		ll y=(ll)(c2[i].r+0.5);
		ll z=(ll)(c1[i].r+0.5);
		x%=mo,y%=mo,z%=mo;
		h[i]=(x+(y*lim))%mo;
		h[i]=(h[i]+(z*lim*lim)%mo)%mo;
	}
}
int mjy[maxn];
void doit(int n)
{
	for (int i=1;i<=m;i++)	F[0][i]=1;
	int now=2;
	for (int i=1;now<=n;i++,now<<=1)
	{
		f[0]=0;g[0]=0;
		for (int j=1;j<=m;j++)	f[j]=((1LL*F[i-1][j]*_fac[j])%mo*(ll)powmod(po[j],now>>1))%mo;
		for (int j=1;j<=m;j++)	g[j]=(1LL*F[i-1][j]*_fac[j])%mo;
		cheng(h,f,g);
		for (int j=1;j<=m;j++)	F[i][j]=(1LL*h[j]*fac[j])%mo;
	}
	mjy[0]=1;
	int sum=1;
	for (int i=0;n;i++)
	{
		if (n&1)
		{
			for (int j=0;j<=m;j++)	f[j]=((1LL*mjy[j]*_fac[j])%mo*(ll)powmod(po[j],po[i]))%mo;
			for (int j=1;j<=m;j++)	g[j]=(1LL*F[i][j]*_fac[j])%mo;g[0]=0;
			cheng(h,f,g);
			for (int j=0;j<=m;j++)	mjy[j]=(1LL*h[j]*fac[j])%mo;
		}
		n>>=1;
	}
}
int main()
{
	ll N;
	cin>>N;
	read(m);
	if (N>m)	{printf("0\n");return 0;}
	n=N;
	l=1,q=0;
	while (l<((m+1)<<1))	l<<=1,q++;
	po[0]=1;
	fac[0]=_fac[0]=1;
	for (int i=1;i<=m;i++)	po[i]=po[i-1]*2%mo,fac[i]=(1LL*fac[i-1]*i)%mo,_fac[i]=powmod(fac[i],mo-2);
	doit(n);
	ll zxo=0;
	for (int i=1;i<=m;i++)	zxo=(zxo+1LL*(1LL*mjy[i]*fac[m])%mo*((ll)_fac[i]*_fac[m-i]%mo))%mo;
	cout<<zxo<<endl;
	return 0;
}