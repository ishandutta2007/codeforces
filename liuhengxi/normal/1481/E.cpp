#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e5+5;
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
int n,a[N],f[N],l[N],r[N],c[N];
int main()
{
	F(i,0,read(n))--read(a[i]);
	F(i,0,n)l[i]=r[i]=-1;
	F(i,0,n)if(!~l[a[i]])l[a[i]]=i;
	F(i,0,n)r[a[i]]=i;
	for(int i=n;~--i;)
	{
		++c[a[i]];
		if(i==l[a[i]])f[i]=f[r[a[i]]+1]+c[a[i]];
		else f[i]=c[a[i]];
		f[i]=max(f[i],f[i+1]);
	}
	printf("%d\n",n-f[0]);
	return 0;
}