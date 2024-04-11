#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;

ll dp[100005];

vector<pair<ll,pair<ll,ll>>> v;

ll dist(pair<ll,ll> a, pair<ll,ll> b){
	return abs(a.fst-b.fst)+abs(a.snd-b.snd);
}

int main(){FIN;
	ll r,n; cin>>r>>n;
	mset(dp,-1);
	v.pb({0,{1,1}});
	fore(i,0,n){
		ll t,x,y; cin>>t>>x>>y;
		v.pb({t,{x,y}});
	}
	v.pb({1e9,{1,1}});
	dp[n+1]=0;
	for(int i=n;i>=0;i--){
		dp[i]=0;
		fore(j,1,2020){
			if(i+j>n+1)break;
			if(abs(v[i].fst-v[i+j].fst)>=dist(v[i].snd,v[i+j].snd)){
				dp[i]=max(dp[i],1+dp[i+j]);
			}
		}
	}
	cout<<dp[0]-1<<"\n";
	
	return 0;
}