#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct pt
{
	long long u,v;
	bool operator<(pt b){return v!=b.v?v<b.v:u<b.u;}
}p[N];
int n,a,fsb;
long long ans;
int main()
{
	read(n);read(a);read(fsb);
	F(i,0,n)
	{
		int x,y;read(fsb);read(x);read(y);
		p[i].u=a*(long long)y+x;
		p[i].v=a*(long long)x-y;
	}
	sort(p,p+n);
	for(int l=0,r=0;l<n;l=r)
	{
		int cnt=0;
		while(r<n&&p[l].v==p[r].v)++r;
		ans+=(r-l)*(r-l-1ll)/2;
		F(i,l,r)
		{
			if(i!=l&&p[i].u==p[i-1].u)++cnt;
			else cnt=0;
			ans-=cnt;
		}
	}
	printf("%lld\n",ans<<1);
	return 0;
}