#include<cstdio>
#include<cmath>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int mu[64]={0,1,-1,-1,0,-1,1,-1,0,0,1,-1,0,-1,1,1,0,-1,0,-1,0,1,1,-1,0,0,1,
0,0,-1,-1,-1,0,1,1,1,0,-1,1,1,0,-1,-1,-1,0,0,1,-1,0,0,0,1,0,-1,0,1,0,1,1,-1,0,-1,1,0};
const long long MAX=2000000000000000000;
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
int tt;
long long n;
long long brute_pow(long long a,int k)
{
	if(a==0)return 0;
	long long c=1,lim=MAX/a+1;
	while(k--)
	{
		if(c>lim)return MAX;
		c*=a;
	}
	return c;
}
long long root(long long n,int k)
{
	long long ans=pow(n,1.0/k)-0.5;
	if(ans<0)ans=0;
	while(brute_pow(ans,k)>n)--ans;
	while(brute_pow(ans+1,k)<=n)++ans;
	return ans;
}
int main()
{
	read(tt);
	while(tt--)
	{
		long long ans=0;
		read(n);
		F(i,1,64)ans+=(root(n,i)-1)*mu[i];
		printf("%lld\n",ans);
	}
	return 0;
}