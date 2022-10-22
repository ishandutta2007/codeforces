#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],c/*remove*/,d/*increase/decrease*/,fac[70],m;
long long f[N][3],ans;
void factor(int a)
{
	for(int i=2;i*i<=a;++i)if(a%i==0)
	{
		while(a%i==0)a/=i;
		fac[m++]=i;
	}
	if(a!=1)fac[m++]=a;
}
int main()
{
	read(n);read(c);read(d);
	F(i,0,n)read(a[i]);
	factor(a[0]);factor(a[0]-1);factor(a[0]+1);
	factor(a[n-1]);factor(a[n-1]-1);factor(a[n-1]+1);
	sort(fac,fac+m);
	m=unique(fac,fac+m)-fac;
	ans=(long long)n*c;
	F(k,0,m)
	{
		int gcd=fac[k];
		f[0][0]=f[0][1]=f[0][2]=0;
		F(i,0,n)
		{
			f[i+1][0]=f[i+1][1]=f[i+1][2]=LLINF;
			if(a[i]%gcd==0)f[i+1][0]=min(f[i+1][0],f[i][0]);
			if((a[i]+1)%gcd==0)f[i+1][0]=min(f[i+1][0],f[i][0]+d);
			if((a[i]-1)%gcd==0)f[i+1][0]=min(f[i+1][0],f[i][0]+d);
			f[i+1][1]=min(f[i+1][1],f[i][1]+c);
			f[i+1][1]=min(f[i+1][0],f[i+1][1]);
			if(a[i]%gcd==0)f[i+1][2]=min(f[i+1][2],f[i][2]);
			if((a[i]+1)%gcd==0)f[i+1][2]=min(f[i+1][2],f[i][2]+d);
			if((a[i]-1)%gcd==0)f[i+1][2]=min(f[i+1][2],f[i][2]+d);
			f[i+1][2]=min(f[i+1][1],f[i+1][2]);
		}
		ans=min(ans,f[n][0]);
		ans=min(ans,f[n][1]);
		ans=min(ans,f[n][2]);
	}
	printf("%lld\n",ans);
	return 0;
}