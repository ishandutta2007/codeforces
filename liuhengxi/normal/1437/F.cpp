#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5005,MOD=998244353;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int fac[N],invfac[N];
inline void add(int &x,int y){(x+=y)-=MOD;x+=(x>>31)&MOD;}
inline int pow(int aa,int b)
{
	long long a=aa,c=1;
	for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
	return (int)c;
}
inline int inv(int a){return pow(a,MOD-2);}
inline A(int n,int m){if(m<0||m>n)return 0;return int((long long)fac[n]*invfac[n-m]%MOD);}
int n,a[N],f[N],cnt[N];
int main()
{
	read(n);
	F(i,fac[0]=1,n+1)fac[i]=int(fac[i-1]*(long long)i%MOD);
	invfac[n]=inv(fac[n]);
	for(int i=n;i;--i)invfac[i-1]=int(invfac[i]*(long long)i%MOD);
	F(i,0,n)read(a[i]);
	sort(a,a+ ++n);
	if(a[n-1]<(a[n-2]<<1))return puts("0"),0;
	for(int i=1,j=0;i<n;cnt[i++]=j)while((a[j]<<1)<=a[i])++j;
	f[n-1]=1;
	for(int i=n-1;~--i;)for(int j=i+1;j<n;++j)if((a[i]<<1)<=a[j])
	{
		add(f[i],int((long long)f[j]*A(n-2-cnt[i],cnt[j]-cnt[i]-1)%MOD));
	}
	printf("%d\n",f[0]);
	return 0;
}