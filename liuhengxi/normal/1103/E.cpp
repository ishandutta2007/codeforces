#include<cstdio>
#include<cstring>
#define F(i,l,r) for(ui i=l,i##_end=r;i<i##_end;++i)
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
typedef unsigned int ui;
typedef unsigned long long ull;
typedef ull comp[4];
constexpr ui N=1e5+5,m=100000;
constexpr ull INV5=14757395258967641293u,INV55=INV5*INV5*INV5*INV5*INV5;
void mul(comp c,const comp a,const comp b)
{
	static comp t;
	static ull q;
	q=a[1]*b[3]+a[2]*b[2]+a[3]*b[1];
	t[0]=a[0]*b[0]-a[2]*b[3]-a[3]*b[2]-q;
	t[1]=a[0]*b[1]+a[1]*b[0]-a[3]*b[3]+q;
	t[2]=a[0]*b[2]+a[1]*b[1]+a[2]*b[0]-q;
	t[3]=a[0]*b[3]+a[1]*b[2]+a[2]*b[1]+a[3]*b[0]+q;
	memcpy(c,t,sizeof(comp));
}
void add_eq(comp c,const comp a){c[0]+=a[0];c[1]+=a[1];c[2]+=a[2];c[3]+=a[3];}
void pow(const comp aa,ui b,comp c)
{
	static comp a;memcpy(a,aa,sizeof(comp));
	c[0]=1;c[3]=c[2]=c[1]=0;
	for(;b;b>>=1,mul(a,a,a))if(b&1)mul(c,a,c);
}
void trans(comp *a,ui opt)
{
	static comp t[10];
	constexpr comp ww[10]={1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,-1ull,1,-1ull,1,
	-1ull,0,0,0,0,-1ull,0,0,0,0,-1ull,0,0,0,0,-1ull,1,-1ull,1,-1ull};
	for(ui i=1;i<m;i*=10)
	{
		for(ui j=0;j<m;j+=i*10)
		{
			F(k,j,j+i)
			{
				F(p,0,10)
				{
					const comp &w=ww[opt&&p?10-p:p];
					memset(t[p],0,sizeof(comp));
					for(ui l=10;~--l;)
					{
						mul(t[p],t[p],w);
						add_eq(t[p],a[l*i+k]);
					}
				}
				F(p,0,10)memcpy(a[p*i+k],t[p],sizeof(comp));
			}
		}
	}
	if(opt)F(i,0,m)
	{
		a[i][0]*=INV55;
		a[i][0]>>=5;
		a[i][1]*=INV55;
		a[i][1]>>=5;
		a[i][2]*=INV55;
		a[i][2]>>=5;
		a[i][3]*=INV55;
		a[i][3]>>=5;
	}
}
ui n;
comp f[N];
int main()
{
	read(n);
	F(i,0,n)
	{
		ui x;
		++f[read(x)][0];
	}
	trans(f,0);
	F(i,0,m)pow(f[i],n,f[i]);
	trans(f,1);
	F(i,0,n)printf("%llu\n",f[i][0]&((1ull<<58)-1));
	return 0;
}