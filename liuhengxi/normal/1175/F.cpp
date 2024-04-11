#include<cstdio>
#include<algorithm>
#include<random>
#include<chrono>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
typedef unsigned long long ull;
const int N=3e5+5;
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
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()^20220218);
int n,a[N],ans;
ull v[N],s[N],p[N];
void calc()
{
	F(i,0,n)s[i+1]=s[i]^v[a[i]];
	F(i,0,n)if(!a[i])
	{
		int mx=0;
		for(int j=i+1;j<n;)if(a[j])
		{
			mx=max(mx,a[j]);
			int len=mx+1;
			++j;
			if(j>=len&&(s[j]^s[j-len])==p[len])++ans;
		}
		else break;
	}
}
int main()
{
	F(i,0,read(n))if(!--read(a[i]))++ans;
	F(i,0,n)v[i]=gen();
	F(i,0,n)p[i+1]=p[i]^v[i];
	calc();
	F(i,0,n>>1)swap(a[i],a[n-1-i]);
	calc();
	printf("%d\n",ans);
	return 0;
}