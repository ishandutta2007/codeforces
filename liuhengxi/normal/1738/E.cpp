#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
constexpr int N=1e5+5,MOD=998244353;
int pow(int aa,int b)
{
	long long a=aa,c=1;
	for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
	return (int)c;
}
int tt,n,a[N],fac[N],invfac[N];
int C(int x,int y){return (int)((long long)fac[x]*invfac[y]%MOD*invfac[x-y]%MOD);}
int solve(int l,int r,int sp=0)
{
	if(l==r)return 2;
	int x=1,y=1;
	while(l<r&&a[l]==0)++l,++x;
	while(l<r&&a[r-1]==0)--r,++y;
	if(l==r)return pow(2,x-2*sp);
	long long ans=0;
	x-=sp;y-=sp;
	F(i,0,min(x,y)+1)ans+=C(x,i)*(long long)C(y,i)%MOD;
	ans%=MOD;
	long long d=a[l];++l;
	while(r-l>0&&d!=0)
	{
		if(d>0)d-=a[--r];
		else d+=a[l++];
	}
	if(d==0)(ans*=solve(l,r))%=MOD;
	return (int)ans;
}
int main()
{
	F(i,fac[0]=1,N)fac[i]=(int)((long long)fac[i-1]*i%MOD);
	invfac[N-1]=pow(fac[N-1],MOD-2);
	for(int i=N;--i;)invfac[i-1]=(int)((long long)invfac[i]*i%MOD);
	read(tt);
	while(tt--)
	{
		read(n);
		F(i,0,n)read(a[i]);
		printf("%d\n",solve(0,n,1));
	}
	return 0;
}