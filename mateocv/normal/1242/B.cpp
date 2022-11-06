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

vector<ll> g[100005];

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll u,v;
	fore(i,0,m){
	    cin>>u>>v; u--; v--;
	    g[u].pb(v);
	    g[v].pb(u);
	}
	set<pair<ll,ll>> s;
	map<ll,ll> mp;
	ll res=-1;
	ll tot=0;
	ll va=0;
	fore(i,0,n){
	    s.insert({0,i});
	    mp[i]=0;
	}
	while(tot<n){
	    ll br=0;
	    while(s.begin()->fst<va){
	        ll p=s.begin()->snd;
	        s.erase({mp[p],p});
	        mp.erase(p);
	        va++; tot++;
	        if(tot==n){
	            br++; break;
	        }
	        for(auto i:g[p]){
	            if(mp.count(i)){
	                s.erase({mp[i],i});
	                s.insert({mp[i]+1,i});
	                mp[i]++;    
	            }
	        }
	    }
	    if(br)break;
	    //va=0;
	    ll p=s.begin()->snd;
        s.erase({mp[p],p});
        mp.erase(p);
        va++; tot++; res++;
        if(tot==n){
            break;
        }
        for(auto i:g[p]){
            if(mp.count(i)){
                s.erase({mp[i],i});
                s.insert({mp[i]+1,i});
                mp[i]++;    
            }
        }
	}
	cout<<res;
	return 0;
}