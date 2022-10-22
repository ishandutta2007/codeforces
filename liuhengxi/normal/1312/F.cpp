#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
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
int tt,n,x,y,z,xx,yy,zz,p,r,sta[N],f[N];
long long a[N];
inline int to(int x)
{
	int t0=0,t1=0,t2=0;
	int v0=x>>xx&3,v1=x>>yy&3,v2=x>>zz&3;
	while(t0==v0||t0==v1||t0==v2)++t0;
	while(t1==v0||t1==v2)++t1;
	while(t2==v0||t2==v1)++t2;
	return t0<<28|t1<<26|t2<<24|x>>6;
}
inline int get(long long i)
{
	if(i<p)return sta[i];
	i-=p;i%=r;
	return sta[i+p];
}
int main()
{
	for(read(tt);tt--;)
	{
		int s=0,ans=0;
		read(n,x,y,z);xx=34-x*6,yy=32-y*6,zz=30-z*6;
		p=-1;
		for(int i=0,u=0;;++i,u=to(u))
		{
			F(j,0,i)if(sta[j]==u)r=i-(p=j);
			if(~p)break;
			sta[i]=u;
		}
		F(i,0,n)
		{
			int x;
			read(a[i]);
			x=get(a[i]);
			f[i]=x>>28;
			s^=f[i];
		}
		F(i,0,n)
		{
			int x;
			s^=f[i];
			x=get(--a[i]);
			int v0=x>>xx&3,v1=x>>yy&3,v2=x>>zz&3;
			ans+=(v0==s)+(v1==s)+(v2==s);
			s^=f[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}