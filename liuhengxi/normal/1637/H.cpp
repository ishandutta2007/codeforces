#include<cstdio>
#include<algorithm>
#include<functional>
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
constexpr int N=5e5+5;
struct BIT
{
	int n,c[N];
	void init(int n_){n=n_;F(i,1,n+1)c[i]=0;}
	void add(int x,int y){for(++x;x<=n;x+=x&-x)c[x]+=y;}
	int sum(int x){int ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
}a;
int tt,n,p[N],c[N];
long long ans;
int main()
{
	read(tt);
	while(tt--)
	{
		F(i,0,read(n))--read(p[i]);
		a.init(n);
		ans=0;
		for(int i=n;~--i;)ans+=a.sum(p[i]),a.add(p[i],1);
		F(i,0,n)c[i]=i-2*p[i];
		sort(c,c+n,greater<int>());
		F(i,0,n+1)
		{
			printf("%lld ",ans);
			if(i<n)
			{
				ans-=c[i];
				ans-=i;
			}
		}
		puts("");
	}
	return 0;
}