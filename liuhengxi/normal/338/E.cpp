#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1.5e5+5;
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
namespace seg
{
	#define lc(p) ((p)<<1)
	#define rc(p) ((p)<<1|1)
	int n,val[N<<3],tag[N<<3];
	void init()
	{
		while(n!=(n&-n))n+=(n&-n);
	}
	void update(int l,int r,int v)
	{
		bool ul=false,ur=false;
		for(l+=n,r+=n;l;l>>=1,r>>=1)
		{
			if(ul)val[l-1]=min(val[lc(l-1)],val[rc(l-1)])+tag[l-1];
			if(ur)val[r]=min(val[lc(r)],val[rc(r)])+tag[r];
			if(l==r&&(l&1))
			{
				ul=false;ur=true;
				--l;--r;
			}
			if(l&1)
			{
				val[l]+=v;tag[l]+=v;
				++l;
				ul=true;
			}
			if(r&1)
			{
				--r;
				val[r]+=v;tag[r]+=v;
				ur=true;
			}
		}
	}
	int allmin(){return val[1];}
	#undef lc
	#undef rc
}
int n,m,h,b[N],a[N],v[N<<1],k,ans;
int main()
{
	read(n,m,h);
	F(i,0,m)v[i]=read(b[i]);
	F(i,0,n)read(a[i]),v[i+m]=a[i]=h-a[i];
	sort(v,v+m+n);
	k=(int)(unique(v,v+m+n)-v);
	F(i,0,m)b[i]=(int)(lower_bound(v,v+k,b[i])-v);
	F(i,0,n)a[i]=(int)(lower_bound(v,v+k,a[i])-v);
	seg::n=k;
	F(i,0,m)seg::update(b[i],k,-1);
	F(i,0,m)seg::update(a[i],k,1);
	ans+=seg::allmin()>=0;
	F(i,m,n)
	{
		seg::update(a[i-m],k,-1);
		seg::update(a[i],k,1);
		ans+=seg::allmin()>=0;
	}
	printf("%d\n",ans);
	return 0;
}