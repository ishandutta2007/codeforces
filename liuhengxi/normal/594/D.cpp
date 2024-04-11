#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,M=1e6+5,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct query
{
	int l,r,id;
	bool operator<(query b)const{return l>b.l;}
}r[N];
int n,a[N],m,pri[N],cnt,mpf[M],sb[M],fsb[M],q,last[M],ans[N],c[N];
bool vis[M];
int pow(int aa,int b)
{
	long long a=aa,c=1;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		b>>=1;(a*=a)%=MOD;
	}
	return c;
}
inline int inv(int a){return pow(a,MOD-2);}
void init()
{
	F(i,2,m)
	{
		if(!vis[i])pri[cnt++]=mpf[i]=i,sb[i]=MOD+1-inv(i),fsb[i]=inv(sb[i]);
		F(j,0,cnt)
		{
			int x=i*pri[j];
			if(x>=m)break;
			vis[x]=true;
			mpf[x]=pri[j];
			if(i%pri[j]==0)break;
		}
	}
}
void add(int x,int y){for(++x;x<=n;x+=x&-x)c[x]=(long long)c[x]*y%MOD;}
int sum(int x){int ans=1;for(;x;x-=x&-x)ans=(long long)ans*c[x]%MOD;return ans;}
int main()
{
	read(n);int l=n;
	F(i,0,n)read(a[i]),m=m>a[i]?m:a[i];
	++m;
	init();
	read(q);
	F(i,0,q)read(r[i].l),read(r[i].r),--r[r[i].id=i].l;
	sort(r,r+q);
	F(i,0,m)last[i]=n;
	F(i,1,n+1)c[i]=1;
	F(i,0,n)add(i,a[i]);
	F(i,0,q)
	{
		int l_=r[i].l,r_=r[i].r;
		while(l>l_)
		{
			for(int i=a[--l];i!=1;i/=mpf[i])if(last[mpf[i]]>l)
				add(last[mpf[i]],fsb[mpf[i]]),add(last[mpf[i]]=l,sb[mpf[i]]);
		}
		ans[r[i].id]=sum(r_)*(long long)inv(sum(l_))%MOD;
	}
	F(i,0,q)printf("%d\n",ans[i]);
	return 0;
}