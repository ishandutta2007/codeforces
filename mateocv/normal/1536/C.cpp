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

pair<ll,ll> comp(pair<ll,ll> p){
	ll g=__gcd(p.fst,p.snd);
	return {p.fst/g,p.snd/g};
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		vector<pair<pair<ll,ll>,ll>> v;
		pair<ll,ll> va={0,0};
		fore(i,0,n){
			if(s[i]=='D')va.fst++;
			else va.snd++;
			v.pb({comp(va),i});
		}
		vector<ll> res(n);
		sort(ALL(v));
		fore(i,0,n){
			if(i==0||v[i].fst!=v[i-1].fst){
				res[v[i].snd]=1;
			}else{
				res[v[i].snd]=res[v[i-1].snd]+1;
			}
		}
		fore(i,0,n)cout<<res[i]<<" ";
		cout<<"\n";
	}
	
	return 0;
}