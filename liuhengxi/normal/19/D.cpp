#include<cstdio>
#include<algorithm>
#include<functional>
#include<set>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define rev greater<int>()
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
constexpr int N=2e5+5;
namespace seg
{
	constexpr int N=(1<<19)+5;
	#define lc (p<<1)
	#define rc (p<<1|1)
	int max[N];
	void update(int p,int l,int r,int x,int v)
	{
		if(r-l==1)return void(max[p]=v);
		int mid=(l+r)>>1;
		if(x<mid)update(lc,l,mid,x,v);
		else update(rc,mid,r,x,v);
		max[p]=std::max(max[lc],max[rc]);
	}
	int find(int p,int l,int r,int x,int v)
	{
		if(r-l==1)return max[p]>v?l:-1;
		int mid=(l+r)>>1;
		if(x>mid)
		{
			int ans=find(rc,mid,r,x,v);
			if(~ans)return ans;
		}
		if(x>=mid&&max[lc]<=v)return -1;
		return find(lc,l,mid,x,v);
	}
	#undef lc
	#undef rc
}
using seg::update;using seg::find;
int n,opt[N],x[N],y[N],xv[N],yv[N],mx[N];
set<int> s[N];
int main()
{
	read(n);
	F(i,0,n)
	{
		char str[7];scanf("%s",str);
		if(str[0]=='r')opt[i]=1;
		if(str[0]=='f')opt[i]=2;
		read(x[i],y[i]);
		xv[i]=x[i];
		yv[i]=y[i];
	}
	sort(xv,xv+n,rev);sort(yv,yv+n);
	F(i,0,n)x[i]=(int)(lower_bound(xv,xv+n,x[i],rev)-xv),y[i]=(int)(lower_bound(yv,yv+n,y[i])-yv);
	F(i,0,n)
	{
		if(opt[i]==0)
		{
			s[x[i]].insert(y[i]);
			mx[x[i]]=max(mx[x[i]],y[i]);
			update(1,0,n,x[i],mx[x[i]]);
		}
		if(opt[i]==1)
		{
			s[x[i]].erase(y[i]);
			mx[x[i]]=s[x[i]].empty()?0:*s[x[i]].rbegin();
			update(1,0,n,x[i],mx[x[i]]);
		}
		if(opt[i]==2)
		{
			int rx=x[i]?find(1,0,n,x[i],y[i]):-1;
			if(~rx)printf("%d %d\n",xv[rx],yv[*s[rx].lower_bound(y[i]+1)]);
			else puts("-1");
		}
	}
	return 0;
}