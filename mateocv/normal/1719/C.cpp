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

ll INF=2e9;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vector<ll> a(n);
		deque<ll> d;
		fore(i,0,n){
			cin>>a[i]; a[i]--;
			d.pb(a[i]);
		}
		vector<pair<ll,ll>> c(n,{INF,INF});
		ll va=1;
		while(1){
			ll fa=d.front(); d.pop_front();
			ll fb=d.front(); d.pop_front();
			if(fa<fb)swap(fa,fb);
			if(c[fa].fst==INF)c[fa].fst=va;
			if(c[fb].fst!=INF)c[fb].snd=va;
			va++;
			d.push_front(fa);
			d.pb(fb);
			if(fa==n-1)break;
		}
		while(q--){
			ll x,k; cin>>x>>k; x--;
			x=a[x];
			auto p=c[x];
			p.snd=min(p.snd,k+1);
			cout<<max(0ll,p.snd-p.fst)<<"\n";
		}
	}
	
	return 0;
}