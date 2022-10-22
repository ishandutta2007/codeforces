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
constexpr int N=1e6+5;
int n,m,a[N],s[N],r[N],id[N],t[N],b[N],d;
int main()
{
	read(n,m);
	F(i,0,m)s[i+1]=s[i]+read(a[i]),r[id[i]=i]=s[i+1]%n;
	a[m-1]+=(n-s[m]%n)%n;s[m]=s[m-1]+a[m-1];r[m-1]=-1;
	sort(id,id+m,[](int u,int v){return r[u]<r[v];});
	r[m-1]=0;
	r[id[m]=m]=n;
	F(i,0,m)b[t[id[i]]=i]=r[id[i+1]]-r[id[i]];
	printf("%d\n",d=s[m]/n);
	F(i,0,m)printf("%d ",b[i]);
	puts("");
	for(int i=0,k=0;i<d;++i)
	{
		F(j,0,m)
		{
			if(!a[k])++k;
			a[k]-=b[j];
			printf("%d ",k+1);
		}
		puts("");
	}
	return 0;
}