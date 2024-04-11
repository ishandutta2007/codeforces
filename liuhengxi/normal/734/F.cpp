#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
int n;
long long sum,a[N],b[N],c[N];
int main()
{
	read(n);
	F(i,0,n)sum+=read(b[i]);
	F(i,0,n)sum+=read(c[i]);
	sum/=n<<1;
	F(i,0,n)if((a[i]=(b[i]+c[i]-sum)/n)<0)return puts("-1"),0;
	for(int k=30;~k;--k)
	{
		int d[2]={0,0};
		F(i,0,n)++d[a[i]>>k&1];
		F(i,0,n)b[i]-=(a[i]>>k&1)*d[1]<<k,c[i]-=((a[i]>>k&1)*d[0]+d[1])<<k;
	}
	F(i,0,n)if(b[i]||c[i])return puts("-1"),0;
	F(i,0,n)printf("%lld ",a[i]);
	puts("");
	return 0;
}