#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e4+5,M=2e5+5,K=1<<28,KK=(1<<28)-1;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line
{
	int a,b,id;/*y=(1/b-1/a)x+1/a*/
	line(){}
	line(int aa,int bb,int iidd){a=aa,b=bb,id=iidd;}
};
bool ok(line x,line y,line z)
{
	long long a=x.a,b=x.b,c=y.a,d=y.b,e=z.a,f=z.b;
	long long left=(d*(a-c)*(f-b)+c*f*(d-b))*e;//10^16
	long long right=a*c*f*(d-b);
	return left<=right;
}
int n,m,same[M],f[N],id[N],t;
bool ans[M];
line s[N];
int main()
{
	read(n);
	F(i,0,n)
	{
		int a,b;read(a);read(b);
		int t=a>b?a:b;
		m=m>t?m:t;
		same[i]=-1;
		if(f[a]==b)same[i]=id[a];
		else if(f[a]<b)f[a]=b,id[a]=i;
	}
	++m;
	for(int i=m-1;~i;--i)
	{
		if(f[i]<=f[i+1])f[i]=f[i+1],id[i]=-1;
	}
	for(int i=m-1,j=0;~i;--i)if(~id[i])
	{
		line a(i,f[i],id[i]);
		if(j>1)while(t>1&&!ok(s[t-2],s[t-1],a))--t;
		s[t++]=a;
		++j;
	}
	F(i,0,t)ans[s[i].id]=true;
	F(i,0,n)if(~same[i])ans[i]=ans[same[i]];
	F(i,0,n)if(ans[i])printf("%d ",i+1);
	puts("");
	return 0;
}