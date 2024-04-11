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
constexpr int N=1e5+5;
struct opt
{
	int id,t,i,b;
	long long num,den;
}p[N];
int k,n,m;
long long a[N],b[N];
int main()
{
	read(k,n,m);
	F(i,0,k)b[i]=read(a[i]);
	F(i,0,n)read(p[i].t,p[i].i,p[i].b),--p[i].i,p[i].id=i;
	F(i,0,n)if(p[i].t==1)b[p[i].i]=max(b[p[i].i],(long long)p[i].b);
	F(i,0,n)if(p[i].t==1)
	{
		if(b[p[i].i]==p[i].b)
		{
			p[i].b-=(int)a[p[i].i];
			b[p[i].i]=-1;
		}
		else p[i].b=0;
	}
	sort(p,p+n,[](opt u,opt v){return (u.t==3)!=(v.t==3)?u.t<v.t:u.b>v.b;});
	F(i,0,n)
	{
		if(p[i].t<3)
		{
			p[i].num=p[i].b;
			p[i].den=a[p[i].i];
			a[p[i].i]+=p[i].b;
		}
		if(p[i].t==3)
		{
			p[i].num=p[i].b-1;
			p[i].den=1;
		}
	}
	sort(p,p+n,[](opt u,opt v){return u.num*v.den>v.num*u.den;});
	int l=0;
	while(l<m&&p[l].num>0)++l;
	printf("%d\n",l);
	sort(p,p+l,[](opt u,opt v){return u.t<v.t;});
	F(i,0,l)printf("%d ",p[i].id+1);
	puts("");
	return 0;
}