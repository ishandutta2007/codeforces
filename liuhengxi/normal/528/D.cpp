#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define mul *(long long)
using namespace std;
const int N=5.25e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
namespace NTT
{
	const int MOD=998244353,G=3;
	int n=1,k,g[2*N],gg[N],invn,rev[N];
	int pow(int aa,int b)
	{
		long long a=aa,c=1;
		while(b)
		{
			if(b&1)(c*=a)%=MOD;
			b>>=1;(a*=a)%=MOD;
		}
		return (int)c;
	}
	inline int inv(int a){return pow(a,MOD-2);}
	void init(int N)
	{
		while(n<N)n<<=1,++k;
		g[g[0]=1]=pow(G,MOD-1-(MOD-1)/n);
		F(i,1,n)g[i+1]=g[i] mul g[1]%MOD;
		F(i,0,n)g[2*n-i]=g[i];
		--k;
		F(i,1,n)rev[i]=(rev[i>>1]>>1)^((i&1)<<k);
		++k;
		invn=inv(n);
	}
	void ntt(int *a,int flag)
	{
		F(i,0,n)if(rev[i]>i)a[i]^=a[rev[i]]^=a[i]^=a[rev[i]];
		F(i,0,k)
		{
			int len=2<<i,half=1<<i,t=n/len;
			F(j,0,half)gg[j]=g[n+t*j*flag];
			for(int l=0,mid=half;l<n;l+=len,mid+=len)
				F(j,0,half)
				{
					int tmp=gg[j] mul a[mid+j]%MOD;
					a[mid+j]=(a[l+j]-tmp+MOD)%MOD;
					a[l+j]=(a[l+j]+tmp)%MOD;
				}
		}
		if(flag==-1)
		{
			F(i,0,n)a[i]=a[i] mul invn%MOD;
			F(i,1,n/2)a[i]^=a[n-i]^=a[i]^=a[n-i];
		}
	}
}
using NTT::ntt;
/*
	ch = 'A', 'C' ,'G', 'T'
	reverse T
	no ch in S[i-k...i+k] ->a[i]=1
	ch in T[i] -> b[i]=1
	a*b
*/
char s[N],t[N];
int ans[N],n,m,k,a[N],b[N],c[N],sum[N],occ;
void calc(char ch)
{
	using NTT::MOD;
	F(i,0,NTT::n)a[i]=b[i]=0;
	F(i,0,n)sum[i+1]=sum[i]+(s[i]==ch?1:0);
	F(i,0,n)a[i]=sum[i+k+1<n?i+k+1:n]==sum[i-k>0?i-k:0]?1:0;
	F(i,0,n)b[i]=t[i]==ch?1:0;
//	F(i,n,n+m)a[i]=1;
	ntt(a,1);ntt(b,1);
	F(i,0,NTT::n)a[i]=a[i] mul b[i]%MOD;
	F(i,0,NTT::n)(ans[i]+=a[i])%=MOD;
	ntt(a,-1);
}
int main()
{
	read(n);read(m);read(k);
	gets(s);gets(t);
	F(i,0,m/2)t[i]^=t[m-i-1]^=t[i]^=t[m-i-1];
	NTT::init(n+m);
	calc('A');
	calc('C');
	calc('G');
	calc('T');
	ntt(ans,-1);
	F(i,m-1,n)if(ans[i]==0)++occ;
	printf("%d\n",occ);
	return 0;
}