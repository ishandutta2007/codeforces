#include<cstdio>
#include<algorithm>
#include<functional>
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
int n,d,m,a[N],b[N],c[N],bb,cc;
long long tmp=0,ans=0,sb[N+1],sc[N+1];
int main()
{
	read(n);read(d);read(m);
	++d;
	F(i,0,n)read(a[i]);
	F(i,0,n)if(a[i]<=m)b[bb++]=a[i];
	else c[cc++]=a[i];
	sort(b,b+bb,greater<int>());
	sort(c,c+cc,greater<int>());
	F(i,0,bb)sb[i+1]=sb[i]+b[i];
	F(i,0,cc)sc[i+1]=sc[i]+c[i];
	ans=sb[bb]+sc[(cc-1+d)/d];
	F(i,(cc-1+d)/d+1,(n-1+d)/d+1)
	{
		int ub=n-((i-1)*d+1),uc=i;
		tmp=sb[ub]+sc[uc];
		if(tmp>ans)ans=tmp;
	}
	printf("%lld\n",ans);
	return 0;
}