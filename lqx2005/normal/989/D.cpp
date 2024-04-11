#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,l,w,slen,tlen;
vector<ll> s,t;
bool check(ll xa,ll xb)
{
	ll x=(xa+xb);
	ll y=(xb-xa);
	ll k=w*y;
	if(k>x&&k>-x) return false;
	return true;
}
int main()
{
	scanf("%lld%lld%lld",&n,&l,&w);
	ll x,v,ans=0;
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x,&v);
		if(v==1) s.push_back(x);
		else t.push_back(x);
	}
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	slen=s.size();
	tlen=t.size();
	for(ll lt=0,rt=0;lt<slen;lt++)
	{
		while(rt<tlen&&check(s[lt],t[rt]+l)) rt++;
		ans+=tlen-rt;
	}
	printf("%lld\n",ans);
	return 0;
}