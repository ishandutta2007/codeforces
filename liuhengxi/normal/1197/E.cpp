#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,INF=0x3fffffff,MOD=1000000007;
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
struct doll
{
	int a,b;
	bool operator<(doll c)const{return a<c.a;}
}d[N];
int n,m,v[2*N],dis[2*N],f[2*N],minm=INF,ans;
int main()
{
	F(i,0,read(n))read(d[i].b,d[i].a),v[i<<1]=d[i].a,v[i<<1|1]=d[i].b;
	sort(v,v+(n<<1));m=unique(v,v+(n<<1))-v;sort(d,d+n);
	F(i,0,n)d[i].a=lower_bound(v,v+m,d[i].a)-v,d[i].b=lower_bound(v,v+m,d[i].b)-v;
	F(i,1,m)dis[i]=INF;
	f[0]=1;
	for(int i=0,j=0;i<m;++i)
	{
		if(dis[i+1]>dis[i]+v[i+1]-v[i])dis[i+1]=dis[i]+v[i+1]-v[i],f[i+1]=0;
		if(dis[i+1]==dis[i]+v[i+1]-v[i])(f[i+1]+=f[i])%=MOD;
		for(;j<n&&d[j].a==i;++j)
		{
			if(dis[d[j].b]>dis[i])dis[d[j].b]=dis[i],f[d[j].b]=0;
			if(dis[d[j].b]==dis[i])(f[d[j].b]+=f[i])%=MOD;
		}
	}
	F(i,d[n-1].a+1,m)minm=min(minm,dis[i]);
	F(i,d[n-1].a+1,m)if(dis[i]==minm)(ans+=f[i])%=MOD;
	printf("%d\n",ans);
	return 0;
}