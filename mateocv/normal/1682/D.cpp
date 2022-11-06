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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		ll st=-1;
		fore(i,0,n){
			if(s[i]=='1'){
				st=i; break;
			}
		}
		if(st==-1){
			cout<<"NO\n";
			continue;
		}
		string sm;
		fore(i,0,n)sm+=s[(st+i)%n];
		vector<pair<ll,ll>> res;
		vector<ll> v;
		fore(i,0,SZ(sm)){
			if(sm[i]=='0'){
				assert(SZ(v));
				res.pb({i,v.back()});
				v.pop_back();
				v.pb(i);
			}else v.pb(i);
		}
		if(SZ(v)&1){
			cout<<"NO\n";
			continue;
		}
		fore(i,1,SZ(v))res.pb({v[0],v[i]});
		cout<<"YES\n";
		for(auto i:res)cout<<(i.fst+st)%n+1<<" "<<(i.snd+st)%n+1<<"\n";
	}
	
	return 0;
}