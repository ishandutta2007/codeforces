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

string s;

map<string,pair<ll,ll>> mp;

ll dp[1003];

ll f(ll x){
	auto &res=dp[x];
	if(res>=0)return res;
	if(x==SZ(s))return res=1;
	res=0;
	string sp;
	sp+=s[x];
	fore(k,0,2){
		if(x+1+k<SZ(s))sp+=s[x+1+k];
		if(mp.count(sp))res=max(res,f(x+2+k));
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		mp.clear();
		fore(i,0,n){
			string sf; cin>>sf;
			fore(j,0,m-1){
				string sp;
				sp+=sf[j];
				sp+=sf[j+1];
				mp[sp]={i,j};
				if(j+2<m)sp+=sf[j+2];
				mp[sp]={i,j};
			}
		}
		cin>>s;
		fore(i,0,SZ(s)+1)dp[i]=-1;
		auto resp=f(0);
		if(!resp)cout<<"-1\n";
		else{
			ll x=0;
			vector<pair<ll,pair<ll,ll>>> res;
			while(x<m){
				string sp;
				sp+=s[x];
				sp+=s[x+1];
				if(f(x+2)){
					pair<ll,pair<ll,ll>> p;
					p.fst=mp[sp].fst;
					p.snd.fst=mp[sp].snd;
					p.snd.snd=p.snd.fst+1;
					res.pb(p);
					x+=2;
				}else{
					sp+=s[x+2];
					pair<ll,pair<ll,ll>> p;
					p.fst=mp[sp].fst;
					p.snd.fst=mp[sp].snd;
					p.snd.snd=p.snd.fst+2;
					res.pb(p);
					x+=3;
				}
			}
			cout<<SZ(res)<<"\n";
			for(auto i:res)cout<<i.snd.fst+1<<" "<<i.snd.snd+1<<" "<<i.fst+1<<"\n";
		}
	}
	
	return 0;
}