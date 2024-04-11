#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,M=105;
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
int n,a[N],m,c[M],s[N],d,f_[N<<1],*f=f_+N,ans;
int main()
{
	F(i,0,read(n))++c[--read(a[i])];
	m=min(n,100);
	F(i,1,m)if(c[i]>c[d])d=i;
	F(v,0,m)if(v!=d)
	{
		F(i,0,n)s[i+1]=s[i]+(a[i]==v?-1:(a[i]==d?1:0));
		F(i,-n,n+1)f[i]=n;
		F(i,0,n+1)
		{
			ans=max(ans,i-f[s[i]]);
			f[s[i]]=min(f[s[i]],i);
		}
	}
	printf("%d\n",ans);
	return 0;
}