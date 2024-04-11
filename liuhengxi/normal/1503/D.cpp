#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define fail return puts("-1"),0
using namespace std;
const int N=2e5+5;
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
int n,a[N],b[N],f[2*N],t[2*N],p[N],m,ans;
bool c[N];
int main()
{
	read(n);
	F(i,0,n)read(a[i],b[i]),--a[i],--b[i];
	F(i,0,n)if((a[i]<n)==(b[i]<n))fail;else f[a[i]]=b[i],f[b[i]]=a[i],t[a[i]]=1;
	F(i,0,n)f[i]-=n;
	for(int i=0,j=n;i<n;)
	{
		c[f[i]]=true;
		while(j&&c[j-1])--j;
		if(j+ ++i==n)p[++m]=i;
	}
	F(i,0,m)
	{
		int s0=n,s1=n,tmp=0;
		F(j,p[i],p[i+1])
		{
			if(s0<s1)
			{
				if(s0>f[j])s0=f[j],tmp+=t[j];
				else if(s1>f[j])s1=f[j],tmp+=!t[j];
				else fail;
			}
			else
			{
				if(s1>f[j])s1=f[j],tmp+=!t[j];
				else if(s0>f[j])s0=f[j],tmp+=t[j];
				else fail;
			}
		}
		ans+=min(tmp,p[i+1]-p[i]-tmp);
	}
	printf("%d\n",ans);
	return 0;
}