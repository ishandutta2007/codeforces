#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
const int mod=1e9+7;
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
namespace sgt
{
	const int N=1e7+5;
	int rt,tot;
	int sum[N],Max[N],tag[N];
	int ch[N][2];
	inline void init()
	{
		rt=tot=0;
		return;
	}
	inline void update(int &x,int lp,int rp,int k)
	{
		if(!x)
			x=++tot,sum[x]=Max[x]=tag[x]=ch[x][0]=ch[x][1]=0;
		sum[x]=mul(rp-lp+1,k);Max[x]=k;tag[x]=k;
		return;
	}
	inline void push_down(int x,int lp,int rp)
	{
		if(tag[x]==-1)
			return;
		int mid=(lp+rp)>>1;
		update(ch[x][0],lp,mid,tag[x]);
		update(ch[x][1],mid+1,rp,tag[x]);
		tag[x]=-1;
		return;
	}
	inline void push_up(int x)
	{
		sum[x]=add(sum[ch[x][0]],sum[ch[x][1]]);
		Max[x]=std::max(Max[ch[x][0]],Max[ch[x][1]]);
		return;
	}
	int find(int x,int lp,int rp,int k)
	{
		if(!x)
			return k>0?lp-1:rp;
		if(lp==rp)
			return sum[x]>=k?lp:lp-1;
		int mid=(lp+rp)>>1;
		push_down(x,lp,rp);
		if(Max[ch[x][1]]>=k)
			return find(ch[x][1],mid+1,rp,k);
		return find(ch[x][0],lp,mid,k);
	}
	void assign(int &x,int lp,int rp,int l,int r,int k)
	{
		if(l>r)
			return;
		if(!x)
			x=++tot,sum[x]=Max[x]=tag[x]=ch[x][0]=ch[x][1]=0;
		if(lp==l&&rp==r)
			return update(x,lp,rp,k);
		int mid=(lp+rp)>>1;
		push_down(x,lp,rp);
		if(r<=mid)
			assign(ch[x][0],lp,mid,l,r,k);
		else if(l>=mid+1)
			assign(ch[x][1],mid+1,rp,l,r,k);
		else
			assign(ch[x][0],lp,mid,l,mid,k),assign(ch[x][1],mid+1,rp,mid+1,r,k);
		push_up(x);
		return;
	}
	int query(int x,int lp,int rp,int l,int r)
	{
		if(lp==l&&rp==r)
			return sum[x];
		int mid=(lp+rp)>>1;
		push_down(x,lp,rp);
		if(r<=mid)
			return query(ch[x][0],lp,mid,l,r);
		else if(l>=mid+1)
			return query(ch[x][1],mid+1,rp,l,r);
		else
			return add(query(ch[x][0],lp,mid,l,mid),query(ch[x][1],mid+1,rp,mid+1,r));
	}
}
const int N=2005;
int n,k,L,ans;
struct cell
{
	int x,y,c;
}c[N],d[N];
std::vector<cell> in[N];
std::stack<int> st[N];
inline void per(cell c)
{
	int t=sgt::find(sgt::rt,1,L,c.y);
	sgt::assign(sgt::rt,1,L,t+1,c.x,c.y);
	return;
}
inline void run(int m,int wu,int wl)
{
	int t;
	register int i;
	for(i=0;i<=m;i++)
		in[i].clear();
	memcpy(d+1,c+1,sizeof(cell)*m);
	std::sort(d+1,d+m+1,[](cell a,cell b)->bool
	{
		if(a.y!=b.y)
			return a.y<b.y;
		return a.x<b.x;
	});
	for(i=m;i>=1;i--)
	{
		std::stack<int> &ist=st[d[i].c];
		in[i].push_back(cell{ist.empty()?L:d[ist.top()].y-1,L+1,0});
		while(!ist.empty()&&d[ist.top()].x>=d[i].x)
		{
			t=ist.top();ist.pop();
			in[i].push_back(cell{ist.empty()?L:d[ist.top()].y-1,d[t].x,0});
		}
		st[d[i].c].push(i);
	}
	for(i=1;i<=k;i++)
	{
		std::stack<int> &ist=st[i];
		in[0].push_back(cell{ist.empty()?L:d[ist.top()].y-1,L+1,0});
		while(!ist.empty())
		{
			t=ist.top();ist.pop();
			in[0].push_back(cell{ist.empty()?L:d[ist.top()].y-1,d[t].x,0});
		}
	}
	sgt::init();
	for(cell c:in[0])
		per(c);
	int lst=0;
	for(i=1;i<=m;i++)
	{
		if(i==1||d[i].y!=d[i-1].y)
			ans=add(ans,mul(d[i].y-lst,mul(wu-wl,sub(mul(L+1,L-d[i].y+1),sgt::query(sgt::rt,1,L,d[i].y,L))))),lst=d[i].y;
		for(cell c:in[i])
			per(c);
	}
	return;
}
signed main()
{
	register int i;
	scanf("%d%d%d",&n,&k,&L);
	for(i=1;i<=n;i++)
		scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].c),c[i].x++,c[i].y++;
	std::sort(c+1,c+n+1,[](cell a,cell b)->bool
	{
		return a.x>b.x;
	});
	for(i=2;i<=n;i++)
		if(c[i].x<c[i-1].x)
			run(i-1,c[i-1].x,c[i].x);
	run(n,c[n].x,0);
	printf("%d\n",ans);
	return 0;
}