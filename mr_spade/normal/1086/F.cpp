#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using std::min;
using std::max;
using std::lower_bound;
using std::sort;
using std::unique;
using std::vector;
inline int abs(int x)
{
	return x<0?-x:x;
}
const int mod=998244353;
inline int add(int a,int b)
{
	return (a+=b)>=mod?a-mod:a;
}
inline int sub(int a,int b)
{
	return (a-=b)<0?a+mod:a;
}
inline int mul(int a,int b)
{
	return (long long)a*b%mod;
}
inline int qpow(int a,int b)
{
	int res=1;
	for(;b;a=mul(a,a),b>>=1)
		if(b&1)
			res=mul(res,a);
	return res;
}
const int N=105;
int n,t,ans;
struct cell
{
	int x,y;
}c[N];
vector<int> V,Vx,Vy;
int sw,w[N],sumw[N];
struct task
{
	int t,l,r,k;
};
vector<task> ta;
int f[N];
namespace lglr
{
	int n;
	int x[N],y[N];
	// inline void print()
	// {
	// 	register int i;
	// 	for(i=1;i<=n;i++)
	// 		fprintf(stderr,"x:%d y:%d\n",x[i],y[i]);
	// 	return;
	// }
	inline int get(int x0)
	{
		int res=0,cur;
		register int i,j;
		for(i=1;i<=n;i++)
		{
			cur=1;
			for(j=1;j<=n;j++)
				if(i!=j)
					cur=mul(cur,mul(sub(x0,x[j]),qpow(sub(x[i],x[j]),mod-2)));
			res=add(res,mul(cur,y[i]));
		}
		return res;
	}
}
namespace zkw
{
	int M;
	int Min[N<<2],lazy[N<<2],cnt[N<<2];
	inline void push_up(int x)
	{
		Min[x]=min(Min[x<<1],Min[x<<1|1])+lazy[x];
		cnt[x]=(Min[x<<1]+lazy[x]==Min[x])*cnt[x<<1]+(Min[x<<1|1]+lazy[x]==Min[x])*cnt[x<<1|1];
		return;
	}
	inline void build(int n)
	{
		register int i;
		for(M=1;M<=n;M<<=1);
		memset(lazy,0,sizeof(int)*(M<<1));
		memset(cnt,0,sizeof(int)*(M<<1));
		for(i=1;i<=n;i++)
			Min[M+i]=0,cnt[M+i]=w[i];
		for(i=M-1;i;i--)
			push_up(i);
		return;
	}
	inline void modify(int l,int r,int k)
	{
		for(l=M+l-1,r=M+r+1;l^r^1;l>>=1,r>>=1,push_up(l),push_up(r))
			(l&1)?0:(Min[l^1]+=k,lazy[l^1]+=k),(r&1)?(Min[r^1]+=k,lazy[r^1]+=k):0;
		for(l>>=1;l;l>>=1)
			push_up(l);
		return;
	}
	inline int query()
	{
		return sw-(Min[1]==0)*cnt[1];
	}
}
inline int calc(int t)
{
	int cl,cr,res=0;
	register int i;
	Vx.clear();Vy.clear();
	for(i=1;i<=n;i++)
	{
		Vx.push_back(c[i].x-t);
		Vx.push_back(c[i].x+t+1);
		Vy.push_back(c[i].y-t);
		Vy.push_back(c[i].y+t+1);
	}
	sort(Vx.begin(),Vx.end());
	Vx.erase(unique(Vx.begin(),Vx.end()),Vx.end());
	sort(Vy.begin(),Vy.end());
	Vy.erase(unique(Vy.begin(),Vy.end()),Vy.end());
	sw=0;
	for(i=1;i<(int)Vy.size();i++)
		w[i]=Vy[i]-Vy[i-1],sw+=w[i];
	ta.clear();
	for(i=1;i<=n;i++)
	{
		cl=lower_bound(Vy.begin(),Vy.end(),c[i].y-t)-Vy.begin()+1;
		cr=lower_bound(Vy.begin(),Vy.end(),c[i].y+t+1)-Vy.begin();
		ta.push_back(task{c[i].x-t,cl,cr,1});
		ta.push_back(task{c[i].x+t+1,cl,cr,-1});
	}
	sort(ta.begin(),ta.end(),[](task a,task b)->bool
	{
		return a.t<b.t;
	});
	zkw::build((int)Vy.size()-1);
	for(i=0;i<(int)ta.size()-1;i++)
	{
		// fprintf(stderr,"%d:%d %d %d\n",ta[i].t,ta[i].l,ta[i].r,ta[i].k);
		zkw::modify(ta[i].l,ta[i].r,ta[i].k);
		// fprintf(stderr,"q:%d %d\n",ta[i+1].t-ta[i].t,zkw::query());
		res=add(res,mul(ta[i+1].t-ta[i].t,zkw::query()%mod));
	}
	// fprintf(stderr,"%d:OK(%d)\n",t,res);
	return res;
}
inline int solve(int l,int r)
{
	int res=0;
	register int i;
	if(r-l+1<3)
	{
		for(i=l;i<=r;i++)
			res=add(res,calc(i));
		return res;
	}
	for(i=l;i<=l+2;i++)
		f[i-l]=calc(i);
	// fprintf(stderr,"hhhh\n");
	for(i=l+1;i<=l+2;i++)
		f[i-l]=add(f[i-l],f[i-l-1]);
	lglr::n=4;
	lglr::x[1]=l;lglr::y[1]=0;
	for(i=l;i<=l+2;i++)
		lglr::x[i-l+2]=i+1,lglr::y[i-l+2]=f[i-l];
	// fprintf(stderr,"hhhh\n");
	// lglr::print();
	return sub(lglr::get(r+1),lglr::get(l));
}
signed main()
{
	int d;
	register int i,j;
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++)
		scanf("%d%d",&c[i].x,&c[i].y);
	V.push_back(0);V.push_back(t+1);
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if((d=(max(abs(c[i].x-c[j].x),abs(c[i].y-c[j].y))+1)/2)<=t)
			V.push_back(d);
	sort(V.begin(),V.end());
	V.erase(unique(V.begin(),V.end()),V.end());
	for(i=0;i<(int)V.size()-1;i++)
		ans=add(ans,solve(V[i],V[i+1]-1));
	// fprintf(stderr,"%d\n",ans);
	ans=sub(mul(t+1,calc(t)),ans);
	printf("%d\n",ans);
	return 0;
}