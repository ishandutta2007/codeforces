#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
const ll M=6e5+6;
const ll mod=1e9+7;
ll val[4*M],lt[4*M],rt[4*M];
int no[4*M];
ll pw[M],ipw[M];
int P[M],idx[M],qr[M],n,q;
vector<pair<int,int> > v;
ll power(ll a,ll b)
{
	ll val=1;
	while(b)
	{
		if(b%2)
			val=(val*a)%mod;
		b/=2;
		a=(a*a)%mod;
	}
	return val;
}
void build(int i,int s,int e)
{
	if(s==e)
	{
		if(v[s].ss>n)
			return;
		val[i]=0;
		lt[i]=v[s].ff;
		rt[i]=(v[s].ff*ipw[1])%mod;
		no[i]=1;
		return;
	}
	int m=(s+e)/2;
	int lc=2*i,rc=2*i+1;
	build(lc,s,m);
	build(rc,m+1,e);
	ll tp=(ipw[no[lc]]*rt[rc])%mod;
	tp=(tp*lt[lc])%mod;
	val[i]=(val[lc]+val[rc]+tp)%mod;
	lt[i]=(lt[lc]+pw[no[lc]]*lt[rc])%mod;
	rt[i]=(rt[lc]+ipw[no[lc]]*rt[rc])%mod;
	no[i]=(no[lc]+no[rc]);
}
void update(int i,int s,int e,int x,int y)
{
	if(s==e)
	{
		if(y==-1)
		{
			val[i]=0;
			lt[i]=0;
			rt[i]=0;
			no[i]=0;
		}
		else
		{
			val[i]=0;
			lt[i]=v[s].ff;
			rt[i]=(v[s].ff*ipw[1])%mod;
			no[i]=1;
		}
		return;
	}
	int m=(s+e)/2;
	int lc=(i<<1),rc=(lc|1);
	if(x<=m)
		update(lc,s,m,x,y);
	else
		update(rc,m+1,e,x,y);
	ll tp=(ipw[no[lc]]*rt[rc])%mod;
	tp=(tp*lt[lc])%mod;
	val[i]=(val[lc]+val[rc]+tp)%mod;
	lt[i]=(lt[lc]+pw[no[lc]]*lt[rc])%mod;
	rt[i]=(rt[lc]+ipw[no[lc]]*rt[rc])%mod;
	no[i]=(no[lc]+no[rc]);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	pw[0]=1;
	ipw[0]=1;
	ll inv=power(2,mod-2);
	for(int i=1;i<M;i++)
	{
		pw[i]=(pw[i-1]*2)%mod;
		ipw[i]=(ipw[i-1]*inv)%mod;
	}
	cin>>n;
	v.pb({-1LL,-1});
	for(int i=1;i<=n;i++)
	{
		cin>>P[i];
		v.pb({P[i],i});
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>idx[i]>>qr[i];
		v.pb({qr[i],n+i});
	}
	sort(all(v));
	std::vector<int> pos(n+q+1,0);
	for(int i=1;i<sz(v);i++)
		pos[v[i].ss]=i;
	build(1,1,n+q);
	cout<<val[1]<<"\n";
	for(int i=1;i<=q;i++)
	{
		update(1,1,n+q,pos[idx[i]],-1);
		pos[idx[i]]=pos[n+i];
		update(1,1,n+q,pos[idx[i]],1);
		cout<<val[1]<<"\n";
	}
	return 0;
}