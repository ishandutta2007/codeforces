#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,m,a[N],s[N],cc[N<<1],*c=cc+N;
long long calc(int v)
{
	int sum=0;
	long long ans=0;
	F(i,0,n)s[i+1]=s[i]+(a[i]>=v?1:-1);
	F(i,-n,n+1)c[i]=0;
	c[0]=1;sum=0;
	F(i,1,n+1)
	{
		if(s[i]>s[i-1])sum+=c[s[i-1]];
		else sum-=c[s[i]];
		ans+=sum;
		++c[s[i]];
	}
	return ans;
}
int main()
{
	read(n,m);
	F(i,0,n)read(a[i]);
	printf("%lld\n",calc(m)-calc(m+1));
	return 0;
}