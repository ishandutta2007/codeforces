//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int cnt;
int lstans;
int nowr;
namespace seg1
{
	int tr[N<<2];
	void pushup(int k)
	{
		tr[k]=min(tr[k<<1],tr[k<<1|1]);
	}
	void update(int k,int l,int r,int x,int val)
	{
		if (l==r)
		{
			tr[k]=val;
			return;
		}
		int mid=l+(r-l)/2;
		if (x<=mid) update(k<<1,l,mid,x,val);
		else update(k<<1|1,mid+1,r,x,val);
		pushup(k);
	}
	pa query(int k,int l,int r,int x)
	{
		if (l==r)
		{
			return mp(tr[k],l);
		}
		int mid=l+(r-l)/2;
		if (tr[k<<1]<=x) return query(k<<1,l,mid,x);
		return query(k<<1|1,mid+1,r,x);
	}
};
namespace seg2
{
	#define B 100
	int tr[N*B],tr1[N*B],lson[N*B],rson[N*B];
	int tag[N*B];
	int tag1[N*B];
	void build(int &k,int l,int r)
	{
		if (!k) k=++cnt;
		if (l==r) return;
		int mid=l+(r-l)/2;
		build(lson[k],l,mid);
		build(rson[k],mid+1,r);
	}
	// void pushdown(int k,.
	void pushup(int k)
	{
		tr[k]=tr[lson[k]]+tr[rson[k]];
		tr1[k]=tr1[lson[k]]+tr1[rson[k]];
	}
	void update(int &k,int lst,int l,int r,int L,int R,int val)
	{
		k=++cnt;
		tr[k]=tr[lst];
		tr1[k]=tr1[lst];
		tag[k]=tag[lst];
		tag1[k]=tag1[lst];
		lson[k]=lson[lst];
		rson[k]=rson[lst];
		if (L>R)
		{
			return;
		}
		if (L<=l&&r<=R)
		{
			if (val<0)
			{
				// val++;
				tr[k]+=val*(r-l+1);
				tr1[k]+=r-l+1;
				tag[k]+=val;
				tag1[k]+=1;
			} else
			{
				tr[k]+=val*(r-l+1);
				tr1[k]-=r-l+1;
				tag[k]+=val;
				tag1[k]-=1;
			}
			// cout<<"?upd "<<l<<" "<<r<<" "<<val<<" "<<tr[k]<<" "<<tr1[k]<<endl;
			return;
		}
		int mid=l+(r-l)/2;
		// pushdown(lst,l,r);
		if (L<=mid) 
			update(lson[k],lson[lst],l,mid,L,R,val);
		else lson[k]=lson[lst];
		if (R>mid) update(rson[k],rson[lst],mid+1,r,L,R,val);
		else rson[k]=rson[lst];
		pushup(k);
	}
	pa query(int k,int l,int r,int L,int R)
	{
		if (!k) return mp(0ll,0ll);
		if (L<=l&&r<=R)
		{
			return mp(tr[k],tr1[k]);
		}
		pa res=mp((R-L+1)*tag[k],(R-L+1)*tag1[k]);
		int mid=l+(r-l)/2;
		if (L<=mid)
		{
			pa now=query(lson[k],l,mid,L,min(R,mid));
			res.fi+=now.fi;
			res.se+=now.se;
		}
		if (R>mid)
		{
			pa now=query(rson[k],mid+1,r,max(mid+1,L),R);
			res.fi+=now.fi;
			res.se+=now.se;
		}
		return res;
	}
};
vector<pa>Rt[N];
pa seg[N];
int n;
pa mergepa(pa x,pa y)
{
	if (y.fi==0) return x;
	if (x.fi==0) return y;
	if (x.fi>y.fi) swap(x,y);
	return mp(x.fi,y.se);
}
void update(int x)
{
	if (seg[x].fi)
	{
		int nowrt=0;
		int lst=(Rt[x].back()).se;
		seg2::update(nowrt,lst,1,n,seg[x].fi,seg[x].se,(nowr));
		// cout<<"upd "<<x<<" "<<seg[x].fi<<" "<<seg[x].se<<" "<<nowr<<endl;
		Rt[x].push_back(mp(nowr,nowrt));
		int L=seg[x].fi,R=seg[x].se;
		seg[x]=mp(0,0);
		while (L<=R)
		{
			pa u=seg1::query(1,0,n+1,R-1);
			nowrt=0;
			lst=(Rt[u.se].back()).se;
			seg2::update(nowrt,lst,1,n,max(L,u.fi+1),R,-(nowr));
			// cout<<"upd "<<u.se<<" "<<max(L,u.fi+1)<<" "<<R<<" "<<-nowr<<endl;
			Rt[u.se].push_back(mp(nowr,nowrt));
			seg[u.se]=mergepa(seg[u.se],mp(max(L,u.fi+1),R));
			R=max(L,u.fi+1)-1;
		}
	}
	int y=0;
	if (x==0) y=1;
	else y=0;
	int nowrt=0;
	int lst=(Rt[y].back()).se;
	seg2::update(nowrt,lst,1,n,nowr,nowr,-(nowr));
	// cout<<"upd "<<y<<" "<<nowr<<" "<<nowr<<" "<<-nowr<<endl;
	Rt[y].push_back(mp(nowr,nowrt));
	seg[y]=mergepa(seg[y],mp(nowr,nowr));
}		
void query(int x,int l,int r)
{
	if (!Rt[x].size())
	{
		lstans=0;
		writeln(0);
		return;
	}
	int nowrt=lower_bound(Rt[x].begin(),Rt[x].end(),mp(r+1,0ll))-Rt[x].begin();
	nowrt--;
	if (nowrt<0) return lstans=0,writeln(0),void();
	nowrt=Rt[x][nowrt].se;
	pa u=seg2::query(nowrt,1,n,l,r);
	lstans=u.se*(r+1)+u.fi;
	// cout<<"?"<<u.se<<" "<<u.fi<<" "<<l<<" "<<r<<endl;
	// cout<<"?"<<seg2::tr[0]<<" "<<endl;
	writeln(lstans);
}
void BellaKira()
{
	n=read();
	++cnt;
	seg2::build(cnt,1,n);
	for (int i=0;i<=n+1;i++) Rt[i].push_back(mp(0,1));
	for (int i=1;i<=n;i++)
	{
		nowr=i;
		int x=read(),l=read(),r=read(),p=read();
		x=(x+lstans)%(n+1);
		// cout<<"ins "<<x<<endl;
		seg1::update(1,0,n+1,x,i);
		l=(l+lstans)%i+1;
		r=(r+lstans)%i+1;
		if (l>r) swap(l,r);
		p=(p+lstans)%(n+1);
		update(x);
		query(p,l,r);
	}
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/