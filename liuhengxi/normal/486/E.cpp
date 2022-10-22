#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,MOD=2144214451;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],m,d[N],c[N],p[N],pc[N],s[N],sc[N],l,t;
bool b[N];
void add(int x,int y,int z)
{
	for(++x;x<=m;x+=x&-x)if(y>d[x])d[x]=y,c[x]=z;
	else if(y==d[x])c[x]=((long long)c[x]+z)%MOD;
}
void sum(int x,int &y,int &z)
{
	y=0;z=0;
	for(;x;x-=x&-x)if(d[x]>y)y=d[x],z=c[x];
	else if(d[x]==y)z=((long long)z+c[x])%MOD;
}
int main()
{
	read(n);F(i,0,n)read(a[i]),m=a[i]>m?a[i]:m;
	++m;
	add(0,0,1);
	F(i,0,n)
	{
		sum(a[i],p[i],pc[i]);
		++p[i];
		add(a[i],p[i],pc[i]);
	}
	sum(m,l,t);++l;
	F(i,0,m+1)d[i]=c[i]=0;
	F(i,0,n)a[i]=m-a[i];
	add(0,0,1);
	for(int i=n-1;~i;--i)
	{
		sum(a[i],s[i],sc[i]);
		++s[i];
		add(a[i],s[i],sc[i]);
	}
	F(i,0,n)if(s[i]+p[i]==l)
	{
		if((long long)sc[i]*pc[i]%MOD==t)putchar('3');
		else putchar('2');
	}
	else putchar('1');
	putchar('\n');
	return 0;
}