#include<cstdio>
#include<algorithm>
#include<functional>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define fail return puts("No"),0;
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
int n,pr[N],ne[N],tail,c[N],m;
long long b[N];
void add(int u,int v)
{
	ne[pr[u]=pr[v]]=u;
	pr[ne[u]=v]=u;
}
int main()
{
	read(n);
	F(i,0,n)read(b[i]);
	sort(b,b+n,greater<long long>());
	pr[ne[n]=tail=n+1]=n;
	for(int l=0,r=0,k=59;~k;--k,l=r)
	{
		while((b[r]>>k)==1)++r;
		m=0;
		for(int i=ne[n];i!=n+1;i=ne[i])if(b[i]>>k&1)c[m++]=i;
		c[m++]=tail;
		if(r-l>m)fail;
		F(i,l,r)add(i,c[i-l]);
	}
	puts("Yes");
	for(int i=ne[n];i!=n+1;i=ne[i])printf("%lld ",b[i]);
	puts("");
	return 0;
}