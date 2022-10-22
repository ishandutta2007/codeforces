#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
constexpr int N=1e5+5;
int tt,n,a[N],c[N];
int main()
{
	read(tt);
	while(tt--)
	{
		read(n);
		F(i,0,n)read(a[i]);
		for(int i=n;--i;)a[i]=a[i]-a[i-1];
		a[0]=n;
		F(i,0,n)c[i]=i;
		sort(c,c+n,[](int u,int v){return a[u]>a[v];});
		F(i,0,n)printf("%d ",c[i]+1);
		puts("");
	}
	return 0;
}