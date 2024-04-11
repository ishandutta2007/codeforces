#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
typedef long long ll;
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
int n,a[N],sta[N],top;
ll s[N],t[N],y[N],ans;
// x: j  y: j * s[j] - t[j]    k: s[i]        b: y - k*x
// t[i] - t[j] - j * (s[i] - s[j]) = t[i] + (j * s[j] - t[j]) - j * s[i]
//                                          _______y_________ - x * _k__
bool leq(long long a,int b,long long c,int d)
{
	long long ar=(a%b+b)%b,cr=(c%d+d)%d,e=(a-ar)/b,f=(c-cr)/d;
	if(e!=f)return e<f;
	return ar*d<=cr*b;
}
int main()
{
	F(i,0,read(n))read(a[i]);
	F(i,0,n)s[i+1]=s[i]+a[i];
	F(i,0,n)t[i+1]=t[i]+a[i]*(i+1ll);
	F(i,0,n+1)y[i]=i*s[i]-t[i];
	F(i,0,n+1)
	{
#define u sta[top-1]
#define v sta[top-2]
		while(top>=2&&leq(y[u]-y[v],u-v,y[i]-y[u],i-u))--top;
#undef u
#undef v
		sta[top++]=i;
		int l=0,r=top,mid;
		while(r-l>1)
		{
#define u sta[mid]
#define v sta[mid-1]
			mid=(l+r)>>1;
			if(y[u]-u*s[i]>=y[v]-v*s[i])l=mid;
			else r=mid;
#undef u
#undef v
		}
		int j=sta[l];
		ans=max(ans,t[i]+y[j]-j*s[i]);
	}
	printf("%lld\n",ans);
	return 0;
}