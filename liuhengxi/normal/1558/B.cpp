#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=4e6+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
unsigned n,mod,f[N],g[N],a[N];
int main()
{
	read(n);read(mod);
	f[1]=1;g[1]=1;
	++n;
	for(unsigned j=2,k=4;j<=n;++j,k+=2)a[j]=(a[j]+1)%mod,a[k]=(a[k]+mod-1)%mod;
	F(i,2,n)
	{
		(a[i]+=a[i-1])%=mod;
		f[i]=(g[i-1]+a[i])%mod;
		for(unsigned j=i<<1,k=(i+1)<<1;j<n;j+=i,k+=i+1)a[j]=(a[j]+f[i])%mod,a[k]=(a[k]+mod-f[i])%mod;
		g[i]=(g[i-1]+f[i])%mod;
	}
	printf("%u\n",f[--n]);
	return 0;
}