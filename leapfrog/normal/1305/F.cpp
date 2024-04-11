//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>59;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,pc,p[400005];char v[1000005];ll a[100005];set<ll>mp;
inline void init()
{
	for(int i=2;i<=1000000;i++)
	{
		if(!v[i]) p[++pc]=i;
		for(int j=1;j<=pc&&i*p[j]<=1000000;j++) {v[i*p[j]]=1;if(i%p[j]==0) break;}
	}
}
inline void solve(ll x)
{
	for(int i=1;i<=pc&&1ll*p[i]*p[i]<=x;i++)
	{
		if(x%p[i]==0) mp.insert(p[i]);
		while(x%p[i]==0) x/=p[i];
	}
	if(x>1) mp.insert(x);
}
inline ll check(ll w)
{
	ll res=0;
	for(int i=1;i<=n;i++) if(a[i]<w) res+=w-a[i];else res+=min(a[i]%w,w-a[i]%w);
	return res;
}
int main()
{
	read(n),init(),srand(time(0));for(int i=1;i<=n;i++) read(a[i]);
	random_shuffle(a+1,a+n+1);for(int i=1;i<=n&&i<=100;i++) solve(a[i]),solve(a[i]-1),solve(a[i]+1);
	ll cnt=n;for(auto i:mp) cnt=min(cnt,check(i));
	return printf("%lld\n",cnt),0;
}