#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
int tt,a,b,c,cnt[8];
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int factor(int x)
{
	int i=1,tot=0;
	for(;i*i<x;++i)if(x%i==0)tot+=2;
	if(i*i==x)++tot;
	return tot;
}
int main()
{
	for(read(tt);tt--;)
	{
		long long ans=0;
		read(a,b,c);
		cnt[7]=factor(gcd(a,gcd(b,c)));
		cnt[6]=factor(gcd(a,b))-cnt[7];
		cnt[5]=factor(gcd(a,c))-cnt[7];
		cnt[4]=factor(a)-cnt[5]-cnt[6]-cnt[7];
		cnt[3]=factor(gcd(b,c))-cnt[7];
		cnt[2]=factor(b)-cnt[3]-cnt[6]-cnt[7];
		cnt[1]=factor(c)-cnt[3]-cnt[5]-cnt[7];
		F(i,1,8)F(j,i+1,8)F(k,j+1,8)
		{
			__builtin_popcount(i|j|k)>=3&&__builtin_popcount(i|j)>=2&&
			__builtin_popcount(j|k)>=2&&__builtin_popcount(i|k)>=2&&
			(ans+=(long long)cnt[i]*cnt[j]*cnt[k]);
		}
		F(i,1,8)F(j,1,8)if(i!=j)
		{
			__builtin_popcount(i|j)>=3&&__builtin_popcount(i)>=2&&
			(ans+=cnt[i]*(cnt[i]+1ll)/2*cnt[j]);
		}
		ans+=cnt[7]*(cnt[7]+1ll)*(cnt[7]+2ll)/6;
		printf("%lld\n",ans);
	}
	return 0;
}