#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
#include<set>
#include<map>
#define int long long
#define mp make_pair
#define fi first
#define se second
using std::max;
using std::min;
using std::sort;
using std::unique;
using std::pair;
using std::mp;
using std::vector;
using std::set;
using std::map;
namespace zxs
{
	const int N=3e7+5;
	int tot;
	signed sum[N],ch[N][2];
	inline int copy_node(int x)
	{
		int y=++tot;
		sum[y]=sum[x];ch[y][0]=ch[x][0];ch[y][1]=ch[x][1];
		return y;
	}
	inline void push_up(int x)
	{
		sum[x]=sum[ch[x][0]]+sum[ch[x][1]];
		return;
	}
	int build(int lp,int rp)
	{
		int x=++tot;
		if(lp==rp)
			return x;
		int mid=(lp+rp)>>1;
		ch[x][0]=build(lp,mid);
		ch[x][1]=build(mid+1,rp);
		return x;
	}
	int modify(int x,int lp,int rp,int pos)
	{
		x=copy_node(x);
		if(lp==rp)
			return sum[x]++,x;
		int mid=(lp+rp)>>1;
		if(pos<=mid)
			ch[x][0]=modify(ch[x][0],lp,mid,pos);
		else
			ch[x][1]=modify(ch[x][1],mid+1,rp,pos);
		push_up(x);
		return x;
	}
	int query(int x,int lp,int rp,int l,int r)
	{
		if(lp==l&&rp==r)
			return sum[x];
		int mid=(lp+rp)>>1;
		if(r<=mid)
			return query(ch[x][0],lp,mid,l,r);
		else if(l>=mid+1)
			return query(ch[x][1],mid+1,rp,l,r);
		else
			return query(ch[x][0],lp,mid,l,mid)+query(ch[x][1],mid+1,rp,mid+1,r);
	}
}
namespace solver
{
	const int N=1e5+5;
	int n,m;
	vector<int> X,Y,pt[N];
	int x[N],y[N],rt[N];
	set<pair<int,int>> S;
	map<pair<int,int>,int> M;
	inline void play(int x,int y,int z)
	{
		M[mp(x,x+z-1)]=y-x;
		return;
	}
	inline bool judge(int x,int y)
	{
		if(S.find(mp(x,y))!=S.end())
			return 1;
		auto it=M.upper_bound(mp(x,1e12));
		if(it==M.begin())
			return 0;
		it--;
		if(it->fi.se>=x&&y-x==it->se)
			return 1;
		return 0;
	}
	inline int query(int xl,int xr,int yl,int yr)
	{
		xl=lower_bound(X.begin(),X.end(),xl)-X.begin()+1;
		xr=upper_bound(X.begin(),X.end(),xr)-X.begin();
		yl=lower_bound(Y.begin(),Y.end(),yl)-Y.begin()+1;
		yr=upper_bound(Y.begin(),Y.end(),yr)-Y.begin();
		if(xl>xr||yl>yr)
			return 0;
		return zxs::query(rt[xr],1,(int)Y.size(),yl,yr)-zxs::query(rt[xl-1],1,(int)Y.size(),yl,yr);
	}
	inline void init()
	{
		int xx,yy;
		register int i;
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%lld%lld",&x[i],&y[i]),S.insert(mp(x[i],y[i])),X.push_back(x[i]),Y.push_back(y[i]);
		sort(X.begin(),X.end());X.erase(unique(X.begin(),X.end()),X.end());
		sort(Y.begin(),Y.end());Y.erase(unique(Y.begin(),Y.end()),Y.end());
		for(i=1;i<=n;i++)
		{
			xx=lower_bound(X.begin(),X.end(),x[i])-X.begin()+1;
			yy=lower_bound(Y.begin(),Y.end(),y[i])-Y.begin()+1;
			pt[xx].push_back(yy);
		}
		rt[0]=zxs::build(1,(int)Y.size());
		for(i=1;i<=(int)X.size();i++)
		{
			rt[i]=rt[i-1];
			for(int y:pt[i])
				rt[i]=zxs::modify(rt[i],1,(int)Y.size(),y);
		}
		return;
	}
	inline void swift(int &x,int &y)
	{
		while(query(x,x,0,y)||query(0,x,y,y))
			if(query(x,x,0,y))
				x++;
			else
				y++;
		return;
	}
	inline int bound(int x,int y)
	{
		int l=0,r=1e10,mid,t=query(0,x,0,y);
		while(l<r)
		{
			mid=(l+r+1)>>1;
			if(query(0,x+mid,0,y+mid)==t)
				l=mid;
			else
				r=mid-1;
		}
		return l+1;
	}
	void solve()
	{
		int x=0,y=0,b;
		while(x<2e9&&y<2e9)
		{
			swift(x,y);
			b=bound(x,y);play(x,y,b);
			x+=b;y+=b;
		}
		return;
	}
	void main()
	{
		int x,y;
		init();
		solve();
		while(m--)
		{
			scanf("%lld%lld",&x,&y);
			puts(judge(x,y)?"LOSE":"WIN");
		}
		return;
	}
}
signed main()
{
	solver::main();
	return 0;
}