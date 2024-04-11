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

bool cmp(pair<ll,ll> a, pair<ll,ll> b){
	return abs(a.fst)<abs(b.fst);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n){
			char c; cin>>c;
			if(c=='L')a[i]=-a[i];
		}
		vector<pair<ll,ll>> v[2];
		fore(i,0,n){
			if(a[i]&1)v[1].pb({a[i],i});
			else v[0].pb({a[i],i});
		}
		fore(k,0,2)sort(ALL(v[k]),cmp);
		vector<ll> res(n);
		fore(i,0,n)res[i]=-1;
		fore(k,0,2){
			vector<pair<ll,ll>> s;
			for(auto i:v[k]){
				if(SZ(s)&&s.back().fst>0&&i.fst<0){
					ll tt=abs(i.fst+s.back().fst)/2;
					res[s.back().snd]=tt;
					res[i.snd]=tt;
					s.pop_back();
				}else{
					s.pb(i);
				}
			}
			while(SZ(s)>=2){
				if(s[SZ(s)-1].fst>0&&s[SZ(s)-2].fst>0){
					auto b=s.back();
					s.pop_back();
					auto bb=s.back();
					s.pop_back();
					ll tt=(abs(m-b.fst)+abs(m-bb.fst))/2;
					res[b.snd]=tt;
					res[bb.snd]=tt;
				}else break;
			}
			reverse(ALL(s));
			while(SZ(s)>=2){
				if(s[SZ(s)-1].fst<0&&s[SZ(s)-2].fst<0){
					auto b=s.back();
					s.pop_back();
					auto bb=s.back();
					s.pop_back();
					ll tt=(abs(b.fst)+abs(bb.fst))/2;
					res[b.snd]=tt;
					res[bb.snd]=tt;
				}else break;
			}
			reverse(ALL(s));
			if(SZ(s)>=2){
				ll mini=min(abs(m-s[1].fst),abs(s[0].fst));
				s[0].fst+=mini;
				s[1].fst+=mini;
				if(s[1].fst==m){
					s[1].fst=-m;
					ll tt=mini+(abs(s[0].fst)+abs(s[1].fst))/2;
					res[s[0].snd]=tt;
					res[s[1].snd]=tt;
				}else{
					ll tt=mini+(abs(m-s[0].fst)+abs(m-s[1].fst))/2;
					res[s[0].snd]=tt;
					res[s[1].snd]=tt;
				}
			}
		}
		fore(i,0,n)cout<<res[i]<<" ";
		cout<<"\n";
	}
	
	return 0;
}