#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=(1<<12)+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int w,n,m,a[N];
long long b[N];
char s[N];
void fwt()
{
	for(int size=2,half=1,d=w-1;~d;--d,half<<=1,size<<=1)
	{
if(s[d]=='o')for(int l=0,mid=half;l<n;l+=size,mid+=size)F(i,l,mid)b[i+half]+=b[i];
if(s[d]=='a')for(int l=0,mid=half;l<n;l+=size,mid+=size)F(i,l,mid)b[i]+=b[i+half];
if(s[d]=='x')for(int l=0,mid=half;l<n;l+=size,mid+=size)F(i,l,mid)b[i]+=b[i+half],b[i+half]*=-2,b[i+half]+=b[i];
	}
}
void ufwt()
{
	for(int size=2,half=1,d=w-1;~d;--d,half<<=1,size<<=1)
	{
if(s[d]=='o')for(int l=0,mid=half;l<n;l+=size,mid+=size)F(i,l,mid)b[i+half]-=b[i];
if(s[d]=='a')for(int l=0,mid=half;l<n;l+=size,mid+=size)F(i,l,mid)b[i]-=b[i+half];
if(s[d]=='x')for(int l=0,mid=half;l<n;l+=size,mid+=size)F(i,l,mid)b[i+half]-=b[i],b[i+half]/=-2,b[i]-=b[i+half];
	}
}
int main()
{
	read(w);read(n);read(m);
	F(i,0,n){int x;read(x);++a[x];}
	n=1<<w;
	while(m--)
	{
		int ans=0;
		gets(s);
		F(i,0,w)if(s[i]>='a')ans^=1<<(w-1-i);
		F(i,0,w)s[i]|=32;
		F(i,0,n)b[i]=a[i];
		fwt();
		F(i,0,n)b[i]*=b[i];
		ufwt();
		printf("%lld\n",b[ans]);
	}
	return 0;
}