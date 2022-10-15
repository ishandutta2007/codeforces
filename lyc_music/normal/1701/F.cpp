// Lynkcat.
// Problem: F. Points
// Contest: Codeforces - Educational Codeforces Round 131 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1701/problem/F
// Memory Limit: 512 MB
// Time Limit: 6500 ms

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
int tr[N<<2],tag[N<<2],sm[N<<2];
int q,d;
int vis[N];
const int B=200000;
void pushup(int k)
{
	tr[k]=tr[k<<1]+tr[k<<1|1];
	sm[k]=sm[k<<1]+sm[k<<1|1];
	tr[k]+=sm[k]*tag[k];
}
void update(int k,int l,int r,int x,int L,int tg,int tp)
{
	tg+=tag[k];
	// if (x==1)
		// cout<<"!!!"<<k<<","<<l<<" "<<r<<" "<<tg<<" "<<L<<endl;
	if (l==r)
	{
		tr[k]=L;
		if (tp) tr[k]+=tag[k];
		sm[k]=tp;
		return;
	}
	int mid=l+(r-l)/2;
	if (x<=mid)
		update(k<<1,l,mid,x,L,tg,tp);
	else
		update(k<<1|1,mid+1,r,x,L,tg,tp);
	pushup(k);
}
pa query(int k,int l,int r,int L,int R)
{
	if (L>R) return mp(0ll,0ll);
	if (L<=l&&r<=R)
	{
		return mp(tr[k],sm[k]);
	}
	int mid=l+(r-l)/2;
	pa res=mp(0ll,0ll);
	if (L<=mid) 
	{
		pa nw=query(k<<1,l,mid,L,R);
		res.fi+=nw.fi;
		res.se+=nw.se;
	}
	if (R>mid)
	{
		pa nw=query(k<<1|1,mid+1,r,L,R);
		res.fi+=nw.fi;
		res.se+=nw.se;
	}
	res.fi+=res.se*tag[k];
	return res;
}
void add(int k,int l,int r,int L,int R,int x)
{
	if (L>R) return;
	if (L<=l&&r<=R)
	{
		tag[k]+=x;
		tr[k]+=x*sm[k];
		// cout<<l<<","<<r<<" "<<tag[k]<<endl;
		return;
	}
	int mid=l+(r-l)/2;
	if (L<=mid) add(k<<1,l,mid,L,R,x);
	if (R>mid) add(k<<1|1,mid+1,r,L,R,x);
	pushup(k);
}
void BellaKira()
{
	cin>>q>>d;
	int ans=0;
	for (int i=1;i<=q;i++)
	{
		int x;
		cin>>x;
		if (vis[x])
		{
			vis[x]=0;
			int nw=query(1,1,B,x+1,min(B,x+d)).se;
			ans-=nw*(nw-1)/2;
			// nw=query(1,1,B,max(1ll,x-d),x-1).se;
			// ans-=nw*(nw-1)/2;
			// cout<<"?"<<ans<<endl;
			update(1,1,B,x,0,0,0);
			pa now=query(1,1,B,max(1ll,x-d),x-1);
			if (now.se)
			{
				now.fi=now.fi-now.se;
				ans-=now.fi;
			}
			add(1,1,B,max(1ll,x-d),x-1,-1);
		} else
		{
			vis[x]=1;
			// cout<<"???"<<endl;
			int nw=query(1,1,B,x+1,min(B,x+d)).se;
			ans+=nw*(nw-1)/2;
			update(1,1,B,x,0,0,1);
			pa now=query(1,1,B,max(1ll,x-d),x-1);
			if (now.se)
			{
				now.fi=now.fi;
				ans+=now.fi;
			}
			add(1,1,B,max(1ll,x-d),x-1,1);
		}
		cout<<ans<<endl;
		// cout<<ans<<"          "<<query(1,1,B,1,1).fi<<endl;
	}
}
signed main()
{
	IOS;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}