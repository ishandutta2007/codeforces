// Lynkcat.
// Problem: D. Robot Cleaner Revisit
// URL: https://codeforces.com/contest/1623/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// -----------------------------------------------

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 1000000007
#define int ll
#define N 400005
using namespace std;
map<tuple<int,int,int>,int> mp;
int n,m,sx,sy,tx,ty,p;
bool a[N];
int tot;
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
void BellaKira()
{
	cin>>n>>m>>sx>>sy>>tx>>ty>>p;
	p=(100-p)*quickPower(100,mod-2)%mod;
	int nx=sx,ny=sy,dx=1,dy=1;
	tot=0;
	mp.clear();
	int pos=0;
	while(true)
	{
		if(nx+dx<1||nx+dx>n)dx=-dx;
		if(ny+dy<1||ny+dy>m)dy=-dy;
		auto tp=make_tuple(nx,ny,dx*2+dy);
		if(mp.count(tp)){
			pos=mp[tp];break;
		}
		a[++tot]=nx==tx||ny==ty;
		nx+=dx,ny+=dy;
		mp[tp]=tot;
	};
	int ans=0,cir=1,pre=1,zz=0;
	for(int i=1;i<pos;++i)
	{
		if(a[i]) pre=pre*p%mod;
		zz=(zz+pre)%mod;
	}
	for(int i=pos;i<=tot;++i)
	{
		if(a[i]) cir=cir*p%mod;
		ans=(ans+cir)%mod;
	}
	ans=(zz+ans*pre%mod*quickPower(mod+1-cir,mod-2))%mod;
	cout<<ans<<endl;
		
}
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}