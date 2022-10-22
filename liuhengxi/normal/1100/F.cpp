#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e5+5,LogN=22;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct query
{
	int l,r,id;
	bool operator<(query b)const{return l>b.l;}
}qy[N];
int n,c[N],q,a[LogN],b[LogN],bb[LogN],m,mm,ans[N];
bool insert(int x)
{
	for(int i=LogN;~--i;)if(x>>i&1)
	{
		if(!a[i])return a[i]=x,true;
		x^=a[i];
	}
	return false;
}
int main()
{
	F(i,0,read(n))read(c[i]);
	F(i,0,read(q))--read(qy[i].l),read(qy[qy[i].id=i].r);
	sort(qy,qy+q);
	m=0;
	for(int i=n,k=0;~--i;)
	{
		F(j,0,LogN)a[j]=0;
		for(int j=m++;j;--j)b[j]=b[j-1];
		b[0]=i;
		F(j,mm=0,m)if(insert(c[b[j]]))bb[mm++]=b[j];
		F(j,0,m=mm)b[j]=bb[j];
		for(;k<q&&qy[k].l==i;++k)
		{
			int &lans=ans[qy[k].id];
			F(j,0,LogN)a[j]=0;
			F(j,0,m)if(b[j]<qy[k].r)insert(c[b[j]]);
			for(int j=LogN;~--j;)if((lans^a[j])>lans)lans^=a[j];
		}
	}
	F(i,0,q)printf("%d\n",ans[i]);
	return 0;
}