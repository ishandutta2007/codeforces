#include<cstdio>
#include<bitset>
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
constexpr int N=1005;
typedef pair<int,int> vec;
int tt,n,m,a[N],b[N];
bitset<N*N/2> f[N];
vec v[N];
int main()
{
	read(tt);
	while(tt--)
	{
{
		int ha=0,hb=0;
		F(i,0,read(n))ha+=read(a[i]);
		F(i,0,read(m))hb+=read(b[i]);
		if(n!=m||(ha&1)||(hb&1))goto fail;
		ha>>=1;hb>>=1;
		F(i,0,n+1)f[i].reset();
		f[0].set(0);
		F(i,0,n)f[i+1]=f[i]|(f[i]<<a[i]);
		if(!f[n].test(ha))goto fail;
		for(int i=n,cur=ha;~--i;)
		{
			if(f[i].test(cur))a[i]=-a[i];
			else cur-=a[i];
		}
		F(i,0,n+1)f[i].reset();
		f[0].set(0);
		F(i,0,n)f[i+1]=f[i]|(f[i]<<b[i]);
		if(!f[n].test(hb))goto fail;
		for(int i=n,cur=hb;~--i;)
		{
			if(f[i].test(cur))b[i]=-b[i];
			else cur-=b[i];
		}
		sort(a,a+n);sort(b,b+n);
		bool c[2][2]={0,0,0,0};
		F(i,0,n)c[a[i]>0][b[i]>0]=1,v[i]=(vec){a[i],b[i]};
		if(!c[0][0])F(i,0,n)v[i].first*=-1;
		else if(!c[1][0])F(i,0,n)v[i].first*=-1,v[i].second*=-1;
		else if(!c[1][1])F(i,0,n)v[i].second*=-1;
		auto sgn=[](vec x){return (x.first&x.second)>>31;};
		sort(v,v+n,[&](vec x,vec y){return sgn(x)!=sgn(y)?sgn(x)<sgn(y):x.first*y.second>y.first*x.second;});
		puts("Yes");
		int x=0,y=0;
		F(i,0,n)
		{
			printf("%d %d\n",x,y);
			x+=v[i].first;
			printf("%d %d\n",x,y);
			y+=v[i].second;
		}
}
		goto succeed;
		fail:
		puts("No");
		succeed:;
	}
	return 0;
}