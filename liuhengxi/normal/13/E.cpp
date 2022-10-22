#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int M=320,N=M*M;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int realn,n,a[N],m,q,bl[N],dep[N],to[N],f;
int main()
{
	read(n);read(q);
	F(i,0,n)read(a[i]);
	while(m*m<n)++m;
	++m;f=m-1;
	realn=n;n=m*m;
	F(i,0,realn)if(i+a[i]>=realn)a[i]=n-1-i;
	F(i,0,n+1)bl[i]=i/m;
	for(int i=realn-1;~i;--i)if(bl[i+a[i]]!=bl[i])dep[i]=1,to[i]=i+a[i];
	else dep[i]=dep[i+a[i]]+1,to[i]=to[i+a[i]];
	while(q--)
	{
		int opt;read(opt);
		if(opt)
		{
			int x,t,ans=0;read(x);--x;
			while(bl[x]!=f)ans+=dep[t=x],x=to[x];
			while(t+a[t]<realn)t+=a[t];
			printf("%d %d\n",t+1,ans);
		}
		else
		{
			int x,y;read(x);read(y);--x;
			a[x]=y;
			if(x+a[x]>=realn)a[x]=n-1-x;
			for(int i=x,sb=bl[x]*m;i>=sb;--i)if(bl[i+a[i]]!=bl[i])dep[i]=1,to[i]=i+a[i];
			else dep[i]=dep[i+a[i]]+1,to[i]=to[i+a[i]];
		}
	}
	return 0;
}