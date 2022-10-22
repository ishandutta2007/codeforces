#include<cstdio>
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
constexpr int N=(1<<19)+5;
int n,m,a[N];
int main()
{
	F(i,0,read(n))read(a[i]);
	while((1<<m)<n)++m;
	m=1<<m;
	for(int i=1;i^m;i<<=1)for(int j=0;j<n;++j,j+=j&i)a[j^i]^=a[j];
	for(int i=1;i^m;i<<=1)for(int j=i;j<n;++j,j+=(~j)&i)a[j^i]^=a[j];
	for(int i=n;~--i;)printf("%d ",a[i]);
	puts("");
	return 0;
}