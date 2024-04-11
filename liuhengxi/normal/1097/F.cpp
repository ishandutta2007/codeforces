#include<cstdio>
#include<bitset>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=7005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,q;
bitset<M> a[N],t[M],s[M],mu;
int getmu(int x)
{
	int ans=1;
	for(int i=2;i*i<=x;++i)if(x%i==0)
	{
		x/=i;
		while(x%i==0)ans=0,x/=i;
	}
	return ans;
}
int main()
{
	read(n);read(q);
	F(i,1,M)mu[i]=getmu(i);
	F(i,1,M)for(int j=i;j<M;j+=i)t[j][i]=1,s[i][j]=mu[j/i];
	while(q--)
	{
		int opt;read(opt);
		if(opt==1)
		{
			int x,v;read(x);read(v);--x;
			a[x]=t[v];
		}
		if(opt==2)
		{
			int x,y,z;read(x);read(y);read(z);--x,--y,--z;
			a[x]=a[y]^a[z];
		}
		if(opt==3)
		{
			int x,y,z;read(x);read(y);read(z);--x,--y,--z;
			a[x]=a[y]&a[z];
		}
		if(opt==4)
		{
			int x,v;read(x);read(v);--x;
			putchar(((a[x]&s[v]).count()&1)|48);
		}
	}
	return 0;
}