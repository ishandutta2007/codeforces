#include<cstdio>
#include<set>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=505,M=1000000005;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct pointx
{int x,y;bool operator<(pointx b)const{return x<b.x;}}px[N];
struct pointy
{int x,y;bool operator<(pointy b)const{return y<b.y;}}py[N];
int n,m,k,v[2*N];
struct fake
{
	multiset<int> _sub,_add;
	void init(int m)
	{
		_sub.clear();_add.clear();
		_sub.insert(0);_add.insert(m);
	}
	void add(int x,int y){_add.insert(x);_sub.insert(y);}
	void sub(int x,int y){_sub.insert(x);_add.insert(y);}
	bool ok()
	{
		for(auto i=_sub.begin(),j=_add.begin(),iend=_sub.end();i!=iend;++i,++j)if(*i<*j)return true;
		return false;
	}
}ds;
bool check(int s)
{
	int xmin=n-1,xmax=0,ymin=m-1,ymax=0,tot;
	F(i,0,k)v[i<<1]=px[i].x-s-1,v[i<<1|1]=px[i].x+s+1;
	v[k<<1]=0,v[k<<1|1]=n-1;
	sort(v,v+((k+1)<<1));
	tot=unique(v,v+((k+1)<<1))-v;
	ds.init(m);
	for(int i=0,l=0,r=0;i<tot;++i)if(v[i]>=0&&v[i]<n)
	{
		while(r<k&&px[r].x-s<=v[i])ds.add(px[r].y-s,px[r].y+s+1),++r;
		while(l<k&&px[l].x+s< v[i])ds.sub(px[l].y-s,px[l].y+s+1),++l;
		if(ds.ok())xmin=min(xmin,v[i]),xmax=max(xmax,v[i]);
	}
	F(i,0,k)v[i<<1]=py[i].y-s-1,v[i<<1|1]=py[i].y+s+1;
	v[k<<1]=0,v[k<<1|1]=m-1;
	sort(v,v+((k+1)<<1));
	tot=unique(v,v+((k+1)<<1))-v;
	ds.init(n);
	for(int i=0,l=0,r=0;i<tot;++i)if(v[i]>=0&&v[i]<m)
	{
		while(r<k&&py[r].y-s<=v[i])ds.add(py[r].x-s,py[r].x+s+1),++r;
		while(l<k&&py[l].y+s< v[i])ds.sub(py[l].x-s,py[l].x+s+1),++l;
		if(ds.ok())ymin=min(ymin,v[i]),ymax=max(ymax,v[i]);
	}
	if(xmax-xmin>2*s||ymax-ymin>2*s)return false;
	return true;
}
int solve()
{
	int l=-1,r=M,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	return r;
}
int main()
{
	read(n,m);
	F(i,0,read(k))px[i].x=--read(py[i].x),px[i].y=--read(py[i].y);
	sort(px,px+k);sort(py,py+k);
	check(0);
	printf("%d\n",solve());
	return 0;
}