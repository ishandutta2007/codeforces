// Lynkcat.
// Problem: H. Keep XOR Low
// Contest: Codeforces - Good Bye 2021: 2022 is NEAR
// URL: https://codeforces.com/contest/1616/problem/H
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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
int n,m,a[N],pw2[N];
int rt;
int sm[6000005],son[6000005][2];
int tot;
void ins(int &k,int dep,int val)
{
	if (!k) k=++tot,sm[k]=0;
	// cout<<k<<" "<<dep<<" "<<val<<endl;
	sm[k]++;
	if (dep<0) return;
	if ((val>>dep)&1) ins(son[k][1],dep-1,val);
	else ins(son[k][0],dep-1,val);
}
int work(int x,int y,int dep,int val)
{
	if (!x||!y) return 0;
	// cout<<x<<" "<<y<<" "<<dep<<" "<<val<<endl;
	if (dep<0)
	{
		if (x==y) return pw2[sm[x]];
		return pw2[sm[x]]*pw2[sm[y]]%mod;
	}
	int res=0;
	if ((val>>dep)%2==0)
	{
		res=(work(son[x][0],son[y][0],dep-1,val)
		+work(son[x][1],son[y][1],dep-1,val))%mod;
	} else
	{
		int vx=work(son[x][1],son[y][0],dep-1,val);
		if (x==y) return (vx+pw2[sm[son[x][0]]]+pw2[sm[son[x][1]]])%mod;
		int vy=work(son[x][0],son[y][1],dep-1,val);
		res=vx*vy%mod;
		// cout<<"?"<<vx<<" "<<vy<<" "<<res<<endl;
		res=(res+vx*pw2[sm[son[y][1]]]%mod)%mod;
		res=(res+vx*pw2[sm[son[x][0]]]%mod)%mod;
		res=(res+vy*pw2[sm[son[x][1]]]%mod)%mod;
		res=(res+vy*pw2[sm[son[y][0]]]%mod)%mod;
		// cout<<"?"<<vx<<" "<<vy<<" "<<res<<endl;
		res=(res+
		pw2[sm[son[y][0]]]*pw2[sm[son[x][0]]]%mod+
		pw2[sm[son[y][1]]]*pw2[sm[son[x][1]]]%mod)%mod;
		res=(res+vx+vy)%mod;
	}
	return res;
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) ins(rt,29,a[i]);
	cout<<work(rt,rt,29,m)<<endl;
	rt=0;
	tot=0;
}
signed main()
{
	pw2[0]=1;
	for (int i=1;i<=200000;i++) pw2[i]=pw2[i-1]*2%mod;
	for (int i=0;i<=200000;i++) pw2[i]=(pw2[i]-1+mod)%mod;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}