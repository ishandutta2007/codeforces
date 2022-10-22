#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5,MOD=998244353;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k,q,m,a[N],b[N],f[N],c[2*N],d[2*N],e[2*N],ans[2*N],g[2*N],r[2*N];
int inv(int a)
{
	int b=MOD-2,c=1;
	while(b)
	{
		if(b&1)c=(long long)c*a%MOD;
		a=(long long)a*a%MOD;
		b>>=1;
	}
	return c;
}
int C(int n,int m)
{
	if(m>n)return 0;
	return (long long)f[n]*inv((long long)f[m]*f[n-m]%MOD)%MOD;
}
void FFT(int *a,int flag)
{
	int invm=inv(m);
	F(i,0,m)if(r[i]>i)a[r[i]]^=a[i]^=a[r[i]]^=a[i];
	for(int k=1;k<m;k<<=1)
		for(int i=0;i<m;i+=k<<1)
			for(int j=0;j<k;++j)
			{
				int tmp=a[i+k+j];
				if(flag==0)tmp=(long long)tmp*g[m/k/2*j]%MOD;
				else tmp=(long long)tmp*g[m-m/k/2*j]%MOD;
				a[i+k+j]=(a[i+j]-tmp+MOD)%MOD;
				a[i+j]=(a[i+j]+tmp)%MOD;
			}
	if(flag)for(int i=0;i<m;++i)a[i]=(long long)a[i]*invm%MOD;
}
int main()
{
	int logm=0;
	read(n);read(k);
	F(i,0,n)read(a[i]);
	sort(a,a+n);
	F(i,0,k)read(b[i]);
	m=1;
	while(m<n+1)m<<=1,++logm;
	f[0]=1;
	F(i,0,n)f[i+1]=(long long)f[i]*(i+1)%MOD;
	g[0]=1;g[1]=15311432;
	for(int i=(MOD-1)/m/119;i!=1;i>>=1)g[1]=(long long)g[1]*g[1]%MOD;
	F(i,1,m)g[i+1]=(long long)g[i]*g[1]%MOD;
	F(i,0,m)r[i]=(r[i>>1]>>1)|((i&1)<<(logm-1));
	F(i,0,k)
	{
		int x=b[i],one=0,two=0,pow2=1;
		for(int j=0;j<n&&a[j]<x;++j)
		{
			if(j==0||a[j]!=a[j-1])++one;
			else if(j==1||a[j]!=a[j-2])--one,++two;
		}
		F(j,0,m)
		{
			c[j]=(long long)C(one,j)*pow2%MOD;
			pow2<<=1;pow2%=MOD;
		}
		F(j,0,m)d[j]=C(two*2,j);
#define FFT_
#ifdef FFT_
		FFT(c,0);FFT(d,0);
		F(j,0,m)e[j]=(long long)c[j]*d[j]%MOD;
		FFT(e,1);
#else
		F(i,0,m)e[i]=0;
		F(i,0,m)F(j,0,m)if(i+j<m)e[i+j]=(e[i+j]+(long long)c[i]*d[j])%MOD;
#endif
		F(j,0,m)if(e[j])ans[j+x]=(ans[j+x]+e[j])%MOD;
	}
	read(q);
	while(q--)
	{
		int Q;read(Q);Q/=2;
		printf("%d\n",ans[Q-1]);
	}
	return 0;
}