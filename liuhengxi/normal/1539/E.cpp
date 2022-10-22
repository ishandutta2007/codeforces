#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=5e5+5;
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
struct interval
{
	int l,r;
	interval(){}
	interval(int a,int b){l=a,r=b;}
	bool operator()(int x){return l<=x&&x<r;}
};
interval operator&(interval a,interval b){return interval(max(a.l,b.l),min(a.r,b.r));}
struct cond
{
	int al,ar,bl,br;
	interval a,b;
};
int n,m,k[N],v[M],flm,glm,fto[N],gto[N];
bool f[N],g[N],fv,gv;
interval alim,blim;
cond c[N],all;
void discrete(int &x){x=int(lower_bound(v,v+m,x)-v);}
int main()
{
	read(n,m);
	F(i,0,n)
	{
		read(k[i]);
		read(c[i].al,c[i].ar,c[i].bl,c[i].br);
		v[i*5+0]=k[i];
		v[i*5+1]=c[i].al;
		v[i*5+2]=++c[i].ar;
		v[i*5+3]=c[i].bl;
		v[i*5+4]=++c[i].br;
	}
	sort(v,v+5*n);m=int(unique(v,v+5*n)-v);
	all.ar=m-1;all.br=m-1;
	all.a=all.b=interval(0,m-1);
	F(i,0,n)
	{
		discrete(k[i]);
		discrete(c[i].al);discrete(c[i].ar);
		discrete(c[i].bl);discrete(c[i].br);
		c[i].a=interval(c[i].al,c[i].ar);
		c[i].b=interval(c[i].bl,c[i].br);
	}
	flm=glm=n;fv=gv=true;
	alim=all.a;blim=all.b;
	for(int i=n;~--i;)
	{
		{// calculate f (i-1 changes b, i(, i+1,...) change a)
			int b=i?k[i-1]:0,a=k[i];
			blim=blim&c[i].b;
			gv=gv&&c[i].a(a);
			f[i]=gv&&blim(b);
			if(f[i])fto[i]=glm;
		}
		{// calculate g (i-1 changes a, i(, i+1,...) change b)
			int a=i?k[i-1]:0,b=k[i];
			alim=alim&c[i].a;
			fv=fv&&c[i].b(b);
			g[i]=fv&&alim(a);
			if(g[i])gto[i]=flm;
		}
		if(f[i])
		{
			fv=true;flm=i;
			alim=all.a;
		}
		if(g[i])
		{
			gv=true;glm=i;
			blim=all.b;
		}
	}
	puts(f[0]||g[0]?"Yes":"No");
	if(f[0])
	{
		for(int *ff=fto,i=0,u=0;i<n;i=ff[i],ff=(ff==fto?gto:fto),u^=1)
			F(j,i,ff[i])printf("%d ",u);
		puts("");
	}
	else if(g[0])
	{
		for(int *ff=gto,i=0,u=1;i<n;i=ff[i],ff=(ff==fto?gto:fto),u^=1)
			F(j,i,ff[i])printf("%d ",u);
		puts("");
	}
	return 0;
}