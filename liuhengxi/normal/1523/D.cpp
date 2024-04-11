#include<cstdio>
#include<ctime>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define popcnt(x) __builtin_popcountll(x)
#define getms (clock()*1000/CLOCKS_PER_SEC)
using namespace std;
const int N=2e5+5;
const int MOD1=1000000021,MOD2=1000000181;
int start=0;
bool tle(){static int k=10;k+=45;if(k-start>2500)k=getms;
return k-start>2500;}
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>void readbin(T &x)
{
	unsigned char c=getchar();
	for(x=0;(c^48)>9;c=getchar());
	for(int i=0;(c^48)<10;c=getchar(),++i)x^=(c^48ll)<<i;
}
template<typename T>void writebin(const T &x,int k)
{
	F(i,0,k)putchar((x>>i&1)|48);
	putchar('\n');
}
inline int myrand()
{
	static int s1=1,s2=3;
	if((s1<<=1)>=MOD1)s1-=MOD1;
	if((s2<<=1)>=MOD2)s2-=MOD2;
	return s1^s2;
}
int n,n2,m,p;
long long a[N],ans,bit[20],c[N];
int main()
{
	read(n);read(m);read(p);n2=(n+1)>>1;
	F(i,0,n)readbin(a[i]);
	#ifdef LOCAL
	start=getms;
	#endif
	while(!tle())
	{
		int u=myrand()%n,pp=popcnt(a[u]),cnt=1<<pp,tmp=0;
		if(pp<=popcnt(ans))continue;
		for(long long i=0,v=a[u];i<pp;++i,v^=v&-v)bit[i]=v&-v;
		F(i,0,cnt)c[i]=0;
		F(i,0,n)
		{
			int mask=0;
			F(j,0,pp)if(a[i]&bit[j])mask|=1<<j;
			++c[mask];
		}
		F(i,0,pp)
		{
			int t=1<<i;
			F(j,0,cnt)if(j&t)c[j^t]+=c[j];
		}
		F(j,1,cnt)if(c[j]>=n2&&popcnt(j)>popcnt(tmp))tmp=j;
		if(popcnt(tmp)>popcnt(ans))
		{
			ans=0;
			F(j,0,pp)if(tmp>>j&1)ans|=bit[j];
		}
	}
	writebin(ans,m);
	return 0;
}