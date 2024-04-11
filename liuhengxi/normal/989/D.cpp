#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,INF=0x3fffffff;
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
inline long long mod(long long a,long long b){return (a%b+b)%b;}
inline long long floor(long long a,long long b){return (a-mod(a,b))/b;}
inline long long ceil(long long a,long long b){return floor(a+b-1,b);}
int n,l,w,x[N],v[N],a[N],b1[N],b2[N],m1,m2;
long long ans;
int main()
{
	read(n,l,w);
	F(i,0,n)read(x[i],v[i]),(v[i]==-1?b1[m1++]=x[i]+l:b2[m2++]=x[i]);
	sort(b1,b1+m1);
	sort(b2,b2+m2);
	for(int i=0,j=0;i<m1;++i)
	{
		long long f;
		if(b1[i]>0)f=ceil(b1[i]*(w-1ll),w+1);
		else if(w>1)f=ceil(b1[i]*(w+1ll),w-1);
		else f=-INF;
		while(j<m2&&(b2[j]<f))++j;
		ans+=j;
	}
	printf("%lld\n",ans);
	return 0;
}