#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
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
int n,k,x[N],y[N],f[N],g[N];
int main()
{
	read(n,k);
	F(i,0,n)read(x[i]);
	F(i,0,n)read(y[i]);
	F(i,0,n)
	{
		f[i+1]=max(0ll,x[i]-k*(long long)y[i]+f[i]);
		g[i+1]=max(0ll,y[i]-k*(long long)x[i]+g[i]);
		if(f[i+1]>k||g[i+1]>k)return puts("NO"),0;
	}
	puts("YES");
	return 0;
}