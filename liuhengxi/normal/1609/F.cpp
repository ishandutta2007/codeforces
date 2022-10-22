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
constexpr int N=1e6+5;
struct BITb
{
	int n,c[N];
	void init(int n_){n=n_;F(i,1,n+1)c[i]=0;}
	void add(int x,int y){for(++x;x<=n;x+=x&-x)c[x]+=y;}
	int sum(int x){int ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
};
struct BITa
{
	int n;
	BITb c1,c2;
	void init(int n_){n=n_;c1.init(n);c2.init(n);}
	void add(int x,int v){c1.add(x,x*v);c2.add(n-x,v);}
	int sum(int x){return c1.sum(x)+c2.sum(n-x+1)*x;}
	void add(int x,int y,int v){add(x,-v);add(y,v);}
	int sum(int x,int y){return sum(y)-sum(x);}
}tmn,tmx;
struct segment
{
	int z,x,y,tp;
}s[N<<2];
int n,sta[N],top,ln[N],rn[N],lx[N],rx[N],st;
long long a[N],c[N],ans;
int main()
{
	F(i,0,read(n))c[i]=__builtin_popcountll(read(a[i]));
	F(i,0,n)
	{
		while(top&&a[sta[top-1]]>a[i])--top;
		ln[i]=top?sta[top-1]+1:0;
		sta[top++]=i;
	}
	top=0;
	F(i,0,n)
	{
		while(top&&a[sta[top-1]]<=a[i])--top;
		lx[i]=top?sta[top-1]+1:0;
		sta[top++]=i;
	}
	top=0;
	for(int i=n;~--i;)
	{
		while(top&&a[sta[top-1]]>=a[i])--top;
		rn[i]=top?sta[top-1]:n;
		sta[top++]=i;
	}
	top=0;
	for(int i=n;~--i;)
	{
		while(top&&a[sta[top-1]]<a[i])--top;
		rx[i]=top?sta[top-1]:n;
		sta[top++]=i;
	}
	F(cc,0,64)
	{
		st=0;
		F(i,0,n)if(c[i]==cc)
		{
			s[st].z=ln[i];
			s[st].x=i+1;
			s[st].y=rn[i]+1;
			s[st].tp=0;
			++st;
			s[st].z=i+1;
			s[st].x=i+1;
			s[st].y=rn[i]+1;
			s[st].tp=1;
			++st;
			s[st].z=lx[i];
			s[st].x=i+1;
			s[st].y=rx[i]+1;
			s[st].tp=2;
			++st;
			s[st].z=i+1;
			s[st].x=i+1;
			s[st].y=rx[i]+1;
			s[st].tp=3;
			++st;
		}
		sort(s,s+st,[](segment u,segment v){return u.z<v.z;});
		tmn.init(n+1);tmx.init(n+1);
		int last=0,cur=0;
		F(i,0,st)
		{
			ans+=cur*(long long)(s[i].z-last);
			cur+=(s[i].tp&2?tmn:tmx).sum(s[i].x,s[i].y)*(s[i].tp&1?-1:1);
			(s[i].tp&2?tmx:tmn).add(s[i].x,s[i].y,s[i].tp&1?-1:1);
			last=s[i].z;
		}
	}
	printf("%lld\n",ans);
	return 0;
}