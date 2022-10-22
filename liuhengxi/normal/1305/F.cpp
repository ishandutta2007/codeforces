#include<cstdio>
#include<algorithm>
#include<chrono>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,MOD1=1000000021,MOD2=1000000181;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct clock
{
	chrono::time_point<chrono::steady_clock> start,end;
	clock(){start=chrono::steady_clock::now();}
	bool tle()
	{
		end=chrono::steady_clock::now();
		chrono::milliseconds diff=std::chrono::duration_cast<chrono::milliseconds>(end-start);
		return diff.count()>2000;
	}
}cl;
inline int myrand()
{
	static int s1=1,s2=chrono::steady_clock::now()
	.time_since_epoch().count()%MOD2;
	if((s1<<=1)>=MOD1)s1-=MOD1;
	if((s2<<=1)>=MOD2)s2-=MOD2;
	return s1^s2;
}
int n,m,ans;
long long a[N];
bool vis[5*N];
inline void check(long long x,bool type)
{
	long long tmp=0;
	if(type)
	{
		if(vis[x])return;
		vis[x]=true;
	}
	F(i,0,n)if(a[i]<x)tmp+=x-a[i];
	else tmp+=min(a[i]%x,x-a[i]%x);
	if(tmp<ans)ans=tmp;
}
int main()
{
	read(n);ans=n;
	F(i,0,n)read(a[i]);
	while(!cl.tle())
	{
		long long x=a[myrand()%n]+myrand()%3-1;
		if(!x)continue;
		for(long long i=2;i*i<=x;++i)if(x%i==0)
		{
			check(i,true);
			while(x%i==0)x/=i;
		}
		if(x!=1)check(x,false);
	}
	printf("%d\n",ans);
	return 0;
}