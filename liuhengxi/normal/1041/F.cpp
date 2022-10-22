#include<cstdio>
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
int n,a[N],m,b[N],c[2*N],ans;
int main()
{
	read(n);read(a[0]);
	F(i,0,n)read(a[i]);
	read(m);read(b[0]);
	F(i,0,m)read(b[i]);
	F(k,-1,30)
	{
		int sb,fsb;
		if(~k)sb=1<<k,fsb=2<<k;
		else sb=0,fsb=2e9;
		F(i,0,n)c[i]=a[i]%fsb;
		F(i,0,m)c[i+n]=(b[i]+sb)%fsb;
		sort(c,c+n+m);
		for(int l=0,r=0;l<n+m;l=r)
		{
			while(r<n+m&&c[l]==c[r])++r;
			if(r-l>ans)ans=r-l;
		}
	}
	printf("%d\n",ans);
	return 0;
}