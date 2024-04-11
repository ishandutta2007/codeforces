#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2500,M=1e5+5,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,a[N],f[M+1];
int inv(int a)
{
	int c=1,n=MOD-2;
	while(n)
	{
		if(n&1)c=(long long)c*a%MOD;
		n>>=1;a=(long long)a*a%MOD;
	}
	return c;
}
int main()
{
	int add=0,ans=0,maxa=0;
	read(n);
	F(i,0,n)read(a[i]);
	F(i,0,n)m+=a[i];
	F(i,0,n)maxa=maxa>a[i]?maxa:a[i];
	f[1]=(long long)(m-1)*(m-1)%MOD*inv(m)%MOD;
	f[2]=(f[1]+f[1]-1)%MOD;
	add=(f[2]-f[1]+MOD)%MOD;
	F(i,2,maxa)
	{
		int p=(long long)i*(m-i)%MOD*inv((long long)m*(m-1)%MOD)%MOD;
		add-=(long long)i*inv((long long)m*p%MOD)%MOD;
		((add%=MOD)+=MOD)%=MOD;
		f[i+1]=(f[i]+add)%MOD;
	}
	F(i,0,n)ans=(ans+f[a[i]])%MOD;
	printf("%d\n",ans);
	return 0;
}