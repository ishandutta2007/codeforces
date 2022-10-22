#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1<<20;
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
int C(int n,int m){return n>=0&&(n&m)==m;}
int n,k;
bool ans[N];
unsigned b[N];
int main()
{
	read(n,k);
	F(i,0,n)read(b[i]);
	F(len,1,min(21,n-k+!!k))
	{
		unsigned c=0,cc=0;
		F(i,k,n-len+1)c^=C(n-len-2,i-2),cc^=C(n-len-1,i-1);
		F(i,0,n+1-len)
		{
			unsigned long long d=b[i];
			F(j,i+1,i+len)d<<=min(20u,b[j]);
			if(!(d>>20))ans[d]^=i==0||i==n-len?cc:c;
		}
	}
	if(k==0)
	{
		unsigned long long d=b[0];
		F(j,1,n)d<<=min(20u,b[j]);
		if(!(d>>20))ans[d]^=1;
	}
	ans[0]=0;
	int f=1<<20;
	while(f&&!ans[f-1])--f;
	f+=!f;
	for(int i=f;~--i;)printf("%d",ans[i]);
	puts("");
	return 0;
}