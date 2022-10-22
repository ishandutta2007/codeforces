#include<cstdio>
#include<cmath>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],l[N],ans[N];
inline int calc(int k)
{
	static int time=1;
	int m=1,last=++time,tot=0;
	F(i,0,n)
	{
		if(l[a[i]]<last)l[a[i]]=++time,++tot;
		if(tot>k)last=time,tot=1,++m;
	}
	return m;
}
int findbound(int x,int l,int r)// find the first answer < x
{
	int mid;
	while(r-l>1)// (l,r]
	{
		mid=l+((r-l+2)>>2);
		if(calc(mid)<x)r=mid;
		else l=mid;
	}
	return r;
}
int main()
{
	int m;
	read(n);m=min(max((int)sqrt(n*log(n)),0),n)+1;
	F(i,0,n)read(a[i]),--a[i];
	F(i,1,m)ans[i]=calc(i);
	for(int l=m,r=m;l<=n;l=r)
	{
		int x=calc(l);
		r=findbound(x,l,n+1);
		F(i,l,r)ans[i]=x;
	}
	F(i,0,n)printf("%d ",ans[i+1]);
	puts("");
	return 0;
}