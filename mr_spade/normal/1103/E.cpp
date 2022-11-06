#include<cstdio>
#include<cstring>
typedef unsigned long long ull;
const ull mod=1ll<<58;
const ull inv5=14757395258967641293ull;
struct complex
{
	ull a[4];
	complex(ull x=0)
	{
		a[0]=x;a[1]=a[2]=a[3]=0;
		return;
	}
	inline complex operator+(const complex &th)
	{
		complex res;
		res.a[0]=a[0]+th.a[0];
		res.a[1]=a[1]+th.a[1];
		res.a[2]=a[2]+th.a[2];
		res.a[3]=a[3]+th.a[3];
		return res;
	}
	inline complex operator-(const complex &th)
	{
		complex res;
		res.a[0]=a[0]-th.a[0];
		res.a[1]=a[1]-th.a[1];
		res.a[2]=a[2]-th.a[2];
		res.a[3]=a[3]-th.a[3];
		return res;
	}
	inline complex operator*(const complex &th)
	{
		ull b[7];
		b[0]=a[0]*th.a[0];
		b[1]=a[0]*th.a[1]+a[1]*th.a[0];
		b[2]=a[0]*th.a[2]+a[1]*th.a[1]+a[2]*th.a[0];
		b[3]=a[0]*th.a[3]+a[1]*th.a[2]+a[2]*th.a[1]+a[3]*th.a[0];
		b[4]=a[1]*th.a[3]+a[2]*th.a[2]+a[3]*th.a[1];
		b[5]=a[2]*th.a[3]+a[3]*th.a[2];
		b[6]=a[3]*th.a[3];
		b[5]-=b[6];b[4]-=b[6];b[3]-=b[6];b[2]-=b[6];b[6]=0;
		b[4]-=b[5];b[3]-=b[5];b[2]-=b[5];b[1]-=b[5];b[5]=0;
		b[3]-=b[4];b[2]-=b[4];b[1]-=b[4];b[0]-=b[4];b[4]=0;
		complex res;
		res.a[0]=b[0];res.a[1]=b[1];res.a[2]=b[2];res.a[3]=b[3];
		return res;
	}
}w10[10];
inline complex qpow(complex a,int b)
{
	complex res=w10[0];
	for(;b;a=a*a,b>>=1)
		if(b&1)
			res=res*a;
	return res;
}
inline void init()
{
	register int i;
	w10[0].a[0]=1;w10[1].a[3]=-1;
	for(i=2;i<10;i++)
		w10[i]=w10[i-1]*w10[1];
	return;
}
const int N=1e5+5;
const int pow10[]={1,10,100,1000,10000,100000,1000000};
int n;
complex a[N],b[10];
inline void hddft()
{
	register int d,i,j,k;
	for(d=0;d<5;d++)
	{
		for(i=0;i<100000;i++)
			if((i/pow10[d])%10==0)
			{
				memset(b,0,sizeof(b));
				for(j=0;j<10;j++)
					for(k=0;k<10;k++)
						b[j]=b[j]+a[i+k*pow10[d]]*w10[j*k%10];
				for(j=0;j<10;j++)
					a[i+j*pow10[d]]=b[j];
			}
	}
	return;
}
inline void hdidft()
{
	register int d,i,j,k;
	for(d=0;d<5;d++)
	{
		for(i=0;i<100000;i++)
			if((i/pow10[d])%10==0)
			{
				memset(b,0,sizeof(b));
				for(j=0;j<10;j++)
					for(k=0;k<10;k++)
						b[j]=b[j]+a[i+k*pow10[d]]*w10[(10-j*k%10)%10];
				for(j=0;j<10;j++)
					a[i+j*pow10[d]]=b[j];
			}
	}
	ull w=inv5*inv5*inv5*inv5*inv5;
	for(i=0;i<100000;i++)
		a[i]=a[i]*w;
	return;
}
signed main()
{
	int x;
	register int i;
	init();
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&x),a[x].a[0]++;
	hddft();
	for(i=0;i<100000;i++)
		a[i]=qpow(a[i],n);
	hdidft();
	for(i=0;i<n;i++)
		printf("%llu\n",(a[i].a[0]/32)%mod);
	return 0;
}