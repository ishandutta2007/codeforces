#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
int n,m,a[N];
long long s[N],t[N];
int main()
{
	read(n,m);
	F(i,0,n)read(a[i]);
	F(i,0,n-1)
	{
		s[i+1]=s[i]+max(a[i]-a[i+1],0);
		t[i+1]=t[i]+max(a[i+1]-a[i],0);
	}
	while(m--)
	{
		int u,v;read(u,v);--u,--v;
		if(u<v)printf("%lld\n",s[v]-s[u]);
		else printf("%lld\n",t[u]-t[v]);
	}
	return 0;
}