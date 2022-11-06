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
typedef long long ll;

ll INF=2e18;

ll vis[1000006];

ll solve(ll k, ll l, ll r, ll x, ll y){
	ll res=0;
	if(y<x){
		ll c=0;
		if(k>r-y){
			c=min((k-(r-y))/x,(k-l)/x)+1;
		}
		res+=c;
		k-=c*x;
		if(k>=l){
			c=(k-l)/(x-y)+1;
			res+=c;
		}
	}else{
		if(l+x-1+y<=r)return INF;
		while(1){
			ll c=(k-l)/x;
			res+=c;
			k-=c*x;
			if(vis[k-l])return INF;
			vis[k-l]=1;
			if(k+y<=r){
				k+=y;
			}else{
				res++;
				break;
			}
		}
	}
	return res;
}

int main(){FIN;
	ll l,k,r,t,x,y; cin>>k>>l>>r>>t>>x>>y;
	if(solve(k,l,r,x,y)<=t)cout<<"No\n";
	else cout<<"Yes\n";
	
	return 0;
}