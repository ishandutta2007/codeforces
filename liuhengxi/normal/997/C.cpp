#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,MOD=998244353;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct cpow
{
	int a,b;
	cpow(int x){a=x;b=1;}
	void next(){b=(long long)b*a%MOD;}
	int get(){return b;}
	int getnext(){next();return get();}
};
int n,f[N],fi[N],ans1,ans2,ans;
int pow(int aa,int b)
{
	long long a=aa,c=1;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		b>>=1;(a*=a)%=MOD;
	}
	return c;
}
int C(int n,int m){return (long long)f[n]*fi[m]%MOD*fi[n-m]%MOD;}
int main()
{
	read(n);
	f[0]=1;
	F(i,1,n+1)f[i]=f[i-1]*(long long)i%MOD;
	fi[n]=pow(f[n],MOD-2);
	for(int i=n;i;--i)fi[i-1]=fi[i]*(long long)i%MOD;
	cpow c(pow(3,MOD-1-(n-1)));
	F(i,1,n+1)
	{
		int tmp=1;
		if(i&1)tmp=MOD-1;
		tmp=(long long)tmp*c.getnext()%MOD;
		tmp=(long long)tmp*C(n,i)%MOD;
		(ans1+=tmp)%=MOD;
	}
	ans1=ans1*(MOD-2ll)%MOD;
	ans1=(long long)ans1*pow(3,(long long)n*n%(MOD-1))%MOD;
	cpow d(3);
	F(i,0,n)
	{
		int tmp=1;
		if(i&1)tmp=MOD-1;
		tmp=(long long)tmp*C(n,i)%MOD;
		tmp=(long long)tmp*(pow(d.get()-1,n)+MOD-pow(d.get(),n))%MOD;
		(ans2+=tmp)%=MOD;
		d.next();
	}
	ans2=ans2*(MOD-3ll)%MOD;
	ans2=(long long)ans2*pow(MOD-1,n)%MOD;
	ans=(ans1+ans2)%MOD;
	printf("%d\n",ans);
	return 0;
}