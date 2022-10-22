#include<cstdio>
#include<bitset>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=155;
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
struct matrix{int n,m;matrix(int n_=0,int m_=0):n(n_),m(m_){}bitset<N> a[N];};
struct edge{int u,v,w;bool operator<(edge b)const{return w<b.w;}}e[N];
matrix operator*(matrix u,matrix v)
{
	matrix w(u.n,v.m);
	F(i,0,u.n)F(j,0,u.m)if(u.a[i][j])w.a[i]|=v.a[j];
	return w;
}
matrix c,t,tt,cc;
int n,m,d;
int main()
{
	read(n,m);
	F(i,0,m)--read(e[i].u),--read(e[i].v),read(e[i].w);
	sort(e,e+m);
	c.n=1,c.m=n;c.a[0][0]=1;
	t.n=t.m=n;
	F(i,0,m)
	{
		int g=e[i].w-d;d=e[i].w;
		for(tt=t;g;g>>=1,tt=tt*tt)if(g&1)c=c*tt;
		t.a[e[i].u][e[i].v]=1;
		cc=c;
		F(j,0,n)
		{
			if(cc.a[0][n-1])return printf("%d\n",d+j),0;
			cc=cc*t;
		}
	}
	puts("Impossible");
	return 0;
}