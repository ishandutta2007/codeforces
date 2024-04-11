#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
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
int n,val[N];
long long mask[N],sum,ans;
int popcnt(long long x)
{
	int cnt=0;
	while(x)x^=x&-x,++cnt;
	return cnt;
}
int main()
{
	read(n);
	F(i,0,n)read(val[i],mask[i]),sum+=val[i];
	sum>>=63;sum=sum*2+1;
	for(long long l=1,r=2;r>0;l<<=1,r<<=1)
	{
		long long delta=0;
		F(i,0,n)if(mask[i]>=l&&mask[i]<r)delta+=(1-(popcnt(mask[i]&ans)&1)*2)*val[i];
		if(delta*sum>0)ans|=l;
	}
	#ifndef ONLINE_JUDGE
	long long sum1=0;
	F(i,0,n)sum1+=(1-(popcnt(mask[i]&ans)&1)*2)*val[i];
	if(sum1*sum>0)puts("wrong");
	#endif
	printf("%lld\n",ans);
	return 0;
}