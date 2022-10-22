#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
int n,m1,m2,f1[N],f2[N],u[N],v[N],m,l[N],lc,r[N],rc;
template<int *f>int find(int x){return f[x]&(1<<31)?x:f[x]=find<f>(f[x]);}
template<int *f>void merge(int x,int y)
{
	x=find<f>(x);y=find<f>(y);
	if(x!=y)
	{
		if(f[x]>f[y])swap(x,y);
		f[x]+=f[y];f[y]=x;
	}
}
auto find1=find<f1>,find2=find<f2>;auto merge1=merge<f1>,merge2=merge<f2>;
void add(int x,int y){u[m]=x,v[m++]=y;merge1(x,y);merge2(x,y);}
int main()
{
	F(i,0,read(n))f1[i]=f2[i]=-1;
	read(m1,m2);
	F(i,0,m1)
	{
		int x,y;--read(x),--read(y);
		merge1(x,y);
	}
	F(i,0,m2)
	{
		int x,y;--read(x),--read(y);
		merge2(x,y);
	}
	F(i,1,n)if(find1(i)!=find1(0)&&find2(i)!=find2(0))add(0,i);
	F(i,1,n)if(find1(i)!=find1(0))l[lc++]=i,merge1(0,i);else if(find2(i)!=find2(0))r[rc++]=i,merge2(0,i);
	F(i,0,min(lc,rc))add(l[i],r[i]);
	printf("%d\n",m);
	F(i,0,m)printf("%d %d\n",u[i]+1,v[i]+1);
	return 0;
}