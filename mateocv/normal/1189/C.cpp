#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll a[100005];
pair<ll,ll> dp[100005][20];
pair<ll,ll> f(ll x,ll y){
	pair<ll,ll> &r=dp[x][y];
	if(r.fst>=0)return r;
	if(y==0){
		r={0,a[x]}; return r;
	}
	r.fst=f(x,y-1).fst+f(x+(1<<(y-1)),y-1).fst+(f(x,y-1).snd+f(x+(1<<(y-1)),y-1).snd>=10);
	r.snd=(f(x,y-1).snd+f(x+(1<<(y-1)),y-1).snd)%10;
	return r;
}

ll loga(ll n){
	fore(i,0,20){
		if((1<<i)==n)return i;
	}
	return -1;
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i];
	mset(dp,-1);
	ll q; cin>>q;
	while(q--){
		ll l,r; cin>>l>>r; l--; r--;
		ll d=loga(r-l+1);
		//cout<<l<<" "<<d<<"\n";
		cout<<f(l,d).fst<<"\n";
	}
	
	return 0;
}